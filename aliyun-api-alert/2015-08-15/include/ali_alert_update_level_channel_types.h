#ifndef ALI_ALERT_UPDATE_LEVEL_CHANNEL_TYPESH
#define ALI_ALERT_UPDATE_LEVEL_CHANNEL_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct AlertUpdateLevelChannelRequestType {
  std::string project_name;
  std::string level;
  std::string level_channel_setting;
};
struct AlertUpdateLevelChannelResponseType {
  std::string code;
  std::string message;
  std::string success;
  std::string trace_id;
};
} // end namespace
#endif
