#pragma once
#include "stdafx.h"


class TablesReader;
typedef std::shared_ptr<TablesReader> TablesContainer;

class TablesReader {

	public:


		TablesReader() {};
		~TablesReader() {};
	
		//-----------------------------------------------------------------------------------------------------

		void LoadTables(std::string *FilesName, unsigned short TablesCount) {
	
			FILE *Stream = NULL;
			unsigned int FileSize = 0;
	
			try {
	
				for (unsigned short i = 0; i < TablesCount; i++) {
	
					fopen_s(&Stream, ("Tables/" + FilesName[i]).c_str(), "rb");
	
					if (Stream == NULL) {
						printf("Error opening file!");
						system("pause>0");
					}
	
					/*----------------------------------------------*/
	
					fseek(Stream, 0, SEEK_END);
					FileSize = ftell(Stream);
	
					rewind(Stream);
	
					/*----------------------------------------------*/
	
					if (FileSize <= 0) {
	
						printf("FileSize <= 0");
						fclose(Stream);
	
						system("pause>0");
					}
	
					/*----------------------------------------------*/
	
					std::string File;
					File.resize(FileSize);
	
					unsigned int SizeReaded = fread_s(&File[0], FileSize, sizeof(char), FileSize, Stream);
	
					/*----------------------------------------------*/
	
					if (FileSize != SizeReaded) {
	
						printf("FileSize < SizeReaded!");
	
						fclose(Stream);
						system("pause>0");
					}
	
					/*----------------------------------------------*/
	
					Tables.insert(std::make_pair(FilesName[i].c_str(), File));
	
					fclose(Stream);
					printf("[%s][%d] Loaded successfully!\n", FilesName[i].c_str(), FileSize);
	
					/*----------------------------------------------*/
				}
			}
			catch (std::exception &err) {
				printf("Err: %s", err);
			}
		}

		//-----------------------------------------------------------------------------------------------------
	
		template<typename T>
		unsigned int GetTable(std::string FileName, T &NData, unsigned char Race, unsigned char Class, unsigned char Gender) {
			
			memset(&NData, 0, sizeof(NData));
			std::string LTable = Tables.find(FileName.c_str())->second;

			unsigned int TableSize = Tables.find(FileName.c_str())->second.size();
			unsigned int CountTables = (TableSize / sizeof(NData));

			for (unsigned short a = 0; a < CountTables; a++) {
	
				memcpy(&NData, &(LTable.c_str())[(TableSize / CountTables * a) + 6], sizeof(NData));
				
				if (NData.Race == Race)
					if (NData.Class == Class)
						if (NData.Gender == Gender)
							break;
			}

			return CountTables;
		};

		//-----------------------------------------------------------------------------------------------------

		template<typename T>
		void GetTable(std::string FileName, T &NData, unsigned int &Tblidx) {

			memset(&NData, 0, sizeof(NData));
			std::string LTable = Tables.find(FileName.c_str())->second;

			unsigned int TableSize = LTable.size();
			unsigned int CountTables = (TableSize / sizeof(NData));

			for (unsigned short a = 0; a < CountTables; a++) {

				unsigned int TTblidx = *(unsigned int*)&(LTable.c_str())[(TableSize / CountTables * a) + 6];
				
				if (TTblidx == Tblidx) {
					memcpy(&NData, &(LTable.c_str())[(TableSize / CountTables * a) + 6], sizeof(NData));
					break;
				}
			}
		};

		//-----------------------------------------------------------------------------------------------------

		//Get Table per struct
		template<typename T>
		std::map<unsigned int, T> GetTable(std::string FileName, T &NData) {

			std::string LTable = Tables.find(FileName.c_str())->second;
			std::map<UINT, T> NList;

			unsigned int TableSize = LTable.size();
			unsigned int CountTables = (TableSize / sizeof(NData));

			memset(&NData, 0, sizeof(NData));

			for (unsigned short a = 0; a < CountTables; a++) {

				memcpy(&NData, &(LTable.c_str())[(TableSize / CountTables * a) + 6], sizeof(NData));
				NList.insert(std::make_pair(NData.Tblidx, NData));
			}

			return NList;
		};

		//-----------------------------------------------------------------------------------------------------

		//Get all table on string
		std::string GetAllTable(std::string FileName) {

			return Tables.find(FileName.c_str())->second;
		};

		//-----------------------------------------------------------------------------------------------------

		//Get file(table) size
		unsigned int GetTableSize(std::string FileName) {

			return Tables.find(FileName.c_str())->second.size();
		};

		//-----------------------------------------------------------------------------------------------------

		//Get tables count per struct
		unsigned int GetTableSize(std::string FileName, unsigned int StructSize) {

			unsigned int TableSize = Tables.find(FileName.c_str())->second.size();
			unsigned int CountTables = (TableSize / StructSize);

			return CountTables;
		};
	
	private:
		std::map<std::string, std::string> Tables;
};