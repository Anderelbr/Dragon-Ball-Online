#include "stdafx.h"
#include "DataBase.h"

/*----------------------------------------------*/
/*			 DataBase - DataBase.cpp			*/
/*----------------------------------------------*/

DataBase::DataBase() {
	try {
		Driver = get_driver_instance();
		Driver->threadInit();
	}
	catch (sql::SQLException &err) {
		printf("Err: %s", err);
	}
};

DataBase::~DataBase() {
	Driver->threadEnd();
};

bool DataBase::Connect(char *Host, char *Username, char *Password) {
	try {

		Connection = (std::unique_ptr<sql::Connection>)(Driver->connect(Host, Username, Password));
		
		if (Connection->isValid())
			return true;

		return false;

	}catch (sql::SQLException &err) {
		printf("Err: %s !\n", err.what());
	}
};

bool DataBase::SetDataBase(char *DBName) {
	
	try {
		
		Connection->setSchema(DBName);
		Stm = (std::unique_ptr<sql::Statement>)(Connection->createStatement());

		return true;

	}catch(sql::SQLException &err){
		printf("Err: %s !\n", err.what());

		return false;
	}
}

void DataBase::Execute(const sql::SQLString &Query) {

	try {

		Res = (std::unique_ptr<sql::ResultSet>)((Query != "") ? Stm->executeQuery(Query) : PrepStm->executeQuery());

	}catch(sql::SQLException &err){
		printf("Err: %s !\n", err.what());
	}
}

void DataBase::SampleExecute(const std::string &Query) {

	try {
	
		Stm->execute(Query);

	}catch (sql::SQLException &err) {
		printf("Err: %s", err.what());
	}
}

void DataBase::Prepare(const sql::SQLString &Query) {
	
	try {
		PrepStm = (std::unique_ptr<sql::PreparedStatement>)(Connection->prepareStatement(Query));
	}catch (sql::SQLException &err) {
		printf("Err: %s !\n", err.what());
	}
}

void DataBase::SetInt(const int &index, const int &value) {
	PrepStm->setInt(index, value);
}

void DataBase::SetString(const int &index, const std::string &value) {
	PrepStm->setString(index, value);
}

int DataBase::GetInt(const std::string &index) {
	return Res->getInt(index);
}

float DataBase::GetFloat(const std::string &index) {
	return (float)Res->getDouble(index);
}

std::string DataBase::GetString(const std::string &index) {
	return  Res->getString(index);
}

unsigned int DataBase::RowsCount() {
	return Res->rowsCount();
}

long double DataBase::GetDouble(const std::string &index) {
	return Res->getDouble(index);
}

bool DataBase::NextField() {
	return Res->next();
}

