#ifndef ALI_OSSADMIN_GET_BUCKET_VIPS_TYPESH
#define ALI_OSSADMIN_GET_BUCKET_VIPS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct OssAdminGetBucketVipsRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string owner_account;
  std::string bucket_name;
};
struct OssAdminGetBucketVipsResponseType {
  std::vector<std::string> vip_list;
  std::string request_id;
};
} // end namespace
#endif
