#ifndef ALI_SLB_SET_LISTENER_ACCESS_CONTROL_STATUS_TYPESH
#define ALI_SLB_SET_LISTENER_ACCESS_CONTROL_STATUS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct SlbSetListenerAccessControlStatusRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string load_balancer_id;
  std::string listener_port;
  std::string access_control_status;
  std::string owner_account;
};
struct SlbSetListenerAccessControlStatusResponseType {
};
} // end namespace
#endif
