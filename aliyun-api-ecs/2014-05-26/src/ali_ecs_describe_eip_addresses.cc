#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_ecs.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesLockReasonType* item);
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesEipAddressType* item);
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesResponseType* item);

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
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesLockReasonType* item) {
  if(value.isMember("LockReason")) {
    item->lock_reason = value["LockReason"].asString();
  }
}
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesEipAddressType* item) {
  if(value.isMember("RegionId")) {
    item->region_id = value["RegionId"].asString();
  }
  if(value.isMember("IpAddress")) {
    item->ip_address = value["IpAddress"].asString();
  }
  if(value.isMember("AllocationId")) {
    item->allocation_id = value["AllocationId"].asString();
  }
  if(value.isMember("Status")) {
    item->status = value["Status"].asString();
  }
  if(value.isMember("InstanceId")) {
    item->instance_id = value["InstanceId"].asString();
  }
  if(value.isMember("Bandwidth")) {
    item->bandwidth = value["Bandwidth"].asString();
  }
  if(value.isMember("InternetChargeType")) {
    item->internet_charge_type = value["InternetChargeType"].asString();
  }
  if(value.isMember("AllocationTime")) {
    item->allocation_time = value["AllocationTime"].asString();
  }
  if(value.isMember("InstanceType")) {
    item->instance_type = value["InstanceType"].asString();
  }
  if(value.isMember("OperationLocks") && value["OperationLocks"].isMember("LockReason")) {
    Json2Array<EcsDescribeEipAddressesLockReasonType>(value["OperationLocks"]["LockReason"], &item->operation_locks);
  }
}
void Json2Type(const Json::Value& value, EcsDescribeEipAddressesResponseType* item) {
  if(value.isMember("TotalCount")) {
    item->total_count = value["TotalCount"].asInt();
  }
  if(value.isMember("PageNumber")) {
    item->page_number = value["PageNumber"].asInt();
  }
  if(value.isMember("PageSize")) {
    item->page_size = value["PageSize"].asInt();
  }
  if(value.isMember("EipAddresses") && value["EipAddresses"].isMember("EipAddress")) {
    Json2Array<EcsDescribeEipAddressesEipAddressType>(value["EipAddresses"]["EipAddress"], &item->eip_addresses);
  }
}
}

int Ecs::DescribeEipAddresses(const EcsDescribeEipAddressesRequestType& req,
                      EcsDescribeEipAddressesResponseType* response,
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
  req_rpc->AddRequestQuery("Action","DescribeEipAddresses");
  if(!req.owner_id.empty()) {
    req_rpc->AddRequestQuery("OwnerId", req.owner_id);
  }
  if(!req.resource_owner_account.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerAccount", req.resource_owner_account);
  }
  if(!req.resource_owner_id.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerId", req.resource_owner_id);
  }
  if(!req.status.empty()) {
    req_rpc->AddRequestQuery("Status", req.status);
  }
  if(!req.eip_address.empty()) {
    req_rpc->AddRequestQuery("EipAddress", req.eip_address);
  }
  if(!req.allocation_id.empty()) {
    req_rpc->AddRequestQuery("AllocationId", req.allocation_id);
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
  if(!req.filter1_key.empty()) {
    req_rpc->AddRequestQuery("Filter.1.Key", req.filter1_key);
  }
  if(!req.filter2_key.empty()) {
    req_rpc->AddRequestQuery("Filter.2.Key", req.filter2_key);
  }
  if(!req.filter1_value.empty()) {
    req_rpc->AddRequestQuery("Filter.1.Value", req.filter1_value);
  }
  if(!req.filter2_value.empty()) {
    req_rpc->AddRequestQuery("Filter.2.Value", req.filter2_value);
  }
  if(!req.lock_reason.empty()) {
    req_rpc->AddRequestQuery("LockReason", req.lock_reason);
  }
  if(!req.associated_instance_type.empty()) {
    req_rpc->AddRequestQuery("AssociatedInstanceType", req.associated_instance_type);
  }
  if(!req.associated_instance_id.empty()) {
    req_rpc->AddRequestQuery("AssociatedInstanceId", req.associated_instance_id);
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
