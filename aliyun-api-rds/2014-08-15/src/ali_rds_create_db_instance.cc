#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_rds.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, RdsCreateDBInstanceResponseType* item);

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
void Json2Type(const Json::Value& value, RdsCreateDBInstanceResponseType* item) {
  if(value.isMember("DBInstanceId")) {
    item->db_instance_id = value["DBInstanceId"].asString();
  }
  if(value.isMember("OrderId")) {
    item->order_id = value["OrderId"].asString();
  }
  if(value.isMember("ConnectionString")) {
    item->connection_string = value["ConnectionString"].asString();
  }
  if(value.isMember("Port")) {
    item->port = value["Port"].asString();
  }
}
}

int Rds::CreateDBInstance(const RdsCreateDBInstanceRequestType& req,
                      RdsCreateDBInstanceResponseType* response,
                       RdsErrorInfo* error_info) {
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
  req_rpc->AddRequestQuery("Action","CreateDBInstance");
  if(!req.owner_id.empty()) {
    req_rpc->AddRequestQuery("OwnerId", req.owner_id);
  }
  if(!req.resource_owner_account.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerAccount", req.resource_owner_account);
  }
  if(!req.resource_owner_id.empty()) {
    req_rpc->AddRequestQuery("ResourceOwnerId", req.resource_owner_id);
  }
  if(!req.client_token.empty()) {
    req_rpc->AddRequestQuery("ClientToken", req.client_token);
  }
  if(!req.engine.empty()) {
    req_rpc->AddRequestQuery("Engine", req.engine);
  }
  if(!req.engine_version.empty()) {
    req_rpc->AddRequestQuery("EngineVersion", req.engine_version);
  }
  if(!req.db_instance_class.empty()) {
    req_rpc->AddRequestQuery("DBInstanceClass", req.db_instance_class);
  }
  if(!req.db_instance_storage.empty()) {
    req_rpc->AddRequestQuery("DBInstanceStorage", req.db_instance_storage);
  }
  if(!req.system_db_charset.empty()) {
    req_rpc->AddRequestQuery("SystemDBCharset", req.system_db_charset);
  }
  if(!req.db_instance_net_type.empty()) {
    req_rpc->AddRequestQuery("DBInstanceNetType", req.db_instance_net_type);
  }
  if(!req.db_instance_description.empty()) {
    req_rpc->AddRequestQuery("DBInstanceDescription", req.db_instance_description);
  }
  if(!req.security_ip_list.empty()) {
    req_rpc->AddRequestQuery("SecurityIPList", req.security_ip_list);
  }
  if(!req.pay_type.empty()) {
    req_rpc->AddRequestQuery("PayType", req.pay_type);
  }
  if(!req.zone_id.empty()) {
    req_rpc->AddRequestQuery("ZoneId", req.zone_id);
  }
  if(!req.instance_network_type.empty()) {
    req_rpc->AddRequestQuery("InstanceNetworkType", req.instance_network_type);
  }
  if(!req.connection_mode.empty()) {
    req_rpc->AddRequestQuery("ConnectionMode", req.connection_mode);
  }
  if(!req.vp_cid.empty()) {
    req_rpc->AddRequestQuery("VPCId", req.vp_cid);
  }
  if(!req.vswitch_id.empty()) {
    req_rpc->AddRequestQuery("VSwitchId", req.vswitch_id);
  }
  if(!req.private_ip_address.empty()) {
    req_rpc->AddRequestQuery("PrivateIpAddress", req.private_ip_address);
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
