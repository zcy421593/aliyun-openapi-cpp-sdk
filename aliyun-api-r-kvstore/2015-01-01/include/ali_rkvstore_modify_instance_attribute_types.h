#ifndef ALI_RKVSTORE_MODIFY_INSTANCE_ATTRIBUTE_TYPESH
#define ALI_RKVSTORE_MODIFY_INSTANCE_ATTRIBUTE_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct RkvstoreModifyInstanceAttributeRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string owner_account;
  std::string instance_id;
  std::string instance_name;
  std::string new_password;
};
struct RkvstoreModifyInstanceAttributeResponseType {
};
} // end namespace
#endif
