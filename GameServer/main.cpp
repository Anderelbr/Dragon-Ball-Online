#include "stdafx.h"
#include "CGameServer.h"

extern int GameServerMain(int argc, _TCHAR* argv[]);

int _cdecl _tmain(int argc, _TCHAR* argv[]){

	GameServerMain(argc, argv);
	return 0;
}

