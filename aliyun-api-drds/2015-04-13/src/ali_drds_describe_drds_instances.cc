#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_drds.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesVipType* item);
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesInstanceType* item);
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesResponseType* item);

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
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesVipType* item) {
  if(value.isMember("IP")) {
    item->ip = value["IP"].asString();
  }
  if(value.isMember("Port")) {
    item->port = value["Port"].asString();
  }
  if(value.isMember("Type")) {
    item->type = value["Type"].asString();
  }
}
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesInstanceType* item) {
  if(value.isMember("DrdsInstanceId")) {
    item->drds_instance_id = value["DrdsInstanceId"].asString();
  }
  if(value.isMember("Type")) {
    item->type = value["Type"].asString();
  }
  if(value.isMember("RegionId")) {
    item->region_id = value["RegionId"].asString();
  }
  if(value.isMember("ZoneId")) {
    item->zone_id = value["ZoneId"].asString();
  }
  if(value.isMember("Description")) {
    item->description = value["Description"].asString();
  }
  if(value.isMember("NetworkType")) {
    item->network_type = value["NetworkType"].asString();
  }
  if(value.isMember("Status")) {
    item->status = value["Status"].asString();
  }
  if(value.isMember("CreateTime")) {
    item->create_time = value["CreateTime"].asInt();
  }
  if(value.isMember("Version")) {
    item->version = value["Version"].asInt();
  }
  if(value.isMember("Vips") && value["Vips"].isMember("Vip")) {
    Json2Array<DrdsDescribeDrdsInstancesVipType>(value["Vips"]["Vip"], &item->vips);
  }
}
void Json2Type(const Json::Value& value, DrdsDescribeDrdsInstancesResponseType* item) {
  if(value.isMember("Success")) {
    item->success = value["Success"].asBool();
  }
  if(value.isMember("Data") && value["Data"].isMember("Instance")) {
    Json2Array<DrdsDescribeDrdsInstancesInstanceType>(value["Data"]["Instance"], &item->data);
  }
}
}

int Drds::DescribeDrdsInstances(const DrdsDescribeDrdsInstancesRequestType& req,
                      DrdsDescribeDrdsInstancesResponseType* response,
                       DrdsErrorInfo* error_info) {
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
  req_rpc->AddRequestQuery("Action","DescribeDrdsInstances");
  if(!req.type.empty()) {
    req_rpc->AddRequestQuery("Type", req.type);
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