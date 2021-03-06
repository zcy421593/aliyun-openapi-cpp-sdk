#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_ecs.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesRouteEntryType* item);
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesRouteTableType* item);
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesResponseType* item);

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
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesRouteEntryType* item) {
  if(value.isMember("RouteTableId")) {
    item->route_table_id = value["RouteTableId"].asString();
  }
  if(value.isMember("DestinationCidrBlock")) {
    item->destination_cidr_block = value["DestinationCidrBlock"].asString();
  }
  if(value.isMember("Type")) {
    item->type = value["Type"].asString();
  }
  if(value.isMember("Status")) {
    item->status = value["Status"].asString();
  }
  if(value.isMember("InstanceId")) {
    item->instance_id = value["InstanceId"].asString();
  }
  if(value.isMember("NextHopType")) {
    item->next_hop_type = value["NextHopType"].asString();
  }
}
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesRouteTableType* item) {
  if(value.isMember("VRouterId")) {
    item->vrouter_id = value["VRouterId"].asString();
  }
  if(value.isMember("RouteTableId")) {
    item->route_table_id = value["RouteTableId"].asString();
  }
  if(value.isMember("RouteTableType")) {
    item->route_table_type = value["RouteTableType"].asString();
  }
  if(value.isMember("CreationTime")) {
    item->creation_time = value["CreationTime"].asString();
  }
  if(value.isMember("RouteEntrys") && value["RouteEntrys"].isMember("RouteEntry")) {
    Json2Array<EcsDescribeRouteTablesRouteEntryType>(value["RouteEntrys"]["RouteEntry"], &item->route_entrys);
  }
}
void Json2Type(const Json::Value& value, EcsDescribeRouteTablesResponseType* item) {
  if(value.isMember("TotalCount")) {
    item->total_count = value["TotalCount"].asInt();
  }
  if(value.isMember("PageNumber")) {
    item->page_number = value["PageNumber"].asInt();
  }
  if(value.isMember("PageSize")) {
    item->page_size = value["PageSize"].asInt();
  }
  if(value.isMember("RouteTables") && value["RouteTables"].isMember("RouteTable")) {
    Json2Array<EcsDescribeRouteTablesRouteTableType>(value["RouteTables"]["RouteTable"], &item->route_tables);
  }
}
}

int Ecs::DescribeRouteTables(const EcsDescribeRouteTablesRequestType& req,
                      EcsDescribeRouteTablesResponseType* response,
                       EcsErrorInfo* error_info) {
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
  req_rpc->AddRequestQuery("Action","DescribeRouteTables");
  if(!req.owner_id.empty()) {
    req_rpc->AddRequestQuery("OwnerId", req.owner_id);
  }
  if(!req.resource_owner_account.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerAccount", req.resource_owner_account);
  }
  if(!req.resource_owner_id.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerId", req.resource_owner_id);
  }
  if(!req.vrouter_id.empty()) {
    req_rpc->AddRequestQuery("VRouterId", req.vrouter_id);
  }
  if(!req.route_table_id.empty()) {
    req_rpc->AddRequestQuery("RouteTableId", req.route_table_id);
  }
  if(!req.page_number.empty()) {
    req_rpc->AddRequestQuery("PageNumber", req.page_number);
  }
  if(!req.page_size.empty()) {
    req_rpc->AddRequestQuery("PageSize", req.page_size);
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
