#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_slb.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, SlbSetLoadBalancerHTTPListenerAttributeResponseType* item);

template<typename T>
class Json2Array {
public:
  Json2Array(const Json::Value& value, std::vector<T>* vec) {
    if(!value.isArray()) {
      return;
    }
    for(int i = 0; i < value.size(); i++) {
      T val;
      Json2Type(value[i], &val);
      vec->push_back(val);
    }
  }
};

void Json2Type(const Json::Value& value, std::string* item) {
  *item = value.asString();
}
void Json2Type(const Json::Value& value, SlbSetLoadBalancerHTTPListenerAttributeResponseType* item) {
}
}

int Slb::SetLoadBalancerHTTPListenerAttribute(const SlbSetLoadBalancerHTTPListenerAttributeRequestType& req,
                      SlbSetLoadBalancerHTTPListenerAttributeResponseType* response,
                       SlbErrorInfo* error_info) {
  std::string str_response;
  int status_code;
  int ret = 0;
  bool parse_success = false;
  std::string secheme = this->use_tls_ ? "https" : "http";
  AliRpcRequest* req_rpc = new AliRpcRequest(version_,
                         appid_,
                         secret_,
                         secheme + "://" + host_);
  if((!this->use_tls_) && this->proxy_host_ && this->proxy_host_[0]) {
    req_rpc->SetHttpProxy( this->proxy_host_);
  }
  Json::Value val;
  Json::Reader reader;
  req_rpc->AddRequestQuery("Action","SetLoadBalancerHTTPListenerAttribute");
  if(!req.load_balancer_id.empty()) {
    req_rpc->AddRequestQuery("LoadBalancerId", req.load_balancer_id);
  }
  if(!req.listener_port.empty()) {
    req_rpc->AddRequestQuery("ListenerPort", req.listener_port);
  }
  if(!req.xforwarded_for.empty()) {
    req_rpc->AddRequestQuery("XForwardedFor", req.xforwarded_for);
  }
  if(!req.scheduler.empty()) {
    req_rpc->AddRequestQuery("Scheduler", req.scheduler);
  }
  if(!req.sticky_session.empty()) {
    req_rpc->AddRequestQuery("StickySession", req.sticky_session);
  }
  if(!req.sticky_session_type.empty()) {
    req_rpc->AddRequestQuery("StickySessionType", req.sticky_session_type);
  }
  if(!req.cookie_timeout.empty()) {
    req_rpc->AddRequestQuery("CookieTimeout", req.cookie_timeout);
  }
  if(!req.cookie.empty()) {
    req_rpc->AddRequestQuery("Cookie", req.cookie);
  }
  if(!req.health_check.empty()) {
    req_rpc->AddRequestQuery("HealthCheck", req.health_check);
  }
  if(!req.domain.empty()) {
    req_rpc->AddRequestQuery("Domain", req.domain);
  }
  if(!req.ur_i.empty()) {
    req_rpc->AddRequestQuery("URI", req.ur_i);
  }
  if(!req.healthy_threshold.empty()) {
    req_rpc->AddRequestQuery("HealthyThreshold", req.healthy_threshold);
  }
  if(!req.unhealthy_threshold.empty()) {
    req_rpc->AddRequestQuery("UnhealthyThreshold", req.unhealthy_threshold);
  }
  if(!req.health_check_timeout.empty()) {
    req_rpc->AddRequestQuery("HealthCheckTimeout", req.health_check_timeout);
  }
  if(!req.interval.empty()) {
    req_rpc->AddRequestQuery("Interval", req.interval);
  }
  if(!req.host_id.empty()) {
    req_rpc->AddRequestQuery("HostId", req.host_id);
  }
  if(!req.owner_account.empty()) {
    req_rpc->AddRequestQuery("OwnerAccount", req.owner_account);
  }
  if(this->region_id_ && this->region_id_[0]) {
    req_rpc->AddRequestQuery("RegionId", this->region_id_);
  }
  if(req_rpc->CommitRequest() != 0) {
     if(error_info) {
       error_info->code = "connect to host failed";
     }
     ret = -1;
     goto out;
  }
  status_code = req_rpc->WaitResponseHeaderComplete();
  req_rpc->ReadResponseBody(str_response);
  if(status_code > 0 && !str_response.empty()){
    parse_success = reader.parse(str_response, val);
  }
  if(!parse_success) {
    if(error_info) {
      error_info->code = "parse response failed";
    }
    ret = -1;
    goto out;
  }
  if(status_code!= 200 && error_info && parse_success) {
    error_info->request_id = val.isMember("RequestId") ? val["RequestId"].asString(): "";
    error_info->code = val.isMember("Code") ? val["Code"].asString(): "";
    error_info->host_id = val.isMember("HostId") ? val["HostId"].asString(): "";
    error_info->message = val.isMember("Message") ? val["Message"].asString(): "";
  }
  if(status_code== 200 && response) {
    Json2Type(val, response);
  }
  ret = status_code;
out:
  delete req_rpc;
  return ret;
}
