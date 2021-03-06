#ifndef ALI_ONS_ONS_CLUSTER_NAMES_TYPESH
#define ALI_ONS_ONS_CLUSTER_NAMES_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct OnsOnsClusterNamesRequestType {
  std::string ons_region_id;
  std::string ons_platform;
  std::string prevent_cache;
};
struct OnsOnsClusterNamesResponseType {
  std::vector<std::string> data;
  std::string help_url;
};
} // end namespace
#endif
