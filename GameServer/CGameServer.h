#pragma once
#include "stdafx.h"
#include "NtlSfx.h"
#include "NtlThread.h"
#include "NtlFile.h"
#include "ClientSession.h"


//-----------------------------------------------------------------------------------
//		CGameServer
//-----------------------------------------------------------------------------------

class CGameServer : public CNtlServerApp {

	private:

		CNtlAcceptor        NtlAcceptor;
		CGameSessionFactory CSessionFactory;
		ServerConfig	    AppConfig;

	public:

		CGameServer() : CSessionFactory(){}
		~CGameServer(){}

		int LoadDeps();
		int OnInitApp();
		int OnCreate();
		int OnDestroy();
		int	OnCommandArgument(int argc, _TCHAR* argv[]);
		int OnAppStart();
};


