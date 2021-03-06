#ifndef ALI_ALERT_LIST_LEVEL_CHANNEL_TYPESH
#define ALI_ALERT_LIST_LEVEL_CHANNEL_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct AlertListLevelChannelRequestType {
  std::string project_name;
  std::string level;
  std::string page;
  std::string page_size;
};
struct AlertListLevelChannelResponseType {
  std::string code;
  std::string message;
  std::string success;
  std::string trace_id;
  std::string datapoints;
  std::string total;
};
} // end namespace
#endif
