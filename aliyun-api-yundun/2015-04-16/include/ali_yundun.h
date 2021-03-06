#ifndef ALI_YUNDUNH
#define ALI_YUNDUNH
#include <string>
#include <string.h>
#include <stdlib.h>
#include "ali_yundun_add_cname_waf_types.h"
#include "ali_yundun_bruteforce_log_types.h"
#include "ali_yundun_close_cc_protect_types.h"
#include "ali_yundun_close_port_scan_types.h"
#include "ali_yundun_close_vul_scan_types.h"
#include "ali_yundun_config_ddos_types.h"
#include "ali_yundun_confirm_login_types.h"
#include "ali_yundun_ddos_flow_graph_types.h"
#include "ali_yundun_ddos_log_types.h"
#include "ali_yundun_delete_back_door_file_types.h"
#include "ali_yundun_delete_cname_waf_types.h"
#include "ali_yundun_detect_vul_by_id_types.h"
#include "ali_yundun_detect_vul_by_ip_types.h"
#include "ali_yundun_get_ddos_config_options_types.h"
#include "ali_yundun_list_instance_infos_types.h"
#include "ali_yundun_loginevent_log_types.h"
#include "ali_yundun_open_cc_protect_types.h"
#include "ali_yundun_open_port_scan_types.h"
#include "ali_yundun_open_vul_scan_types.h"
#include "ali_yundun_query_ddos_config_types.h"
#include "ali_yundun_secure_check_types.h"
#include "ali_yundun_service_status_types.h"
#include "ali_yundun_set_ddos_auto_types.h"
#include "ali_yundun_set_ddos_qps_types.h"
#include "ali_yundun_summary_types.h"
#include "ali_yundun_vul_scan_log_types.h"
#include "ali_yundun_waf_info_types.h"
#include "ali_yundun_waf_log_types.h"
#include "ali_yundun_webshell_log_types.h"
#ifdef WIN32
 #ifdef aliyun_api_yundun_2015_04_16_EXPORTS
 #define ALIYUN_API_YUNDUN_2015_04_16_DLL_EXPORT_IMPORT __declspec(dllexport)
 #else
 #define ALIYUN_API_YUNDUN_2015_04_16_DLL_EXPORT_IMPORT 
 #endif
#else
#define ALIYUN_API_YUNDUN_2015_04_16_DLL_EXPORT_IMPORT
#endif
namespace aliyun {
struct YundunErrorInfo {
  std::string request_id;
  std::string code;
  std::string message;
  std::string host_id;
};
class ALIYUN_API_YUNDUN_2015_04_16_DLL_EXPORT_IMPORT Yundun {
public:
  static Yundun* CreateYundunClient(std::string endpoint, std::string appid, std::string secret);
  ~Yundun();
private:
  Yundun(std::string host, std::string appid, std::string secret);
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
  int AddCNameWaf(const YundunAddCNameWafRequestType& req,
          YundunAddCNameWafResponseType* resp,
          YundunErrorInfo* error_info);

  int BruteforceLog(const YundunBruteforceLogRequestType& req,
          YundunBruteforceLogResponseType* resp,
          YundunErrorInfo* error_info);

  int CloseCCProtect(const YundunCloseCCProtectRequestType& req,
          YundunCloseCCProtectResponseType* resp,
          YundunErrorInfo* error_info);

  int ClosePortScan(const YundunClosePortScanRequestType& req,
          YundunClosePortScanResponseType* resp,
          YundunErrorInfo* error_info);

  int CloseVulScan(const YundunCloseVulScanRequestType& req,
          YundunCloseVulScanResponseType* resp,
          YundunErrorInfo* error_info);

  int ConfigDdos(const YundunConfigDdosRequestType& req,
          YundunConfigDdosResponseType* resp,
          YundunErrorInfo* error_info);

  int ConfirmLogin(const YundunConfirmLoginRequestType& req,
          YundunConfirmLoginResponseType* resp,
          YundunErrorInfo* error_info);

  int DdosFlowGraph(const YundunDdosFlowGraphRequestType& req,
          YundunDdosFlowGraphResponseType* resp,
          YundunErrorInfo* error_info);

  int DdosLog(const YundunDdosLogRequestType& req,
          YundunDdosLogResponseType* resp,
          YundunErrorInfo* error_info);

  int DeleteBackDoorFile(const YundunDeleteBackDoorFileRequestType& req,
          YundunDeleteBackDoorFileResponseType* resp,
          YundunErrorInfo* error_info);

  int DeleteCNameWaf(const YundunDeleteCNameWafRequestType& req,
          YundunDeleteCNameWafResponseType* resp,
          YundunErrorInfo* error_info);

  int DetectVulById(const YundunDetectVulByIdRequestType& req,
          YundunDetectVulByIdResponseType* resp,
          YundunErrorInfo* error_info);

  int DetectVulByIp(const YundunDetectVulByIpRequestType& req,
          YundunDetectVulByIpResponseType* resp,
          YundunErrorInfo* error_info);

  int GetDdosConfigOptions(YundunGetDdosConfigOptionsResponseType* resp,
          YundunErrorInfo* error_info);

  int ListInstanceInfos(const YundunListInstanceInfosRequestType& req,
          YundunListInstanceInfosResponseType* resp,
          YundunErrorInfo* error_info);

  int LogineventLog(const YundunLogineventLogRequestType& req,
          YundunLogineventLogResponseType* resp,
          YundunErrorInfo* error_info);

  int OpenCCProtect(const YundunOpenCCProtectRequestType& req,
          YundunOpenCCProtectResponseType* resp,
          YundunErrorInfo* error_info);

  int OpenPortScan(const YundunOpenPortScanRequestType& req,
          YundunOpenPortScanResponseType* resp,
          YundunErrorInfo* error_info);

  int OpenVulScan(const YundunOpenVulScanRequestType& req,
          YundunOpenVulScanResponseType* resp,
          YundunErrorInfo* error_info);

  int QueryDdosConfig(const YundunQueryDdosConfigRequestType& req,
          YundunQueryDdosConfigResponseType* resp,
          YundunErrorInfo* error_info);

  int SecureCheck(const YundunSecureCheckRequestType& req,
          YundunSecureCheckResponseType* resp,
          YundunErrorInfo* error_info);

  int ServiceStatus(const YundunServiceStatusRequestType& req,
          YundunServiceStatusResponseType* resp,
          YundunErrorInfo* error_info);

  int SetDdosAuto(const YundunSetDdosAutoRequestType& req,
          YundunSetDdosAutoResponseType* resp,
          YundunErrorInfo* error_info);

  int SetDdosQps(const YundunSetDdosQpsRequestType& req,
          YundunSetDdosQpsResponseType* resp,
          YundunErrorInfo* error_info);

  int Summary(const YundunSummaryRequestType& req,
          YundunSummaryResponseType* resp,
          YundunErrorInfo* error_info);

  int VulScanLog(const YundunVulScanLogRequestType& req,
          YundunVulScanLogResponseType* resp,
          YundunErrorInfo* error_info);

  int WafInfo(const YundunWafInfoRequestType& req,
          YundunWafInfoResponseType* resp,
          YundunErrorInfo* error_info);

  int WafLog(const YundunWafLogRequestType& req,
          YundunWafLogResponseType* resp,
          YundunErrorInfo* error_info);

  int WebshellLog(const YundunWebshellLogRequestType& req,
          YundunWebshellLogResponseType* resp,
          YundunErrorInfo* error_info);

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
