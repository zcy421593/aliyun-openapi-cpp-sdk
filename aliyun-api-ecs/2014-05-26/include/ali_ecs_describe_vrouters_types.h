#ifndef ALI_ECS_DESCRIBE_VROUTERS_TYPESH
#define ALI_ECS_DESCRIBE_VROUTERS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct EcsDescribeVRoutersRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string vrouter_id;
  std::string page_number;
  std::string page_size;
  std::string owner_account;
};
struct EcsDescribeVRoutersVRouterType {
  std::vector<std::string> route_table_ids;
  std::string region_id;
  std::string vpc_id;
  std::string vrouter_name;
  std::string description;
  std::string vrouter_id;
  std::string creation_time;
};
struct EcsDescribeVRoutersResponseType {
  std::vector<EcsDescribeVRoutersVRouterType> vrouters;
  int total_count;
  int page_number;
  int page_size;
};
} // end namespace
#endif
