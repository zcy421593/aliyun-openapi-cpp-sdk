#ifndef ALI_OCSH
#define ALI_OCSH
#include <string>
#include <string.h>
#include <stdlib.h>
#include "ali_ocs_activate_instance_types.h"
#include "ali_ocs_add_authentic_ip_types.h"
#include "ali_ocs_create_instance_types.h"
#include "ali_ocs_data_operate_types.h"
#include "ali_ocs_deactivate_instance_types.h"
#include "ali_ocs_delete_instance_types.h"
#include "ali_ocs_describe_authentic_ip_types.h"
#include "ali_ocs_describe_history_monitor_values_types.h"
#include "ali_ocs_describe_instances_types.h"
#include "ali_ocs_describe_monitor_items_types.h"
#include "ali_ocs_describe_monitor_values_types.h"
#include "ali_ocs_describe_regions_types.h"
#include "ali_ocs_describe_security_ips_types.h"
#include "ali_ocs_describe_zones_types.h"
#include "ali_ocs_flush_instance_types.h"
#include "ali_ocs_modify_instance_attribute_types.h"
#include "ali_ocs_modify_instance_capacity_types.h"
#include "ali_ocs_modify_security_ips_types.h"
#include "ali_ocs_remove_authentic_ip_types.h"
#include "ali_ocs_replace_authentic_ip_types.h"
#include "ali_ocs_verify_password_types.h"
#ifdef WIN32
 #ifdef aliyun_api_ocs_2015_03_01_EXPORTS
 #define ALIYUN_API_OCS_2015_03_01_DLL_EXPORT_IMPORT __declspec(dllexport)
 #else
 #define ALIYUN_API_OCS_2015_03_01_DLL_EXPORT_IMPORT 
 #endif
#else
#define ALIYUN_API_OCS_2015_03_01_DLL_EXPORT_IMPORT
#endif
namespace aliyun {
struct OcsErrorInfo {
  std::string request_id;
  std::string code;
  std::string message;
  std::string host_id;
};
class ALIYUN_API_OCS_2015_03_01_DLL_EXPORT_IMPORT Ocs {
public:
  static Ocs* CreateOcsClient(std::string endpoint, std::string appid, std::string secret);
  ~Ocs();
private:
  Ocs(std::string host, std::string appid, std::string secret);
public:
  void SetUseTls(bool use_tls = true) {  if(support_tls_) use_tls_ = use_tls;  }
  bool GetUseTls() {  return use_tls_;  }
  bool GetSupportTls() {  return support_tls_;  }
  void SetProxyHost(std::string proxy_host) {
    if(this->proxy_host_) {
      free(this->proxy_host_);
    }
    this->proxy_host_ = strdup(proxy_host.c_str());
  }
  std::string GetProxyHost() {  return this->proxy_host_;  }
  void SetRegionId(std::string region_id) {
    if(this->region_id_) {
      free(this->region_id_);
    }
    this->region_id_ = strdup(region_id.c_str());
  }
  std::string GetRegionId() {  return this->region_id_;  }
  int ActivateInstance(const OcsActivateInstanceRequestType& req,
          OcsActivateInstanceResponseType* resp,
          OcsErrorInfo* error_info);

  int AddAuthenticIP(const OcsAddAuthenticIPRequestType& req,
          OcsAddAuthenticIPResponseType* resp,
          OcsErrorInfo* error_info);

  int CreateInstance(const OcsCreateInstanceRequestType& req,
          OcsCreateInstanceResponseType* resp,
          OcsErrorInfo* error_info);

  int DataOperate(const OcsDataOperateRequestType& req,
          OcsDataOperateResponseType* resp,
          OcsErrorInfo* error_info);

  int DeactivateInstance(const OcsDeactivateInstanceRequestType& req,
          OcsDeactivateInstanceResponseType* resp,
          OcsErrorInfo* error_info);

  int DeleteInstance(const OcsDeleteInstanceRequestType& req,
          OcsDeleteInstanceResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeAuthenticIP(const OcsDescribeAuthenticIPRequestType& req,
          OcsDescribeAuthenticIPResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeHistoryMonitorValues(const OcsDescribeHistoryMonitorValuesRequestType& req,
          OcsDescribeHistoryMonitorValuesResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeInstances(const OcsDescribeInstancesRequestType& req,
          OcsDescribeInstancesResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeMonitorItems(const OcsDescribeMonitorItemsRequestType& req,
          OcsDescribeMonitorItemsResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeMonitorValues(const OcsDescribeMonitorValuesRequestType& req,
          OcsDescribeMonitorValuesResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeRegions(const OcsDescribeRegionsRequestType& req,
          OcsDescribeRegionsResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeSecurityIps(const OcsDescribeSecurityIpsRequestType& req,
          OcsDescribeSecurityIpsResponseType* resp,
          OcsErrorInfo* error_info);

  int DescribeZones(const OcsDescribeZonesRequestType& req,
          OcsDescribeZonesResponseType* resp,
          OcsErrorInfo* error_info);

  int FlushInstance(const OcsFlushInstanceRequestType& req,
          OcsFlushInstanceResponseType* resp,
          OcsErrorInfo* error_info);

  int ModifyInstanceAttribute(const OcsModifyInstanceAttributeRequestType& req,
          OcsModifyInstanceAttributeResponseType* resp,
          OcsErrorInfo* error_info);

  int ModifyInstanceCapacity(const OcsModifyInstanceCapacityRequestType& req,
          OcsModifyInstanceCapacityResponseType* resp,
          OcsErrorInfo* error_info);

  int ModifySecurityIps(const OcsModifySecurityIpsRequestType& req,
          OcsModifySecurityIpsResponseType* resp,
          OcsErrorInfo* error_info);

  int RemoveAuthenticIP(const OcsRemoveAuthenticIPRequestType& req,
          OcsRemoveAuthenticIPResponseType* resp,
          OcsErrorInfo* error_info);

  int ReplaceAuthenticIP(const OcsReplaceAuthenticIPRequestType& req,
          OcsReplaceAuthenticIPResponseType* resp,
          OcsErrorInfo* error_info);

  int VerifyPassword(const OcsVerifyPasswordRequestType& req,
          OcsVerifyPasswordResponseType* resp,
          OcsErrorInfo* error_info);

private:
  char* appid_;
  char* secret_;
  char* version_;
  char* host_;
  char* proxy_host_;
  bool support_tls_;
  bool use_tls_;
  char* region_id_;
};  //end class
} // end namespace
#endif
