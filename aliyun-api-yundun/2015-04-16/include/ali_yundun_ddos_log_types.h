#ifndef ALI_YUNDUN_DDOS_LOG_TYPESH
#define ALI_YUNDUN_DDOS_LOG_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct YundunDdosLogRequestType {
  std::string jst_owner_id;
  std::string page_number;
  std::string page_size;
  std::string instance_id;
  std::string instance_type;
};
struct YundunDdosLogDdosLogType {
  std::string start_time;
  std::string end_time;
  std::string reason;
  int status;
  long bps;
  long pps;
  long qps;
  std::string attack_type;
  std::string attack_ip_list;
  int type;
};
struct YundunDdosLogResponseType {
  std::vector<YundunDdosLogDdosLogType> log_list;
  int attack_status;
  std::string start_time;
  std::string end_time;
  int page_number;
  int page_size;
  int total_count;
};
} // end namespace
#endif
