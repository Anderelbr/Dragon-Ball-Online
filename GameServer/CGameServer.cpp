#include "stdafx.h"
#include "CGameServer.h"
#include "FileReader.h"

//-----------------------------------------------------------------------------------
//		Author : GameServer by @AnderBerriel
//-----------------------------------------------------------------------------------

int CGameServer::OnInitApp(){

	AppConfig = *(ServerConfig*)ReadJson("Game");

	m_nMaxSessionCount = 5;
	m_pSessionFactory = &CSessionFactory;

	//---------------------------------------------

	if (m_pSessionFactory == NULL) return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;

	return NTL_SUCCESS;
}

int CGameServer::LoadDeps(){
	
	this->MysqlDB =		   MysqlDataBase  (new DataBase());
	this->Tables =		   TablesContainer(new TablesReader());
	this->CPlayerManager = PlayerManager  (new PlayersManager());

	int res = NTL_SUCCESS;
	
	//------------------------------------------------------------------------

	std::string TablesList[] = { "SpawnPlayerData.rdf", "SpawnNPCTable.rdf", "SpawnNPCData.rdf", "SpawnMOBTable.rdf", "SpawnMOBData.rdf", "CharacterNewbie.rdf" };
	Tables->LoadTables(TablesList, 6);

	//------------------------------------------------------------------------

	res = this->GetDB()->Connect(AppConfig.DBHost, AppConfig.DBUsername, AppConfig.DBPassword);
	if (res == NTL_SUCCESS) return NTL_FAIL;

	//------------------------------------------------------------------------

	res = this->GetDB()->SetDataBase(AppConfig.DBName);
	if (res == NTL_SUCCESS) return NTL_FAIL;

	//------------------------------------------------------------------------

	NTL_PRINT(PRINT_SYSTEM, "Now you are connected to data base server !\n\n");
	return NTL_SUCCESS;

}

//-----------------------------------------------------------------------------------
//		OnCreate
//-----------------------------------------------------------------------------------

int CGameServer::OnCreate(){

	int res = NTL_SUCCESS;

	res = NtlAcceptor.Create(AppConfig.ServerIP, std::stoi(AppConfig.ServerPort), SESSION_CLIENT, AppConfig.MaxClients, 5, 2, AppConfig.MaxClients);
	if (res != NTL_SUCCESS) return res;

	//---------------------------------------------

	res = m_network.Associate(&NtlAcceptor, true);
	if (res != NTL_SUCCESS) return res;

	return NTL_SUCCESS;
}

//-----------------------------------------------------------------------------------
//		OnCommandArgument
//-----------------------------------------------------------------------------------

int	CGameServer::OnCommandArgument(int argc, _TCHAR* argv[]) { 
	return NTL_SUCCESS; 
}

//-----------------------------------------------------------------------------------
//		OnAppStart
//-----------------------------------------------------------------------------------

int CGameServer::OnAppStart(){

	std::cout << "\n\n" << std::endl;
	std::cout << "\t  ____                              ____        _ _ " << std::endl;
	std::cout << "\t |  _ \\ _ __ __ _  __ _  ___  _ __ | __ )  __ _| | |" << std::endl;
	std::cout << "\t | | | | '__/ _` |/ _` |/ _ \\| '_ \\|  _ \\ / _` | | |" << std::endl;
	std::cout << "\t | |_| | | | (_| | (_| | (_) | | | | |_) | (_| | | |" << std::endl;
	std::cout << "\t |____/|_|  \\__,_|\\__, |\\___/|_| |_|____/ \\__,_|_|_|" << std::endl;
	std::cout << "\t                  |___/                             " << std::endl;
	std::cout << "\t             Dragon Ball Online Taiwan				\n\n" << std::endl;

	int res = LoadDeps();
	if (res != NTL_SUCCESS) return res;

	return NTL_SUCCESS;
}

//-----------------------------------------------------------------------------------
//		OnDestroy
//-----------------------------------------------------------------------------------

int CGameServer::OnDestroy(){ return NTL_SUCCESS; }

//-----------------------------------------------------------------------------------
//		GameServerMain
//-----------------------------------------------------------------------------------

int GameServerMain(int argc, _TCHAR* argv[]){

	CGameServer    CApp;
	CNtlFileStream Stream;

	int res = NTL_SUCCESS;

	//------------------------------------------------------------------------

	res = Stream.Create("GameLog.txt");
	if (res != NTL_SUCCESS) return res;

	//------------------------------------------------------------------------

	res = CApp.Create(argc, argv, "Server.ini");
	if (res != NTL_SUCCESS) return res;

	//------------------------------------------------------------------------

	NtlSetPrintStream(Stream.GetFilePtr());
	NtlSetPrintFlag(2 | PRINT_SYSTEM);

	//------------------------------------------------------------------------

	CApp.Start();
	CApp.WaitForTerminate();

	return NTL_SUCCESS;
}

