#ifndef ALI_ONS_ONS_TREND_GET_MACHINE_SAR_TYPESH
#define ALI_ONS_ONS_TREND_GET_MACHINE_SAR_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct OnsOnsTrendGetMachineSarRequestType {
  std::string ons_region_id;
  std::string ons_platform;
  std::string prevent_cache;
  std::string host_ip;
  std::string app_id;
  std::string metric;
  std::string begin_time;
  std::string end_time;
  std::string period;
};
struct OnsOnsTrendGetMachineSarStatsDataDoType {
  long x;
  float y;
};
struct OnsOnsTrendGetMachineSarDataType {
  std::vector<OnsOnsTrendGetMachineSarStatsDataDoType> records;
  std::string title;
  std::string xunit;
  std::string yunit;
};
struct OnsOnsTrendGetMachineSarResponseType {
  OnsOnsTrendGetMachineSarDataType data;
  std::string help_url;
};
} // end namespace
#endif
