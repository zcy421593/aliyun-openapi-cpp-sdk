#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_slb.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, SlbDescribeBackendServersBackendServerType* item);
void Json2Type(const Json::Value& value, SlbDescribeBackendServersListenerType* item);
void Json2Type(const Json::Value& value, SlbDescribeBackendServersResponseType* item);

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
void Json2Type(const Json::Value& value, SlbDescribeBackendServersBackendServerType* item) {
  if(value.isMember("ServerId")) {
    item->server_id = value["ServerId"].asString();
  }
  if(value.isMember("ServerHealthStatus")) {
    item->server_health_status = value["ServerHealthStatus"].asString();
  }
}
void Json2Type(const Json::Value& value, SlbDescribeBackendServersListenerType* item) {
  if(value.isMember("ListenerPort")) {
    item->listener_port = value["ListenerPort"].asInt();
  }
  if(value.isMember("BackendServers") && value["BackendServers"].isMember("BackendServer")) {
    Json2Array<SlbDescribeBackendServersBackendServerType>(value["BackendServers"]["BackendServer"], &item->backend_servers);
  }
}
void Json2Type(const Json::Value& value, SlbDescribeBackendServersResponseType* item) {
  if(value.isMember("Listeners") && value["Listeners"].isMember("Listener")) {
    Json2Array<SlbDescribeBackendServersListenerType>(value["Listeners"]["Listener"], &item->listeners);
  }
}
}

int Slb::DescribeBackendServers(const SlbDescribeBackendServersRequestType& req,
                      SlbDescribeBackendServersResponseType* response,
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
  Json::Value val;
  Json::Reader reader;
  req_rpc->AddRequestQuery("Action","DescribeBackendServers");
  if(!req.load_balancer_id.empty()) {
    req_rpc->AddRequestQuery("LoadBalancerId", req.load_balancer_id);
  }
  if(!req.listener_port.empty()) {
    req_rpc->AddRequestQuery("ListenerPort", req.listener_port);
  }
  if(!req.host_id.empty()) {
    req_rpc->AddRequestQuery("HostId", req.host_id);
  }
  if(!req.owner_account.empty()) {
    req_rpc->AddRequestQuery("OwnerAccount", req.owner_account);
  }
  if(!this->region_id_.empty()) {
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
