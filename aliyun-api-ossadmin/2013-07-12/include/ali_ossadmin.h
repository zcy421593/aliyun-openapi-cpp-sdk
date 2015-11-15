#ifndef ALI_OSS_ADMINH
#define ALI_OSS_ADMINH
#include <string>
#include "ali_ossadmin_create_oss_instance_types.h"
#include "ali_ossadmin_get_bucket_policy_types.h"
#include "ali_ossadmin_put_bucket_limit_types.h"
#include "ali_ossadmin_put_bucket_policy_types.h"
#include "ali_ossadmin_put_bucket_status_types.h"
namespace aliyun {
struct OssAdminErrorInfo {
  std::string request_id;
  std::string code;
  std::string message;
  std::string host_id;
};
class OssAdmin {
public:
  static OssAdmin* CreateOssAdminClient(std::string endpoint, std::string appid, std::string secret);
private:
  OssAdmin(std::string host, std::string appid, std::string secret) : 
  appid_(appid),
  secret_(secret),
  version_("2013-07-12"),
  use_tls_(true),
  support_tls_(true),
  host_(host) {}
public:
  void SetUseTls(bool use_tls = true) {  if(support_tls_) use_tls_ = use_tls;  }
  bool GetUseTls() {  return use_tls_;  }
  bool GetSupportTls() {  return support_tls_;  }
  void SetRegionId(std::string region_id) {  this->region_id_ = region_id; }
  std::string GetRegionId() {  return this->region_id_;  }
  int createOssInstance(const OssAdmincreateOssInstanceRequestType& req,
          OssAdmincreateOssInstanceResponseType* resp,
          OssAdminErrorInfo* error_info);

  int GetBucketPolicy(const OssAdminGetBucketPolicyRequestType& req,
          OssAdminGetBucketPolicyResponseType* resp,
          OssAdminErrorInfo* error_info);

  int PutBucketLimit(const OssAdminPutBucketLimitRequestType& req,
          OssAdminPutBucketLimitResponseType* resp,
          OssAdminErrorInfo* error_info);

  int PutBucketPolicy(const OssAdminPutBucketPolicyRequestType& req,
          OssAdminPutBucketPolicyResponseType* resp,
          OssAdminErrorInfo* error_info);

  int PutBucketStatus(const OssAdminPutBucketStatusRequestType& req,
          OssAdminPutBucketStatusResponseType* resp,
          OssAdminErrorInfo* error_info);

private:
  const std::string appid_;
  const std::string secret_;
  const std::string version_;
  const std::string host_;
  const bool support_tls_;
  bool use_tls_;
  std::string region_id_;
};  //end class
} // end namespace
#endif
