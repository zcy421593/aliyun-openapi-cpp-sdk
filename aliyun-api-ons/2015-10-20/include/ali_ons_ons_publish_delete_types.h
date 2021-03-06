#ifndef ALI_ONS_ONS_PUBLISH_DELETE_TYPESH
#define ALI_ONS_ONS_PUBLISH_DELETE_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct OnsOnsPublishDeleteRequestType {
  std::string ons_region_id;
  std::string ons_platform;
  std::string prevent_cache;
  std::string producer_id;
  std::string topic;
};
struct OnsOnsPublishDeleteResponseType {
  std::string help_url;
};
} // end namespace
#endif
