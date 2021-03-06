#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_ots.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, OtsGetInstanceQuotaType* item);
void Json2Type(const Json::Value& value, OtsGetInstanceInstanceInfoType* item);
void Json2Type(const Json::Value& value, OtsGetInstanceResponseType* item);

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
void Json2Type(const Json::Value& value, OtsGetInstanceQuotaType* item) {
  if(value.isMember("EntityQuota")) {
    item->entity_quota = value["EntityQuota"].asInt();
  }
}
void Json2Type(const Json::Value& value, OtsGetInstanceInstanceInfoType* item) {
  if(value.isMember("InstanceName")) {
    item->instance_name = value["InstanceName"].asString();
  }
  if(value.isMember("UserId")) {
    item->user_id = value["UserId"].asString();
  }
  if(value.isMember("ClusterName")) {
    item->cluster_name = value["ClusterName"].asString();
  }
  if(value.isMember("Status")) {
    item->status = value["Status"].asInt();
  }
  if(value.isMember("WriteCapacity")) {
    item->write_capacity = value["WriteCapacity"].asInt();
  }
  if(value.isMember("ReadCapacity")) {
    item->read_capacity = value["ReadCapacity"].asInt();
  }
  if(value.isMember("Description")) {
    item->description = value["Description"].asString();
  }
  if(value.isMember("CreateTime")) {
    item->create_time = value["CreateTime"].asString();
  }
  if(value.isMember("Quota")) {
    Json2Type(value["Quota"], &item->quota);
  }
}
void Json2Type(const Json::Value& value, OtsGetInstanceResponseType* item) {
  if(value.isMember("InstanceInfo")) {
    Json2Type(value["InstanceInfo"], &item->instance_info);
  }
}
}

int Ots::GetInstance(const OtsGetInstanceRequestType& req,
                      OtsGetInstanceResponseType* response,
                       OtsErrorInfo* error_info) {
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
  req_rpc->AddRequestQuery("Action","GetInstance");
  if(!req.instance_name.empty()) {
    req_rpc->AddRequestQuery("InstanceName", req.instance_name);
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
