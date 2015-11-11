#include <stdio.h>
#include "ali_api_core.h"
#include "ali_string_utils.h"
#include "ali_alert.h"
#include "json/value.h"
#include "json/reader.h"
using namespace aliyun;
namespace {

void Json2Type(const Json::Value& value, std::string* item);
void Json2Type(const Json::Value& value, AlertCreateDBSourceResponseType* item);

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
void Json2Type(const Json::Value& value, AlertCreateDBSourceResponseType* item) {
  if(value.isMember("code")) {
    item->code = value["code"].asString();
  }
  if(value.isMember("message")) {
    item->message = value["message"].asString();
  }
  if(value.isMember("success")) {
    item->success = value["success"].asString();
  }
  if(value.isMember("traceId")) {
    item->trace_id = value["traceId"].asString();
  }
  if(value.isMember("result")) {
    item->result = value["result"].asString();
  }
}
}

int Alert::CreateDBSource(const AlertCreateDBSourceRequestType& req,
                      AlertCreateDBSourceResponseType* response,
                      AlertErrorInfo* error_info) {
  std::string str_response;
  int status_code;
  int ret = 0;
  bool parse_success = false;
  Json::Value val;
  Json::Reader reader;
  std::string url = "http://" + host_ + get_format_string("/projects/%s/sources", req.project_name.c_str());
  AliRoaRequest* req_rpc = new AliRoaRequest(version_,
                         appid_,
                         secret_,
                         url);
  req_rpc->setRequestMethod("POST");
  if(req_rpc->CommitRequestWithBody(req.source) != 0) {
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
  if(status_code!= 200 && error_info) {
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