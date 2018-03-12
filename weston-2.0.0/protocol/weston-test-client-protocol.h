/* Generated by wayland-scanner 1.13.0 */

#ifndef WESTON_TEST_CLIENT_PROTOCOL_H
#define WESTON_TEST_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_weston_test The weston_test protocol
 * @section page_ifaces_weston_test Interfaces
 * - @subpage page_iface_weston_test - weston internal testing
 * - @subpage page_iface_weston_test_runner - weston internal testing
 * @section page_copyright_weston_test Copyright
 * <pre>
 *
 * Copyright © 2012 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct weston_test;
struct weston_test_runner;
struct wl_buffer;
struct wl_output;
struct wl_surface;

/**
 * @page page_iface_weston_test weston_test
 * @section page_iface_weston_test_desc Description
 *
 * Internal testing facilities for the weston compositor.
 *
 * It can't be stressed enough that these should never ever be used
 * outside of running weston's tests.  The weston-test.so module should
 * never be installed.
 *
 * These requests may allow clients to do very bad things.
 * @section page_iface_weston_test_api API
 * See @ref iface_weston_test.
 */
/**
 * @defgroup iface_weston_test The weston_test interface
 *
 * Internal testing facilities for the weston compositor.
 *
 * It can't be stressed enough that these should never ever be used
 * outside of running weston's tests.  The weston-test.so module should
 * never be installed.
 *
 * These requests may allow clients to do very bad things.
 */
extern const struct wl_interface weston_test_interface;
/**
 * @page page_iface_weston_test_runner weston_test_runner
 * @section page_iface_weston_test_runner_desc Description
 *
 * This is a global singleton interface for Weston internal tests.
 *
 * This interface allows a test client to trigger compositor-side
 * test procedures. This is useful for cases, where the actual tests
 * are in compositor plugins, but they also require the presence of
 * a particular client.
 *
 * This interface is implemented by the compositor plugins containing
 * the testing code.
 *
 * A test client starts a test with the "run" request. It must not send
 * another "run" request until receiving the "finished" event. If the
 * compositor-side test succeeds, the "finished" event is sent. If the
 * compositor-side test fails, the compositor should send the protocol
 * error "test_failed", but it may also exit with an error (e.g. SEGV).
 *
 * Unknown test name will raise "unknown_test" protocol error.
 * @section page_iface_weston_test_runner_api API
 * See @ref iface_weston_test_runner.
 */
/**
 * @defgroup iface_weston_test_runner The weston_test_runner interface
 *
 * This is a global singleton interface for Weston internal tests.
 *
 * This interface allows a test client to trigger compositor-side
 * test procedures. This is useful for cases, where the actual tests
 * are in compositor plugins, but they also require the presence of
 * a particular client.
 *
 * This interface is implemented by the compositor plugins containing
 * the testing code.
 *
 * A test client starts a test with the "run" request. It must not send
 * another "run" request until receiving the "finished" event. If the
 * compositor-side test succeeds, the "finished" event is sent. If the
 * compositor-side test fails, the compositor should send the protocol
 * error "test_failed", but it may also exit with an error (e.g. SEGV).
 *
 * Unknown test name will raise "unknown_test" protocol error.
 */
extern const struct wl_interface weston_test_runner_interface;

/**
 * @ingroup iface_weston_test
 * @struct weston_test_listener
 */
struct weston_test_listener {
	/**
	 */
	void (*pointer_position)(void *data,
				 struct weston_test *weston_test,
				 wl_fixed_t x,
				 wl_fixed_t y);
	/**
	 * screenshot capture is done
	 *
	 * The capture_screenshot_done signal is sent when a screenshot
	 * has been copied into the provided buffer.
	 */
	void (*capture_screenshot_done)(void *data,
					struct weston_test *weston_test);
};

/**
 * @ingroup iface_weston_test
 */
static inline int
weston_test_add_listener(struct weston_test *weston_test,
			 const struct weston_test_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) weston_test,
				     (void (**)(void)) listener, data);
}

#define WESTON_TEST_MOVE_SURFACE 0
#define WESTON_TEST_MOVE_POINTER 1
#define WESTON_TEST_SEND_BUTTON 2
#define WESTON_TEST_ACTIVATE_SURFACE 3
#define WESTON_TEST_SEND_KEY 4
#define WESTON_TEST_DEVICE_RELEASE 5
#define WESTON_TEST_DEVICE_ADD 6
#define WESTON_TEST_CAPTURE_SCREENSHOT 7

/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_POINTER_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_CAPTURE_SCREENSHOT_DONE_SINCE_VERSION 1

/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_MOVE_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_MOVE_POINTER_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_SEND_BUTTON_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_ACTIVATE_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_SEND_KEY_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_DEVICE_RELEASE_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_DEVICE_ADD_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test
 */
