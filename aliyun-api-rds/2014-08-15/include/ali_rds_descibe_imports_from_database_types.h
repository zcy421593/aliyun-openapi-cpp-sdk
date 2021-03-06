#ifndef ALI_RDS_DESCIBE_IMPORTS_FROM_DATABASE_TYPESH
#define ALI_RDS_DESCIBE_IMPORTS_FROM_DATABASE_TYPESH
#include <stdio.h>
#include <string>
#include <vector>
namespace aliyun {
struct RdsDescibeImportsFromDatabaseRequestType {
  std::string owner_id;
  std::string resource_owner_account;
  std::string resource_owner_id;
  std::string client_token;
  std::string db_instance_id;
  std::string engine;
  std::string import_id;
  std::string start_time;
  std::string end_time;
  std::string page_size;
  std::string page_number;
  std::string owner_account;
};
struct RdsDescibeImportsFromDatabaseImportResultFromDBType {
  int import_id;
  std::string import_data_type;
  std::string import_data_status;
  std::string import_data_status_description;
  std::string incremental_importing_time;
};
struct RdsDescibeImportsFromDatabaseResponseType {
  std::vector<RdsDescibeImportsFromDatabaseImportResultFromDBType> items;
  int total_record_count;
  int page_number;
  int page_record_count;
};
} // end namespace
#endif
