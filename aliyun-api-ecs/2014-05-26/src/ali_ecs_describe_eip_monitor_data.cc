#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_ecs.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, EcsDescribeEipMonitorDataEipMonitorDataType* item);
void Json2Type(const Json::Value& value, EcsDescribeEipMonitorDataResponseType* item);

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
void Json2Type(const Json::Value& value, EcsDescribeEipMonitorDataEipMonitorDataType* item) {
  if(value.isMember("EipRX")) {
    item->eip_rx = value["EipRX"].asInt();
  }
  if(value.isMember("EipTX")) {
    item->eip_tx = value["EipTX"].asInt();
  }
  if(value.isMember("EipFlow")) {
    item->eip_flow = value["EipFlow"].asInt();
  }
  if(value.isMember("EipBandwidth")) {
    item->eip_bandwidth = value["EipBandwidth"].asInt();
  }
  if(value.isMember("EipPackets")) {
    item->eip_packets = value["EipPackets"].asInt();
  }
  if(value.isMember("TimeStamp")) {
    item->time_stamp = value["TimeStamp"].asString();
  }
}
void Json2Type(const Json::Value& value, EcsDescribeEipMonitorDataResponseType* item) {
  if(value.isMember("EipMonitorDatas") && value["EipMonitorDatas"].isMember("EipMonitorData")) {
    Json2Array<EcsDescribeEipMonitorDataEipMonitorDataType>(value["EipMonitorDatas"]["EipMonitorData"], &item->eip_monitor_datas);
  }
}
}

int Ecs::DescribeEipMonitorData(const EcsDescribeEipMonitorDataRequestType& req,
                      EcsDescribeEipMonitorDataResponseType* response,
                       EcsErrorInfo* error_info) {
  std::string str_response;
  int status_code;
  int ret = 0;
  bool parse_success = false;
  AliRpcRequest* req_rpc = new AliRpcRequest(version_,
                         appid_,
                         secret_,
                         "https://" + host_);
  Json::Value val;
  Json::Reader reader;
  req_rpc->AddRequestQuery("Action","DescribeEipMonitorData");
  if(!req.owner_id.empty()) {
    req_rpc->AddRequestQuery("OwnerId", req.owner_id);
  }
  if(!req.resource_owner_account.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerAccount", req.resource_owner_account);
  }
  if(!req.resource_owner_id.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerId", req.resource_owner_id);
  }
  if(!req.allocation_id.empty()) {
    req_rpc->AddRequestQuery("AllocationId", req.allocation_id);
  }
  if(!req.start_time.empty()) {
    req_rpc->AddRequestQuery("StartTime", req.start_time);
  }
  if(!req.end_time.empty()) {
    req_rpc->AddRequestQuery("EndTime", req.end_time);
  }
  if(!req.period.empty()) {
    req_rpc->AddRequestQuery("Period", req.period);
  }
  if(!req.owner_account.empty()) {
    req_rpc->AddRequestQuery("OwnerAccount", req.owner_account);
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