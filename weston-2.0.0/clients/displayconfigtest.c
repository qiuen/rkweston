#include "displayconfig.h"


int main(int argc, char *argv[]) {

  HdmiInfos_t hdmi_infos;
  memset((void*)&hdmi_infos, 0, sizeof(HdmiInfos_t));

  init_display_config();

  get_display_hdmi_info(&hdmi_infos);

  printf("++++++hdmi_infos count=%d\n",hdmi_infos.count);


  return 0;
}




