#pragma once
#include "mysql\mysql_connection.h"

#include "mysql\cppconn\driver.h"
#include "mysql\cppconn\exception.h"
#include "mysql\cppconn\resultset.h"
#include "mysql\cppconn\statement.h"
#include "mysql\cppconn\prepared_statement.h"


/*----------------------------------------------*/
/*			 DataBase - DataBase.h				*/
/*----------------------------------------------*/

class DataBase;

typedef std::shared_ptr<DataBase> MysqlDataBase;

class DataBase {

	public:
		DataBase();
		~DataBase();
	
		bool Connect(char *Host, char *Username, char *Password);
		bool SetDataBase(char *DBName);
	
		void Execute(const sql::SQLString &Query = "");
		void Prepare(const sql::SQLString &Query);
	
		void SampleExecute(const std::string &Query);
	
		void SetInt(const int &index, const int &value);
		void SetString(const int &index, const std::string &value);
	
		bool NextField();
		unsigned int RowsCount();
	
		
		std::string GetString(const std::string &index);
		int  GetInt(const std::string &index);
	
		float GetFloat(const std::string &index);
		long double GetDouble(const std::string &index);

private:

	sql::Driver *Driver;
	std::unique_ptr<sql::Connection> Connection;
	std::unique_ptr<sql::Statement> Stm;
	std::unique_ptr<sql::PreparedStatement> PrepStm;
	std::unique_ptr<sql::ResultSet> Res;

};