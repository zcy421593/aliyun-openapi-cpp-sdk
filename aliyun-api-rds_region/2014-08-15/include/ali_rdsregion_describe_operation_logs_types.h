#ifndef ALI_RDSREGION_DESCRIBE_OPERATION_LOGS_TYPESH
#define ALI_RDSREGION_DESCRIBE_OPERATION_LOGS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct RdsRegionDescribeOperationLogsRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string db_instance_id;
  std::string search_key;
  std::string db_instance_use_type;
  std::string start_time;
  std::string end_time;
  std::string page_size;
  std::string page_number;
  std::string owner_account;
};
struct RdsRegionDescribeOperationLogsOperationlogType {
  std::string db_instance_description;
  std::string db_instance_id;
  std::string operation_source;
  std::string operation_item;
  std::string execution_time;
};
struct RdsRegionDescribeOperationLogsResponseType {
  std::vector<RdsRegionDescribeOperationLogsOperationlogType> items;
  std::string engine;
  int total_record_count;
  int page_number;
  int page_record_count;
};
} // end namespace
#endif