#define WESTON_TEST_CAPTURE_SCREENSHOT_SINCE_VERSION 1

/** @ingroup iface_weston_test */
static inline void
weston_test_set_user_data(struct weston_test *weston_test, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) weston_test, user_data);
}

/** @ingroup iface_weston_test */
static inline void *
weston_test_get_user_data(struct weston_test *weston_test)
{
	return wl_proxy_get_user_data((struct wl_proxy *) weston_test);
}

static inline uint32_t
weston_test_get_version(struct weston_test *weston_test)
{
	return wl_proxy_get_version((struct wl_proxy *) weston_test);
}

/** @ingroup iface_weston_test */
static inline void
weston_test_destroy(struct weston_test *weston_test)
{
	wl_proxy_destroy((struct wl_proxy *) weston_test);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_move_surface(struct weston_test *weston_test, struct wl_surface *surface, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_MOVE_SURFACE, surface, x, y);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_move_pointer(struct weston_test *weston_test, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_MOVE_POINTER, x, y);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_send_button(struct weston_test *weston_test, int32_t button, uint32_t state)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_SEND_BUTTON, button, state);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_activate_surface(struct weston_test *weston_test, struct wl_surface *surface)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_ACTIVATE_SURFACE, surface);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_send_key(struct weston_test *weston_test, uint32_t key, uint32_t state)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_SEND_KEY, key, state);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_device_release(struct weston_test *weston_test, const char *device)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_DEVICE_RELEASE, device);
}

/**
 * @ingroup iface_weston_test
 */
static inline void
weston_test_device_add(struct weston_test *weston_test, const char *device)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_DEVICE_ADD, device);
}

/**
 * @ingroup iface_weston_test
 *
 * Records an image of what is currently displayed on a given
 * display output, returning the image as an event.
 */
static inline void
weston_test_capture_screenshot(struct weston_test *weston_test, struct wl_output *output, struct wl_buffer *buffer)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test,
			 WESTON_TEST_CAPTURE_SCREENSHOT, output, buffer);
}

#ifndef WESTON_TEST_RUNNER_ERROR_ENUM
#define WESTON_TEST_RUNNER_ERROR_ENUM
enum weston_test_runner_error {
	/**
	 * compositor test failed
	 */
	WESTON_TEST_RUNNER_ERROR_TEST_FAILED = 0,
	/**
	 * unrecognized test name
	 */
	WESTON_TEST_RUNNER_ERROR_UNKNOWN_TEST = 1,
};
#endif /* WESTON_TEST_RUNNER_ERROR_ENUM */

/**
 * @ingroup iface_weston_test_runner
 * @struct weston_test_runner_listener
 */
struct weston_test_runner_listener {
	/**
	 */
	void (*finished)(void *data,
			 struct weston_test_runner *weston_test_runner);
};

/**
 * @ingroup iface_weston_test_runner
 */
static inline int
weston_test_runner_add_listener(struct weston_test_runner *weston_test_runner,
				const struct weston_test_runner_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) weston_test_runner,
				     (void (**)(void)) listener, data);
}

#define WESTON_TEST_RUNNER_DESTROY 0
#define WESTON_TEST_RUNNER_RUN 1

/**
 * @ingroup iface_weston_test_runner
 */
#define WESTON_TEST_RUNNER_FINISHED_SINCE_VERSION 1

/**
 * @ingroup iface_weston_test_runner
 */
#define WESTON_TEST_RUNNER_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_weston_test_runner
 */
#define WESTON_TEST_RUNNER_RUN_SINCE_VERSION 1

/** @ingroup iface_weston_test_runner */
static inline void
weston_test_runner_set_user_data(struct weston_test_runner *weston_test_runner, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) weston_test_runner, user_data);
}

/** @ingroup iface_weston_test_runner */
static inline void *
weston_test_runner_get_user_data(struct weston_test_runner *weston_test_runner)
{
	return wl_proxy_get_user_data((struct wl_proxy *) weston_test_runner);
}

static inline uint32_t
weston_test_runner_get_version(struct weston_test_runner *weston_test_runner)
{
	return wl_proxy_get_version((struct wl_proxy *) weston_test_runner);
}

/**
 * @ingroup iface_weston_test_runner
 */
static inline void
weston_test_runner_destroy(struct weston_test_runner *weston_test_runner)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test_runner,
			 WESTON_TEST_RUNNER_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) weston_test_runner);
}

/**
 * @ingroup iface_weston_test_runner
 */
static inline void
weston_test_runner_run(struct weston_test_runner *weston_test_runner, const char *test_name)
{
	wl_proxy_marshal((struct wl_proxy *) weston_test_runner,
			 WESTON_TEST_RUNNER_RUN, test_name);
}

#ifdef  __cplusplus
}
#endif

#endif