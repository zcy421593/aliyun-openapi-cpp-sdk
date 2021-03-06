#ifndef ALI_SLB_DESCRIBE_LOAD_BALANCER_ATTRIBUTE_TYPESH
#define ALI_SLB_DESCRIBE_LOAD_BALANCER_ATTRIBUTE_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct SlbDescribeLoadBalancerAttributeRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string load_balancer_id;
  std::string owner_account;
};
struct SlbDescribeLoadBalancerAttributeListenerPortAndProtocalType {
  int listener_port;
  std::string listener_protocal;
};
struct SlbDescribeLoadBalancerAttributeListenerPortAndProtocolType {
  int listener_port;
  std::string listener_protocol;
};
struct SlbDescribeLoadBalancerAttributeBackendServerType {
  std::string server_id;
  int weight;
};
struct SlbDescribeLoadBalancerAttributeResponseType {
  std::vector<SlbDescribeLoadBalancerAttributeListenerPortAndProtocalType> listener_ports_and_protocal;
  std::vector<SlbDescribeLoadBalancerAttributeListenerPortAndProtocolType> listener_ports_and_protocol;
  std::vector<SlbDescribeLoadBalancerAttributeBackendServerType> backend_servers;
  std::vector<std::string> listener_ports;
  std::string load_balancer_id;
  std::string load_balancer_name;
  std::string load_balancer_status;
  std::string region_id;
  std::string region_id_alias;
  std::string address;
  std::string address_type;
  std::string vpc_id;
  std::string vswitch_id;
  std::string network_type;
  std::string internet_charge_type;
  int bandwidth;
  int sys_bandwidth;
  std::string create_time;
  long create_time_stamp;
  std::string master_zone_id;
  std::string slave_zone_id;
  int max_conn_limit;
  std::string security_status;
};
} // end namespace
#endif
