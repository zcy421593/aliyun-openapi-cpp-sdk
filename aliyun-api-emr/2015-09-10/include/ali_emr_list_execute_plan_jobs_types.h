#ifndef ALI_EMR_LIST_EXECUTE_PLAN_JOBS_TYPESH
#define ALI_EMR_LIST_EXECUTE_PLAN_JOBS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct EmrListExecutePlanJobsRequestType {
  std::string execute_plan_execute_node_id;
  std::string execute_plan_exec_record_id;
  std::string is_desc;
  std::string page_number;
  std::string page_size;
};
struct EmrListExecutePlanJobsExecutePlanJobInfoType {
  std::string id;
  std::string is_master;
  std::string last_run_status;
  std::string run_time;
  std::string cluster_name;
  std::string status;
};
struct EmrListExecutePlanJobsResponseType {
  std::vector<EmrListExecutePlanJobsExecutePlanJobInfoType> execute_plan_jobs;
  int total_count;
  int page_number;
  int page_size;
};
} // end namespace
#endif
