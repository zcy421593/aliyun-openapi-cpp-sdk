#ifndef ALI_ECS_REVOKE_SECURITY_GROUP_EGRESS_TYPESH
#define ALI_ECS_REVOKE_SECURITY_GROUP_EGRESS_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct EcsRevokeSecurityGroupEgressRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string security_group_id;
  std::string ip_protocol;
  std::string port_range;
  std::string dest_group_id;
  std::string dest_group_owner_account;
  std::string dest_cidr_ip;
  std::string policy;
  std::string nic_type;
  std::string owner_account;
};
struct EcsRevokeSecurityGroupEgressResponseType {
};
} // end namespace
#endif
