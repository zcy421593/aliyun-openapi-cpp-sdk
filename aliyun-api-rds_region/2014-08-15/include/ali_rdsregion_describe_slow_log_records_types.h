#ifndef ALI_RDSREGION_DESCRIBE_SLOW_LOG_RECORDS_TYPESH
#define ALI_RDSREGION_DESCRIBE_SLOW_LOG_RECORDS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct RdsRegionDescribeSlowLogRecordsRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string db_instance_id;
  std::string sq_lid;
  std::string start_time;
  std::string end_time;
  std::string db_name;
  std::string page_size;
  std::string page_number;
  std::string owner_account;
};
struct RdsRegionDescribeSlowLogRecordsSQLSlowRecordType {
  std::string host_address;
  std::string db_name;
  std::string sq_ltext;
  long query_times;
  long lock_times;
  long parse_row_counts;
  long return_row_counts;
  std::string execution_start_time;
};
struct RdsRegionDescribeSlowLogRecordsResponseType {
  std::vector<RdsRegionDescribeSlowLogRecordsSQLSlowRecordType> items;
  std::string engine;
  int total_record_count;
  int page_number;
  int page_record_count;
};
} // end namespace
#endif
