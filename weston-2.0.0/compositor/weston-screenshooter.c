/*
 * Copyright © 2008-2011 Kristian Høgsberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "config.h"

#include <stdint.h>
#include <linux/input.h>

#include "compositor.h"
#include "weston.h"
#include "weston-screenshooter-server-protocol.h"
#include "shared/helpers.h"

struct screenshooter {
	struct weston_compositor *ec;
	struct wl_global *global;
	struct wl_client *client;
	struct weston_process process;
	struct wl_listener destroy_listener;
	struct weston_recorder *recorder;
};

struct displayconfig {
	struct weston_compositor *ec;
	struct wl_global *global;
	struct wl_client *client;
	struct weston_process process;
	struct wl_listener destroy_listener;
};

static void
screenshooter_done(void *data, enum weston_screenshooter_outcome outcome)
{
	struct wl_resource *resource = data;

	switch (outcome) {
	case WESTON_SCREENSHOOTER_SUCCESS:
		weston_screenshooter_send_done(resource);
		break;
	case WESTON_SCREENSHOOTER_NO_MEMORY:
		wl_resource_post_no_memory(resource);
		break;
	default:
		break;
	}
}

static void 
displayconfig_done(void *data, enum weston_display_coinfig_error err) 
{
		weston_log("====================%s.\n",__FUNCTION__);
	struct wl_resource *resource = data;
	switch (err) {
		case WESTON_DISPLAY_COINFIG_ERROR_OK:
		     weston_display_coinfig_send_finished(resource);
		     break;
		case WESTON_DISPLAY_COINFIG_ERROR_FAIL:
		     weston_display_coinfig_send_finished(resource);
	         break;
	}
	
}

static void 
displayconfig_GetResource(struct wl_client *client,
			    struct wl_resource *resource,
			    const char *modes) 
{
	weston_log("====================%s---%s,%d\n",__FUNCTION__,modes,strlen(modes));
	struct weston_output *output =
	wl_resource_get_user_data(resource);
	weston_displayconfig_getresource(output, modes);   
}

static void
displayconfig_GetResource2 (struct wl_client *client,
			     struct wl_resource *resource,
			     struct wl_resource *output,
			     struct wl_resource *modes) {

				 
   	struct weston_output *output2 =
		wl_resource_get_user_data(output);
	struct weston_buffer *buffer =
		weston_buffer_from_resource(modes);

	if (buffer == NULL) {
		wl_resource_post_no_memory(resource);
		return;
	}
	weston_log("==================%s\n",__FUNCTION__);
	weston_displayconfig_getresource2(output2, buffer, displayconfig_done, resource);
  

}

static void
displayconfig_SetMode(struct wl_client *client,
			struct wl_resource *resource,
			struct wl_resource *output,
			int32_t width,
			int32_t height,
			int32_t refresh,
			int32_t flag,
			int32_t reserved) {

    weston_log("+++++++++width=%d,height=%d,refresh=%d,flag=%d\n",width,height,refresh,flag);
    struct weston_output *output2 = wl_resource_get_user_data(output);
	
	weston_displayconfig_setmode(output2, width, height, refresh, flag, reserved,displayconfig_done,resource);
}


static void
screenshooter_shoot(struct wl_client *client,
		    struct wl_resource *resource,
		    struct wl_resource *output_resource,
		    struct wl_resource *buffer_resource)
{
	struct weston_output *output =
		wl_resource_get_user_data(output_resource);
	struct weston_buffer *buffer =
		weston_buffer_from_resource(buffer_resource);

	if (buffer == NULL) {
		wl_resource_post_no_memory(resource);
		return;
	}
    weston_log("====================screenshooter_shoot.\n");
	weston_screenshooter_shoot(output, buffer, screenshooter_done, resource);
}

struct weston_screenshooter_interface screenshooter_implementation = {
	screenshooter_shoot
};

struct weston_display_coinfig_interface displayconfig_implementation = {
	displayconfig_GetResource,
	displayconfig_GetResource2,
	displayconfig_SetMode
};


static void
bind_shooter(struct wl_client *client,
	     void *data, uint32_t version, uint32_t id)
{
	struct screenshooter *shooter = data;
	struct wl_resource *resource;

	resource = wl_resource_create(client,
				      &weston_screenshooter_interface, 1, id);
      /*
	if (client != shooter->client) {
		wl_resource_post_error(resource, WL_DISPLAY_ERROR_INVALID_OBJECT,
				       "screenshooter failed: permission denied");
		return;
	}*/

	weston_log("====================%s.\n",__FUNCTION__);

	wl_resource_set_implementation(resource, &screenshooter_implementation,
				       data, NULL);
}

