#ifndef ALI_RDSREGION_ALLOCATE_INSTANCE_PUBLIC_CONNECTION_TYPESH
#define ALI_RDSREGION_ALLOCATE_INSTANCE_PUBLIC_CONNECTION_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct RdsRegionAllocateInstancePublicConnectionRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string db_instance_id;
  std::string connection_string_prefix;
  std::string port;
  std::string owner_account;
};
struct RdsRegionAllocateInstancePublicConnectionResponseType {
};
} // end namespace
#endif
