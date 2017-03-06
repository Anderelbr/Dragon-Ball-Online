#pragma once
#include "stdafx.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "Packets.h"

using boost::property_tree::ptree;
using boost::property_tree::write_json;
using boost::property_tree::read_json;

//-----------------------------------------------------------------------------------
//		Purpose	: 
//		Return  :
//-----------------------------------------------------------------------------------

ServerConfig *ReadJson(std::string object) {

	ServerConfig TempSc;
	ptree ReadData;

	memset(&TempSc, 0, sizeof(TempSc));
	/*--------------------------------------------*/

	read_json("ServerConfig.json", ReadData);

	int i = 0;
	int i2 = 0;
	int i3 = 0;

	/*----------------------------------------------*/

	for (auto& obj : ReadData.get_child(object)) {

		std::string data = obj.second.get_value<std::string>();

		if (i == 0) {

			std::stringstream sstream;
			sstream << object << ".Server " << i;

			for (auto& obj2 : ReadData.get_child(sstream.str())) {

				std::string data2 = obj2.second.get_value<std::string>();
				switch (i2) {

				case 0: memcpy(&TempSc.ServerIP, data2.c_str(), sizeof(TempSc.ServerIP)); break;
				case 1: memcpy(&TempSc.ServerPort, data2.c_str(), sizeof(TempSc.ServerPort)); break;

				case 2: TempSc.MaxClients = std::stoi(data2, nullptr, 0); break;
				case 3: memcpy(&TempSc.ServerName, data2.c_str(), sizeof(TempSc.ServerName)); break;

				}

				i2++;
			}
		}

		i++;
	}

	for (auto& obj : ReadData.get_child("DataBase")) {
		std::string data = obj.second.get_value<std::string>();

		switch (i3) {
		case 0: memcpy(&TempSc.DBHost, data.c_str(), sizeof(TempSc.DBHost)); break;
		case 1: memcpy(&TempSc.DBUsername, data.c_str(), sizeof(TempSc.DBUsername)); break;

		case 2: memcpy(&TempSc.DBPassword, data.c_str(), sizeof(TempSc.DBPassword)); break;
		case 3: memcpy(&TempSc.DBName, data.c_str(), sizeof(TempSc.DBName)); break;
		}

		i3++;
	}

	TempSc.ServerCount = i;
	printf("[ServerConfig] Loaded successfully!\n");

	return (ServerConfig*)&TempSc;
};