static void
bind_displayconfig (struct wl_client *client,
	     void *data, uint32_t version, uint32_t id) {
	struct displayconfig *config = data;
	struct wl_resource *resource;
    	weston_log("====================%s.\n",__FUNCTION__);
	resource = wl_resource_create(client,&weston_display_coinfig_interface, 1, id);		 
			 
	wl_resource_set_implementation(resource, &displayconfig_implementation,
				       data, NULL);
}

static void
screenshooter_sigchld(struct weston_process *process, int status)
{
	struct screenshooter *shooter =
		container_of(process, struct screenshooter, process);

	shooter->client = NULL;
}

static void
screenshooter_binding(struct weston_keyboard *keyboard, uint32_t time,
		      uint32_t key, void *data)
{
	struct screenshooter *shooter = data;
	char *screenshooter_exe;
	int ret;
      weston_log("====================%s.\n",__FUNCTION__);
	ret = asprintf(&screenshooter_exe, "%s/%s",
		       weston_config_get_libexec_dir(),
		       "/weston-screenshooter");
	if (ret < 0) {
		weston_log("Could not construct screenshooter path.\n");
		return;
	}

	if (!shooter->client)
		shooter->client = weston_client_launch(shooter->ec,
					&shooter->process,
					screenshooter_exe, screenshooter_sigchld);
	free(screenshooter_exe);
}

static void
recorder_binding(struct weston_keyboard *keyboard, uint32_t time,
		 uint32_t key, void *data)
{
	struct weston_compositor *ec = keyboard->seat->compositor;
	struct weston_output *output;
	struct screenshooter *shooter = data;
	struct weston_recorder *recorder = shooter->recorder;;
	static const char filename[] = "capture.wcap";

	if (recorder) {
		weston_recorder_stop(recorder);
		shooter->recorder = NULL;
	} else {
		if (keyboard->focus && keyboard->focus->output)
			output = keyboard->focus->output;
		else
			output = container_of(ec->output_list.next,
					      struct weston_output, link);

		shooter->recorder = weston_recorder_start(output, filename);
	}
}

static void
screenshooter_destroy(struct wl_listener *listener, void *data)
{
	struct screenshooter *shooter =
		container_of(listener, struct screenshooter, destroy_listener);

	wl_global_destroy(shooter->global);
	free(shooter);
}


static void
displayconfig_destroy(struct wl_listener *listener, void *data)
{
	struct displayconfig *config =
		container_of(listener, struct displayconfig, destroy_listener);

	wl_global_destroy(config->global);
	free(config);
}

WL_EXPORT void
screenshooter_create(struct weston_compositor *ec)
{
	struct screenshooter *shooter;
    struct displayconfig *config;
	shooter = zalloc(sizeof *shooter);
	config  = zalloc(sizeof *config);
	if (shooter == NULL)
		return;
	if (config == NULL) 
		return;

	shooter->ec = ec;
	config->ec = ec;

	shooter->global = wl_global_create(ec->wl_display,
					   &weston_screenshooter_interface, 1,
					   shooter, bind_shooter);
	config->global = wl_global_create(ec->wl_display,
					   &weston_display_coinfig_interface, 1,
					   config, bind_displayconfig);
	weston_compositor_add_key_binding(ec, KEY_S, MODIFIER_SUPER,
					  screenshooter_binding, shooter);
	weston_compositor_add_key_binding(ec, KEY_R, MODIFIER_SUPER,
					  recorder_binding, shooter);
    
	config->destroy_listener.notify = displayconfig_destroy;
	shooter->destroy_listener.notify = screenshooter_destroy;
	wl_signal_add(&ec->destroy_signal, &shooter->destroy_listener);
	wl_signal_add(&ec->destroy_signal, &config->destroy_listener);
}
