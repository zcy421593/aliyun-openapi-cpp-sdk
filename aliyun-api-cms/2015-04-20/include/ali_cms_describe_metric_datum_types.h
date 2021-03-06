#ifndef ALI_CMS_DESCRIBE_METRIC_DATUM_TYPESH
#define ALI_CMS_DESCRIBE_METRIC_DATUM_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct CmsDescribeMetricDatumRequestType {
  std::string namespace_;
  std::string metric_name;
  std::string start_time;
  std::string end_time;
  std::string dimensions;
  std::string period;
  std::string statistics;
  std::string group_name;
  std::string next_token;
  std::string length;
};
struct CmsDescribeMetricDatumResponseType {
  std::vector<std::string> datapoints;
  std::string next_token;
  std::string code;
  std::string message;
};
} // end namespace
#endif
