#ifndef ALI_ALERT_LIST_ALERT_TYPESH
#define ALI_ALERT_LIST_ALERT_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct AlertListAlertRequestType {
  std::string project_name;
  std::string alert_name;
  std::string page;
  std::string page_size;
};
struct AlertListAlertResponseType {
  std::string code;
  std::string message;
  std::string success;
  std::string trace_id;
  std::string datapoints;
  std::string total;
};
} // end namespace
#endif
