#pragma once

//-----------------------------------------------------------------------------------
//		Purpose	: 
//-----------------------------------------------------------------------------------

enum ResultCodes {

	/*	***********************************	*/
	/*			RESULTCODES - LOGIN			*/
	/*	***********************************	*/

	AUTH_SUCCESS = 100,
	AUTH_FAIL = 101,
	AUTH_VERSION_FAIL = 102,
	AUTH_TOO_LONG_ACCOUNT = 103,
	AUTH_TOO_LONG_PASSWORD = 104,
	AUTH_AUTHKEY_FAIL = 105,
	AUTH_USER_SAMENAME_EXIST = 106,
	AUTH_WRONG_PASSWORD = 107,
	AUTH_USER_NOT_FOUND = 108,
	AUTH_USER_EXIST = 109,
	AUTH_USER_EXIST_IN_CHARACTER_SERVER = 110,
	AUTH_DB_FAIL = 111,
	AUTH_NO_AVAILABLE_CHARACTER_SERVER = 112,
	AUTH_USER_BLOCK = 113,
	AUTH_USER_TEMPORARY_BLOCK = 114,
	AUTH_SERVER_LOCKED = 115,
	AUTH_COMMON_CANT_DO_THAT_FOR_SOME_REASON = 116,
	AUTH_INVALID_CJI_KOR_COOKIE = 117,
	AUTH_IP_BLOCK = 118,

	AUTH_USER_KICKOUT_WAIT_PLZ = 119,
	AUTH_WEB_CHECK_AUTH_FAIL = 120,
	AUTH_AGE_SHUTDOWN_LIMIT_FAIL = 121,

	/*	***********************************	*/
	/*			RESULTCODES - CHAR			*/
	/*	***********************************	*/

	CHARACTER_SUCCESS = 200,		// ĳ���� �������� ��� ����
	CHARACTER_FAIL = 201,                 // ĳ���� �������� �������� ����
	CHARACTER_AUTHKEY_FAIL = 202,         // ����Ű ������ �����Ͽ����ϴ�.
	CHARACTER_TOO_LONG_NAME = 203,		// ĳ���͸��� ���̰� �ʰ��Ǿ����ϴ�.
	CHARACTER_TOO_SHORT_NAME = 204,		// ĳ���͸��� ���̰� �ʹ� ª���ϴ�.
	CHARACTER_SAMENAME_EXIST = 205,		// �̹� ĳ���͸��� �����մϴ�.
	CHARACTER_COUNT_OVER = 206,           // ĳ���� ���������� �ʰ��Ǿ����ϴ�.
	CHARACTER_NAME_NOT_EXIST = 207,       // ĳ���Ͱ� �������� �ʽ��ϴ�.
	CHARACTER_CREATE_VALUE_FAIL = 208,	// ĳ���� ���� ���� ��Ȯ���� �ʽ��ϴ�. 
	CHARACTER_USER_EXIST = 209,           // �̹� �������Դϴ�.
	CHARACTER_USER_EXIST_IN_GAME_SERVER = 210,		// ���� ������ �̹� �÷������� ĳ���Ͱ� �ֽ��ϴ�.
	CHARACTER_USER_ITEM_CREATE_FAIL = 211,// ĳ���� ������ ������ �����Ͽ����ϴ�. 
	CHARACTER_USER_SKILL_CREATE_FAIL = 212,			// ĳ���� ��ų ������ �����Ͽ����ϴ�.
	CHARACTER_USER_QUICK_SLOT_CREATE_FAIL = 213,		// ĳ���� �������� �ʱ�ȭ���� ���߽��ϴ�.
	CHARACTER_DB_QUERY_FAIL = 214, // ĳ���� �������� DB ������ �����Ͽ����ϴ�.
	CHARACTER_WRONG_SERVER_FARM_SELECTED = 215,		// �߸��� ������ �����Ͽ����ϴ�.
	CHARACTER_USER_BLOCK = 216,			// ĳ���Ͱ� ��� �Ǿ����ϴ�. �ڼ��� ������ Ȩ�������� �����Ͻʽÿ�.
	CHARACTER_BLOCK_STRING_INCLUDED = 217, // �������� ��Ʈ���� ���ԵǾ� �ֽ��ϴ�.
	CHARACTER_TEMPORARY_BLOCK = 218,		// ��۾����̶� �����Ͻ� �� �����ϴ�. ��� �� ������ �õ��غ��ʽÿ�.
	CHARACTER_AUTHKEY_MISMATCH = 219,
	CHARACTER_AUTHKEY_CREATE_FAIL = 220,
	CHARACTER_AUTHKEY_NOT_FOUND = 221,
	CHARACTER_DELETE_GUILD_LEADER_FAIL = 222,			// ��帮���� ĳ���� ���� �� �����ϴ�.
	CHARACTER_DELETE_BUDOKAI_REGISTER_FAIL = 223,		// õ�����Ϲ���ȸ ��û�� �϶��� ĳ���͸� ������ �� �����ϴ�.
	CHARACTER_SERVER_LOCKED = 224,					// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	CHARACTER_DISCONNECTED_FORCEDLY = 225,			// ����� ���� ������ ������ ����Ǿ����ϴ�.
	CHARACTER_DISCONNECTED_TEMPORARILY = 226,			// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.
	CHARACTER_RACE_NOT_ALLOWED = 227,					// ������ ���� ���� �Դϴ�.

	CHARACTER_COMMON_CANT_DO_THAT_FOR_SOME_REASON = 228,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	CHARACTER_USER_SHOULD_WAIT_FOR_CONNECT = 229,
	CHARACTER_SERVER_IS_UNDER_CONSTRUCTION = 230,					// ���� ���� �� �Դϴ�.
	CHARACTER_DELETE_CHAR_FAIL = 231,


	/*	***********************************	*/
	/*			RESULTCODES - GAME			*/
	/*	***********************************	*/


	GAME_SUCCESS = 500,				// ���Ӽ��� ���� ��� ����
	GAME_FAIL,						// ���Ӽ��� ���� �������� ����

	GAME_DB_CHAR_DATA_LOAD_FAIL,	// ĳ���� ����Ÿ �ε��� �����Ͽ����ϴ�.
	GAME_DB_CHAR_NOT_FOUND,			// �ش��ϴ� ĳ��Ÿ ����Ÿ�� �������� �ʽ��ϴ�.

	GAME_INVALID_AUTH_KEY,			// ����Ű ������ �����Ͽ����ϴ�.
	GAME_USER_EXIST,				// �̹� �������Դϴ�.
	GAME_SERVER_LOCKED,				// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	GAME_WRONG_SERVER_CHANNEL_HAS_BEEN_SPECIFIED,			// �߸��� ���� ä���� �����Ͽ����ϴ�.

	GAME_CHAR_IS_WRONG_STATE,		// ������ �� �� �����ϴ�
	GAME_INPUT_PARAMETER_WRONG,		// �ùٸ��� ���� �Է� �Դϴ�.

	GAME_TARGET_IS_WRONG_STATE,		// ����� ������ ���°� �ƴմϴ�.
	GAME_TARGET_NOT_FOUND,			// ����� ã�� �� �����ϴ�.
	GAME_TARGET_TOO_FAR,			// ������ �Ÿ��� �ʹ� �ٴϴ�.
	GAME_TARGET_TOO_CLOSE,			// ������ �Ÿ��� �ʹ� �������ϴ�.
	GAME_TARGET_HAS_NOT_FUNCTION,	// ����� �ش� ����� �������� �ʽ��ϴ�.

	GAME_DISCONNECTED_FORCEDLY,							// ����� ���� ������ ������ ����Ǿ����ϴ�.
	GAME_DISCONNECTED_TEMPORARILY,						// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.

	GAME_COMMON_YOU_ARE_NOT_IN_A_PARTY,					// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_COMMON_YOU_ARE_NOT_A_PARTY_LEADER,				// ��Ƽ ������ �ƴմϴ�.
	GAME_COMMON_ZENNY_CANT_BE_USED_RIGHT_NOW,			// �Ͻ������� ���ϸ� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_COMMON_CANT_DO_THAT_FOR_SOME_REASON,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	GAME_COMMON_NON_EXISTING_PET_SPECIFIED,				// �������� �ʴ� ���� �����Ͽ����ϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_SPAWNING_STATE,				// ���� ���� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_STATE,				// �� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_JUMPING_STATE,		// ���ڸ� ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_JUMPING_STATE,				// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_NON_JUMPING_STATE,			// ���� ���� �ƴ� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SITTING_STATE,				// �ɾ� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FAINTING_STATE,				// �ǽ��� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CAMPING_STATE,				// ķ�� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_LEAVING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_STATE,				// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_JUMPING_STATE,		// ���� �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESTMOVING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FOLLOWING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FALLING_STATE,				// �������� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DASH_STATE,					// �뽬 �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TELEPORTING_STATE,			// �ڷ���Ʈ ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLIDING_STATE,				// �����̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_KNOCKDOWN_STATE,			// �˴ٿ� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FOCUSING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_STATE,				// ��ų ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_AFFECTING_STATE,			// ��ų ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_KEEPING_EFFECT_STATE,		// ȿ�� ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_ITEM_STATE,			// ������ ��� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STUNNED_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLEEPING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PARALYZED_STATE,			// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HTB_STATE,					// HTB ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SANDBAG_STATE,				// HTB ��ų�� �ɸ� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_STATE,				// �⸦ ������ �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_BLOCKING_STATE,				// Block ��忡���� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESPAWNING_STATE,			// ���忡�� ����� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PRIVATESHOP_STATE,			// ���� ������ ���� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DIRECT_PLAY_STATE,			// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_OPERATING_STATE,			// ������Ʈ �����߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_RIDEON_STATE,				// Ż���� ź���¿����� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TURNING_STATE,				// �ϻ��¿����� �� �� ���� ����Դϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_INVISIBLE_CONDITION,		// ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HIDING_KI_CONDITION,		// �� ����� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TRANSPARENT_CONDITION,		// GM ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TERROR_CONDITION,			// ������ �ɸ� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_AFTEREFFECT_CONDITION,		// ������ ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_BLOCKED_CONDITION,		// �� �����Ⱑ �Ұ����� �����Դϴ�.

	GAME_GAMERULE_REG_CANT_PLAY_IN_FREEBATTLE,				// ������Ʋ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_RANKBATTLE,				// ��ũ��Ʋ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_TMQ,						// Ÿ�Ӹӽ� ����Ʈ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_SUMMON_DRAGONBALL,		// �巡�ﺼ ��ȯ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_PRIVATE_SHOP,			// ���λ��� �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_BUDOKAI,					// õ�����Ϲ���ȸ �߿��� �� �� �����ϴ�.

	GAME_GAMERULE_REG_ALREADY_JOINED_IN_FREEBATTLE,			// �̹� ������Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_RANKBATTLE,			// �̹� ��ũ��Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_TMQ,				// �̹� Ÿ�Ӹӽ� ����Ʈ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_SUMMON_DRAGONBALL,			// �̹� �巡�ﺼ ��ȯ ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_OPENED_PRIVATE_SHOP,			// �̹� ���λ��� ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_BUDOKAI,				// �̹� õ�����Ϲ���ȸ ���� ���Դϴ�.

	GAME_CONTENTS_LOCK,										// ���� ����ִ� �������Դϴ�.
	GAME_CONTENTS_CAN_NOT_PLAY_IN_BUDOKAI_REGISTER_STATE,	// õ�����Ϲ���ȸ ��ϱⰣ �߿��� �̿��� �� �����ϴ�.

	GAME_WORLD_CAN_NOT_CREATE_DYNAMIC_WORLD,			// ���带 ������ �� �����ϴ�.
	GAME_WORLD_NOW_CREATING,							// ��� �� �ٽ� �õ��Ͻʽÿ�.
	GAME_WORLD_ALREADY_WORLD_ENTERED,					// �̹� ���忡 ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD,						// ������ �� �ִ� ���尡 �����ϴ�.
	GAME_WORLD_ALREADY_WORLD_AREA_ENTERED,				// �̹� ���� ������ ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_FIND_WORLD_AREA,					// ������ ���念���� ã�� �� �����ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD_AREA,					// ������ �� �ִ¿��念���� �����ϴ�.

	GAME_SHORTCUT_KEY_ARLEADY_FOUND,					// ���� Ű�� �̹� �����Ǿ� �ֽ��ϴ�.
	GAME_SHORTCUT_KEY_DEL_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.
	GAME_SHORTCUT_KEY_MODIFY_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.

	GAME_COMMON_CANT_DO_THAT_NOT_ALLOWED_TARGET,		// ��� ������ �Ұ����� ���� �Դϴ�.

	GAME_COMMON_CANT_FIND_OBJECT,						// �ش� ������Ʈ�� ã�� �� �����ϴ�.

	GAME_CHAR_WRONG_REVIVAL_METHOD,						// �߸��� ��Ȱ ����Դϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_TIMEOUT,					// Ÿ�Ӿƿ��Ǿ� ������ �� �����ϴ�.
	GAME_CANNOT_CONNECT_TARGET_CHANNEL_FULL,			// �̵��Ϸ��� ä�ο� ���� ������ �����ϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_INVAlID_CHARACTER,		// �������� ĳ���Ͱ� �ƴմϴ�.
	GAME_TARGET_HAS_DIFFERENT_JOB,						// ����� ������ �ùٸ��� �ʽ��ϴ�.

	GAME_GMT_NOT_ENOUGH_RESET_POINT,					// GMT �缳�� ����Ʈ�� �����մϴ�.

	//-----------------------------------------------------------------
	GAME_SKILL_NOT_ACTIVE_TYPE = 600,		// Active Ÿ���� ��ų�� �ƴմϴ�.
	GAME_SKILL_YOU_DONT_HAVE_THE_SKILL,		// ������ ���� ���� ��ų�Դϴ�.
	GAME_SKILL_NOT_EXISTING_SKILL,			// �������� �ʴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_CAST_NOW,				// ���� ��ų�� ������ �� �ִ� ���°� �ƴմϴ�.
	GAME_SKILL_NO_TARGET_APPOINTED,				// ����� �����ϼž� �մϴ�.
	GAME_SKILL_INVALID_TARGET_APPOINTED,		// ���� Ÿ�ٿ� ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_NOT_READY_TO_BE_CAST,		// ��ų�� ��Ÿ���� ��ٷ��� �մϴ�.
	GAME_SKILL_NOT_ENOUGH_LP,				// LP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_EP,				// EP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_RP_BALL,						// RP ������ ������� �ʽ��ϴ�.

	GAME_SKILL_NO_REQUIRED_ITEM,			// ��ų�� ����ϱ� ���� �ʿ��� �������� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_TOO_MANY_LP_TO_USE_SKILL,				// LP�� 50% ������ ������ �� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_NOT_KNOCKED_DOWN,				// Ÿ���� knock down ���°� �ƴմϴ�.
	GAME_SKILL_RESISTED,								// ��ų�� �����߽��ϴ�.
	GAME_SKILL_TRIED_TO_LEARN_AN_EXISTING_SKILL,		// �̹� ������ �ִ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TRIED_TO_LEARN_WRONG_CLASS_SKILL,		// ������ ���� �ʴ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TOO_HIGH_LEVEL_TO_TRAIN,					// ������ ���Ƽ� ���� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NOT_ENOUGH_ZENNY,						// Zenny�� ���ڶ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NO_EMPTY_SKILL_SLOT,						// �� ��ų ������ �����ϴ�.
	GAME_SKILL_YOU_HAVE_NO_LOWER_LEVEL_SKILL,			// ���׷��̵带 ���ؼ��� ������ ��ų���� �� �ܰ� ���� ��ų�� ������ �־�� �մϴ�.

	GAME_SKILL_ALREADY_MASTERED_SKILL,					// �̹� �ñ��� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_NO_PREREQUISITE_SKILLS_YOU_HAVE,			// ��ų ������ ���� �̹� ���� �־�� �� ��ų�� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_UPGRADE_ONLY_SKILL,		// ���׷��̵�θ� ���� �� �ִ� ��ų�Դϴ�.
	GAME_SKILL_SHOULD_BE_GAINED_BY_YOURSELF,			// ������ ����� �ϴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_BE_GAINED_BY_YOURSELF,				// ������ ��� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_FOR_SOME_REASON,		// �ý��� ������ ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_TARGET_IS_NOT_IN_FRONT_SIDE,		// Ÿ���� ��� �տ� ��ġ�ؾ� �մϴ�.
	GAME_SKILL_YOU_ARE_NOT_IN_BACKSIDE_OF_TARGET,		// ����� �ڿ����� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_IN_FAINT,		// Ÿ���� �ǽ��� �����Դϴ�.
	GAME_SKILL_CAN_BE_CAST_ONLY_ON_PLAYER,		// �÷��̾�Ը� ����� �� �ִ� ��ų�Դϴ�.

	GAME_SKILL_TARGET_IS_NOT_FAINTING,					// Ÿ���� �ǽ��� ���°� �ƴմϴ�.
	GAME_SKILL_NOT_BATTLE_AVAILABLE_LOCATION,			// ��ų ����ڿ� ��� ��� ������ ������ ������ ��ġ�ؾ� �մϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_DAMAGE,				// ������ �޾� ��ų ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_SET_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ������ �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_CANT_USE_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ����� �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_NO_BUFF_TO_DROP_FOUND,					// ������ �� �ִ� ������ �����Ͽ��� �մϴ�.
	GAME_SKILL_ALREADY_TRANSFORMED,						// ������ ���� ���°� �����Ǿ�� ���ο� ������ ����� �� �ֽ��ϴ�.
	GAME_SKILL_NOT_TRANSFORMED,							// ���� ���°� �ƴմϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SUPER_SAIYAN,		// �ʻ��̾��� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_PURE_MAJIN,			// ���� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_SKILL_WHEN_GREAT_NAMEK,			// �Ŵ� ����ũ ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_KAIOKEN,				// ��ձ� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SPINNING_ATTACK,		// ȸ�� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_VEHICLE,				// Ż �� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_NOT_TRANSFORMED,		// �������� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_NOT_ENOUGH_SP_POINT,						// SP POINT �� �����մϴ�.
	GAME_SKILL_ERASE_FAIL,								// ��ų�� ����ٰ� �����߽��ϴ�.
	GAME_BLOCK_ATTACK_NOW,								// ����� ����Ǿ� ����� �� �����ϴ�. 
	GAME_SKILL_HAVE_UPGRADED_SKILL,						// ��ų�� ���׷��̵� �� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_CANT_BE_CAST_ON_YOURSELF,				// �ڽ��� �����ϰ� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_HTB_WHEN_TRANSFORMED,			// ���� �߿��� HTB�� ����� �� �����ϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_TARGET_NEW_STATE,	// 651 // ����� ���°� �ٲ�� ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CASTING_CANCELED_OBJECT_OCCLUSION,       // ĳ�����߿� ������Ʈ�� ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_USE_VEHICLE_WHEN_TRANSFORMED,		// ���� �߿��� Ż ���� �̿��� �� �����ϴ�.
	GAME_SKILL_CANT_USE_WHEN_TRANSFORMED,				// ���� �߿��� �̿��� �� �����ϴ�.
	//-----------------------------------------------------------------
	GAME_CHAR_ONLY_ADULT_CAN_CHANGE_CLASS = 700,				// � ���¿����� ������ �� �� �ֽ��ϴ�.
	GAME_CHAR_NO_AUTHORITY_FOR_CHANGING_CLASS,					// ������ �� �ִ� �ڰ��� ���߰� ���� �ʽ��ϴ�.
	GAME_GM_CANT_DO_THAT_WHEN_YOU_ARE_HIDING,					// 702 // ���� ���¿����� �� �� ���� ����Դϴ�.
	//-----------------------------------------------------------------
	GAME_ITEM_NUM_NULL = 800,		// ������ ��ȣ�� �߸��Ǿ����ϴ�.
	GAME_ITEM_POSITION_FAIL,		// ������ ��ġ���� �߸��Ǿ����ϴ�.	
	GAME_ITEM_OWNER_NOT_SAME,		// ������ �����ְ� �߸��Ǿ����ϴ�.	
	GAME_ITEM_NOT_SAME,             // �������� �߸� �Ǿ����ϴ�.
	GAME_ITEM_OWNER_NULL,			// ������ �����ְ� �����ϴ�.
	GAME_ITEM_STACK_FAIL,           // ������ ������ �߸� �Ǿ����ϴ�.
	GAME_ITEM_NOT_FOUND,			// �������� ã�� �� �����ϴ�.
	GAME_NEEDITEM_NOT_FOUND,		// ������ ���Ž� �ʿ��� �������� Table���� ã�� �� �����ϴ�. [7/17/2008 SGpro]
	GAME_NEEDITEM_NOT_FOUND_INVANTORY,	// ������ ���Ž� �ʿ��� ��ȯ�������� �����ϴ�. [7/17/2008 SGpro]
	GAME_ITEM_BAG_IS_NOT_EMPTY,		// ������ ����� �̵��� �����մϴ�.

	GAME_ITEM_ALREADY_EXIST,        // �������� �����ϹǷ� �̵��� �Ұ� �մϴ�.
	GAME_ITEM_MAX_COUNT_OVER,       // ������ ������ �ʰ��Ͽ����ϴ�.
	GAME_ITEM_STACK_FULL,           // ������ ����á���ϴ�.
	GAME_EQUIP_SLOT_NOT_EMPTY,		// ��� ������ ������� �ʽ��ϴ�.
	GAME_ITEM_CLASS_FAIL,			// ������ ���� ���� Ŭ����Ÿ���� �ƴմϴ�.
	GAME_ITEM_NEED_MORE_LEVEL,		// ���� �������� �������� ������ �� �����ϴ�.
	GAME_ITEM_NEED_MORE_PARAMETER,  // ������ ���밡�� �ɷ�ġ�� �����մϴ�.
	GAME_ITEM_MAX_WATT_OVER,		// Scouter ���������� Max Watt���� �ʰ��Ͽ����ϴ�. 
	GAME_ITEM_INVEN_FULL,			// ������ ����á���ϴ�.
	GAME_ITEM_LOOTING,				// �������� �ݰ� �ֽ��ϴ�.

	GAME_ITEM_UNIDENTIFY,	        // ������ Ȯ���� �ȵǾ��ֽ��ϴ�.
	GAME_ITEM_UNIDENTIFY_FAIL,		// ������ Ȯ�� ����
	GAME_LOOTING_FAIL,			// ������ �������� �����ϴ�.
	GAME_ZENNY_NOT_ENOUGH,			// ���� �����մϴ�.	
	GAME_ITEM_IS_LOCK,				// �������� ��� �����Դϴ�.
	GAME_CHARM_POINT_IS_LOCKED,		// ������ ���� ����Ʈ�� ���� ó���� �Ϸ���� �ʾҽ��ϴ�. ��� �Ŀ� �ٽ� �õ��Ͽ� �ֽʽÿ�.
	GAME_ZENNY_IS_LOCK,				// ������ ��� �����Դϴ�.
	GAME_REPAIR_VALUE_FAIL,			// ���� ������ �������� �ƴմϴ�.
	GAME_REPAIR_NOT_FOUND,			// ���� ������ �������� �����ϴ�.
	GAME_ITEM_YOU_ARE_USING_AN_ITEM,				// �������� ����ϴ� ���Դϴ�.

	GAME_ITEM_NOT_FOR_USE,			// ����� �� �ִ� �������� �ƴմϴ�.
	GAME_ITEM_NOT_BATTLE_AVAILABLE_LOCATION,		// ������ ����ڿ� ��� ��� ������ ������ ������ ��ġ�ؾ� �մϴ�.
	GAME_ITEM_CANT_USE_FOR_SOME_REASON,		// �ý��� ������ �������� ����� �� �����ϴ�.
	GAME_ITEM_NOT_READY_TO_BE_USED,		// �������� ��Ÿ���� ��ٷ��� �մϴ�.
	GAME_ITEM_TOO_LOW_LEVEL_TO_USE_ITEM,		// ������ ���ڶ� �������� ����� �� �����ϴ�.
	GAME_ITEM_NOT_ENOUGH_LP,		// LP�� ������� �ʽ��ϴ�.
	GAME_ITEM_NOT_ENOUGH_EP,		// EP�� ������� �ʽ��ϴ�.
	GAME_ITEM_NOT_ENOUGH_RP_BALL,						// RP ������ ������� �ʽ��ϴ�.
	GAME_ITEM_CASTING_CANCELED,							// ������ ����� ��ҵǾ����ϴ�.
	GAME_ITEM_CANT_USE_NOW,		// ���� �������� ����� �� �ִ� ���°� �ƴմϴ�.

	GAME_ITEM_DUR_ZERO,			// �������� �����Դϴ�.
	GAME_SCOUTER_MAX_OVER,		// ����ġ�� ���� �Ǿ� ��ī���� ���������� ���峵���ϴ�.
	GAME_ITEM_NOT_ENOUGH,		// �������� �������� �ʽ��ϴ�.
	GAME_ITEM_UPGRADE_NO_SUBJECT_ITEM,			// ���׷��̵��� ��� �������� �־� �ֽʽÿ�.
	GAME_ITEM_UPGRADE_NO_HOIPOI_STONE,			// ������ �ϱ� ���ؼ��� ȣ�����̽����� �ʿ��մϴ�.
	GAME_ITEM_UPGRADE_WRONG_ITEM_TYPE,			// ���⳪ ���� ���׷��̵带 �� �� �ֽ��ϴ�.
	GAME_ITEM_UPGRADE_ALREADY_MAX_GRADE,		// �� �̻� ���׷��̵带 �� �� ���� �������Դϴ�.
	GAME_ITEM_UPGRADE_FAIL,     // ������ ���׷��̵� ����
	GAME_ITEM_UPGRADE_FAIL_AND_DEL,     // ���׷��̵� ���з� �������� �ı��Ǿ����ϴ�.
	GAME_BANK_NOT_READY,		// â�� ���� �������� �ʽ��ϴ�.

	GAME_BANK_ALREADY_EXIST,		// â�� �̹� �����մϴ�.
	GAME_SCOUTER_PARTS_NOT_FOUND,	// �ش� ��ī���� ������ ã�� ���߽��ϴ�.
	GAME_SCOUTER_JAMMING,			// ���Ĺ��ط� ���� ǥ���� �� �����ϴ�. 
	GAME_SCOUTER_TARGET_FAIL,	 // ǥ�� ����� �������մϴ�.
	GAME_CHAR_LEVEL_FAIL,		// ������ ���� �ʽ��ϴ�.
	GAME_CHAR_CLASS_FAIL,		// �ش�Ŭ������ ���� �ʽ��ϴ�.
	GAME_CHAR_RACE_FAIL,		// �ش� ������ ���� �ʽ��ϴ�.
	GAME_ZENNY_OVER,			// �ݾ��� �����Ǿ����ϴ�.
	GAME_QUEST_ALREADY_EXIST,	// �̹� �����ϴ� ����Ʈ�Դϴ�.
	GAME_QUEST_COUNT_OVER,		// ���డ���� ����Ʈ���� �ʰ��Ǿ����ϴ�.

	GAME_QUEST_NOT_EXIST,		// �������� �ʴ� ����Ʈ�Դϴ�.
	GAME_ITEM_CREATE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_ITEM_DELETE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_GM_LEVEL_NOT_FOUND,	// GM Level �� ����
	GAME_GM_PUNISH_NOT_FOUND,	// Punish type error
	GAME_SCOUTER_BODY_IS_NOT_EMPTY, // ��ī���� ������ ����� �̵������մϴ�.
	GAME_SCOUTER_PARTS_LEVEL_FAIL,	// ��ī���� ���� ������ ���� �ʽ��ϴ�.
	GAME_TRADE_TARGET_WRONG_STATE,		// ������ ���� Ʈ���̵带 �� �� ���� �����Դϴ�.
	GAME_TRADE_ALREADY_USE,		// Ʈ���̵� ���Դϴ�.
	GAME_TRADE_DENY_USE,		// Ʈ���̵� ���� ���Դϴ�.

	GAME_TRADE_DENY,			// Ʈ���̵带 �����Ͽ����ϴ�.
	GAME_TRADE_REPLY_WAIT_OVER,
	GAME_TRADE_WRONG_STATE,		// Ʈ���̵��ϱ⿡ ������ ���°� �ƴմϴ�.
	GAME_TRADE_ITEM_INVALID,	// Ʈ���̵� �Ұ����� ������ �Դϴ�.
	GAME_TRADE_ALREADY_CLOSE,	// Ʈ���̵尡 �̹� ������ �Դϴ�.
	GAME_TRADE_ALREADY_OPEN,	// Ʈ���̵尡 �̹� �������� �Դϴ�.
	GAME_TRADE_CHANGED_STATE,	// Ʈ���̵� ��ǰ ������ �ٲ�����ϴ�.
	GAME_ITEM_NOT_GO_THERE,		// �ű�� ���� ��ġ�Դϴ�.
	GAME_DRAGONBALL_OBJECT_ARLEADY_USED, // ������ ��� ���Դϴ�.
	GAME_DRAGONBALL_NOT_FOUND,	 // �巡�ﺼ�� ã���� �����ϴ�.

	GAME_DRAGONBALL_REWARD_NOT_FOUND,   // �巡�ﺼ ������ ã�� �� �����ϴ�.
	GAME_DRAGONBALL_TIME_OVER,	// ���ð��� ����Ǿ����ϴ�.
	GAME_DRAGONBALL_SAME_EXIST,		// ���� �� �巡�ﺼ�� �ֽ��ϴ�.
	GAME_QUSET_ITEM_CREATE_COUNT_OVER,// ����Ʈ �κ��丮���� ������ �������� ������ �� �����ϴ�.
	GAME_ITEM_CANT_BE_USED_ON_YOURSELF,					// �ڽ��� �����ϰ� ����� �� ���� �������Դϴ�.
	GAME_ITEM_TYPE_NOT_MISMATCHED,	// ������ Ÿ���� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_ALREADY_EXIST,	// ���� �����ǰ� �̹� ���� �մϴ�.	
	GAME_ITEM_RECIPE_NOT_FOUND,		// �ش� �����ǰ� ���� ���� �ʽ��ϴ� .	
	GAME_ITEM_RECIPE_REGISTER_PROFESSION,	// �ش� ������ �ͽ� ������ ���� �����Ͽ��� �մϴ�.
	GAME_ITEM_RECIPE_LEVEL_MISMATCHED,	// �ش� ������ �����Ƿ����� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_TYPE_MISMATCHED,	// �ش� ������ ������ Ÿ���� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_REGISTER_FAIL,		// ������ ������ ��Ͽ� �����߽��ϴ�.
	GAME_ZENNY_LOOTING,					// ���ϸ� �ݰ� �ֽ��ϴ�.
	GAME_ITEM_RECIPE_REGISTER_PROFESSION_FAIL,	// ������ �ͽ� ������ �߸��Ǿ����ϴ�.
	GAME_SCOUTER_MAIN_PARTS_NOT_FOUND,	// ��ī���� ���� ������ ã�� ���߽��ϴ�.
	GAME_ITEM_HOIPOIMIX_FARE_NOT_SET,	// ȣ�����̸ӽŻ��ᰡ ���õǾ����� �ʽ��ϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_CAN_NOT_SET,	// ȣ�����̸ӽŻ��� ������ ĳ���ӽŸ� �����մϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_RATE_FAIL,	// ȣ�����̸ӽŻ��ᰡ ������ �ʰ� �Ǿ����ϴ�.
	GAME_ITEM_CANNOT_BUY_NOW,			// ������ �� �ִ� �������� �ƴմϴ�.

	// warning! current enum number is 898. -> ������ ������ 3000���뿡�� ���� �߰�.
	// ���⿡ �߰����� ������~ 900�̶� ���Ŀ�~

	//-----------------------------------------------------------------
	GAME_GM_TOOL_SUCCESS = 900,			// GM TOOL �۾��� �����߽��ϴ�.
	GAME_GM_TOOL_FAIL,					// GM TOOL FAIL
	GAME_GM_TOOL_LOGIN_PASS_FAIL,		// GM TOOL LOGIN PASSWORD MISMATCHED
	GAME_GM_TOOL_ACCOUNT_EXIST,			// �̹� �����ϴ� ���̵� �Դϴ�.
	GAME_GM_TOOL_PASS_NULL,				// �н����带 �������� �ʾҽ��ϴ�.
	GAME_GM_TOOL_GROUP_NOT_FOUND,		// �׷��� �����ϴ� �׷��� ���� ����ʽÿ�.
	GAME_GM_TOOL_GROUP_ALREADY_EXIST,	// 
	GAME_GM_TOOL_GROUP_NEED_ADMIN,
	GAME_GM_TOOL_USER_NOT_FOUND,		// �ش� ������ �������� �ʽ��ϴ�.
	GAME_GM_TOOL_LOGIN_DUPLICATE,		// �ߺ� �α���
	GAME_GM_TOOL_CHARACTER_IS_NOT_KICK,	// ű ���°� �ƴϴ�.
	GAME_GM_TOOL_CHARACTER_EXIST,		// ĳ���Ͱ� �����մϴ�.
	GAME_GM_TOOL_INVALID_TOOL_VERSION,	// �� ������ ���� �ʽ��ϴ�.
	GAME_GM_TOOL_INVALID_IP_ADDRESS,	// �ΰ����� ���� IP�Դϴ�.
	GAME_GM_TOOL_NOTICE_OVER,			// �������� �ִ밹���� �ʰ��߽��ϴ�.
	GAME_GM_TOOL_GUILD_NOT_FOUND,		// ��带 ã�� ���߽��ϴ�.
	GAME_GM_TOOL_CHARACTER_NOT_EXIST,	// ĳ���Ͱ� �������� �ʽ��ϴ�.
	GAME_GM_TOOL_SERVER_CANT_BE_TURNED_ON_BY_GM_TOOL,		// GM Tool�� ������ �� ���� �����Դϴ�.
	GAME_GM_TOOL_SERVER_CANT_BE_TURNED_OFF_BY_GM_TOOL,		// GM Tool�� ������ �� ���� �����Դϴ�.
	GAME_GM_TOOL_WRONG_SERVER_TO_TURN_ON,					// ������ ������ �߸� �����Ͽ����ϴ�.
	GAME_GM_TOOL_WRONG_SERVER_TO_TURN_OFF,					// ������ ������ �߸� �����Ͽ����ϴ�.
	GAME_GM_TOOL_SERVERFARMID_INVALID,						// ServerFarmID�� Invalid�Դϴ�.
	GAME_GM_TOOL_AGENTSERVER_NORUN,
	GAME_GM_TOOL_RANK_BATTLE_POINT_NOT_FOUND, // ��ũ ��Ʋ ������ ���� ĳ���� �Դϴ�.
	GAME_GM_TOOL_ACCOUNT_NOT_EXIST,							// �������� �ʴ� ���̵� �Դϴ�.

	//-----------------------------------------------------------------
	GAME_SKILL_SLOT_FAIL = 1000,
	GAME_SKILL_ID_NULL,
	GAME_SKILL_OWNER_NULL,
	GAME_SKILL_SAME_EXIST,
	GAME_SKILL_NOT_FOUND,
	GAME_ITEM_NOT_PROPER_PLACE_TO_USE,						// �������� ����ϱ⿡ ������ ��Ұ� �ƴմϴ�.
	GAME_ITEM_YOU_HAVE_NO_RELATED_QUEST_TO_USE,				// �����۰� ���õ� ����Ʈ�� ���� ���� �ʽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_SHOP_NOT_FOUND = 1100,
	GAME_SHOP_SO_FAR,
	GAME_SHOP_NOT_CLOSED,					// ������ ���������Դϴ�.
	GAME_SHOP_ITEM_INVALID,					// �ȼ� ���� ������ �Դϴ�.
	//-----------------------------------------------------------------
	GAME_MOVE_CANT_GO_THERE = 1200,		// �� �� ���� ��ġ�Դϴ�
	GAME_WORLD_NOT_EXIST,				// �������� �ʴ� ���� �Դϴ�.
	GAME_MOVE_CANT_ALLOWED_ENTER,		// ������ ������ �ʽ��ϴ�.
	GAME_WORLD_CANT_MOVE_AGAIN,// ���忡 ������ �� �� ���� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PARTY_ALREADY_IN_PARTY = 1300,						// �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PLAYER_IS_INVITING_YOU,				// �ٸ� �÷��̾ �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PARTY_IS_INVITING_YOU,				// �ٸ� ��Ƽ�� �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_NOT_PROPER_PARTY_NAME_LENGTH,				// ��Ƽ �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_PARTY_PARTY_NAME_HAS_INVALID_CHARACTER,			// ��Ƽ �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_PARTY_NOT_CREATED_FOR_SOME_REASON,					// �ý��� ������ ��Ƽ�� �������� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_ARE_NOT_IN_PARTY,						// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_PARTY_ONLY_ALLOWED_TO_PARTY_LEADER,				// ��Ƽ ������ ����� �� �ִ� ����Դϴ�.
	GAME_PARTY_NOT_AVAILABLE_OPERATION_RIGHT_NOW,			// ��Ƽ�� �����ϰ� �ִ� �۾��� ������ �����մϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER,							// �������� �ʴ� �÷��̾��Դϴ�.

	GAME_PARTY_TARGET_ALREADY_IN_PARTY,						// ������ �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_TARGET_ALREADY_HAS_INVITATION,				// ������ �̹� ��Ƽ �ʴ븦 ���� �����Դϴ�.
	GAME_PARTY_NO_ROOM_FOR_NEW_MEMBER,						// �� �̻� ����� ���� �� �����ϴ�.
	GAME_PARTY_MEMBER_IS_ALREADY_REGISTERED_TIMEQUEST,		// ������ Ÿ�Ӹӽ� ����Ʈ�� �̹� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_YOU_HAVE_NO_INVITATION,						// ����� ��Ƽ�κ��� �ʴ븦 ���� ���°� �ƴմϴ�.
	GAME_PARTY_INVITOR_PLAYER_IS_IN_A_PARTY,				// ����� �ʴ��ߴ� �÷��̾ ã�� �� �����ϴ�.
	GAME_PARTY_NO_SUCH_A_PARTY,								// ��Ƽ�� �����ϱ� �ʽ��ϴ�.
	GAME_PARTY_COULDNT_JOIN_FOR_SOME_REASON,				// �ý��� ������ ��Ƽ�� ������ �� �������ϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER_IN_THE_PARTY,				// ��Ƽ�� �������� �ʴ� �÷��̾��Դϴ�.
	GAME_PARTY_COULDNT_KICK_OUT_FOR_SOME_REASON,			// �ý��� ������ ����� ������ Ż���ų �� �������ϴ�.

	GAME_PARTY_CANT_KICK_OUT_HIMSELF,						// �ڱ� �ڽ��� ������ Ż���ų �� �����ϴ�.
	GAME_PARTY_YOU_ARE_ALREADY_A_LEADER,					// �̹� �ڽ��� ��Ƽ �����Դϴ�.
	GAME_PARTY_COULDNT_ASSIGN_A_LEADER_FOR_SOME_REASON,		// �ý��� ������ ����� ������ ������ �� �������ϴ�.
	GAME_PARTY_COULDNT_BE_DONE_FOR_SOME_REASON,				// �ý��� ������ ��û�� ó���� �� �������ϴ�.
	GAME_PARTY_WRONG_CHARM_INVENTORY_SPECIFIED,				// ���� �κ��丮�� �߸� �����Ǿ����ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_OPEN,						// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_CLOSED,					// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_NOT_EMPTY,			// ���� �κ��丮 ������ ��� ���� ���� �����Դϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_EMPTY,				// ���� �κ��丮 ������ ��� �ִ� �����Դϴ�.
	GAME_PARTY_ZENNY_IS_LOCKED_RIGHT_NOW,					// ���� �κ��丮�� ���ϸ� ������ �� ���� �����Դϴ�.

	GAME_PARTY_NO_SUCH_A_VICTIM_ITEM,						// �������� �ʴ� ���� �������Դϴ�.
	GAME_PARTY_UNIDENTIFIED_VICTIM_ITEM,					// ���� �������� ������ ���� ���� �����Դϴ�.
	GAME_PARTY_THE_ITEM_IS_LOCKED,							// �������� ������ �� �����ϴ�.
	GAME_PARTY_VICTIM_ITEM_IS_NOT_YOURS,					// ����� ����� ���� �������� �ƴմϴ�.
	GAME_PARTY_CANT_UNREGISTER_CHARM_DUE_TO_VITIM,			// �̹� ����� ������ �־ ������ �ٽ� ������ �� �����ϴ�.
	GAME_PARTY_YOU_DONT_BELONG_TO_THE_PARTY,				// ����� ��Ƽ�� ���� ���� ���� �� �����ϴ�.
	GAME_PARTY_VICTIM_ZENNY_HASNT_CHANGED,					// ���� ������ ����� ������ ���� �ٲ��� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_DONT_HAVE_THAT_MUCH_ZENNY,				// �׸�ŭ�� ���ϸ� ������ ���� �ʽ��ϴ�.
	GAME_PARTY_YOU_HAVENT_REGISTERED_VICTIM_ZENNY,			// ���ϸ� ���� ������ ����� ���� �����ϴ�.
	GAME_PARTY_TOO_MUCH_VICTIM_ZENNY_TO_UNREGISTER,			// ����� ������ �纸�� ���� ���� ���ϸ� ���������� �߽��ϴ�.

	GAME_PARTY_ONLY_LEADER_CAN_REGISTER_CHARM,				// ������ ��Ƽ ������ ����� �� �ֽ��ϴ�.
	GAME_PARTY_ONLY_CHARM_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_SAME_CHARM_ALREADY_HAS_BEEN_REGISTERED,		// �̹� Ȱ��ȭ�Ǿ� �ִ� ���� �������Դϴ�.
	GAME_PARTY_ONLY_EQUIP_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� ������ �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_CHARM_ITEM_HASNT_BEEN_REGISTERED,			// ���� ������ ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_AN_ITEM_OF_IMPROPER_TYPE,		// ���� ���Կ� ������ �ƴ� �������� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_UNKNOWN_CHARM_ITEM,			// ���� ���Կ� �� �� ���� ������ ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_ITEMS_DONT_SATISFY_THE_CONDITION,			// ���� �������� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_ZENNY_DOESNT_SATISFY_THE_CONDITION,			// ���ϰ� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_CHARM_POINT,		// ����� ���� ����Ʈ���� ���� ����Ʈ�� ���� ��Ƽ���� �ֽ��ϴ�.

	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_ZENNY,				// ����� ���Ϻ��� ���� ���ϸ� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_CHARM_POINT_IS_IN_TRANSACTION,		// ���� ����Ʈ�� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_IN_TRANSACTION,				// ���ϸ� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_SATISFY_THE_CONDITION,			// ���� ��� ������ ������Ű�� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_BUFF_REGISTERED_ALREADY,				// �̹� ��ϵ� ���� ������ �ֽ��ϴ�.
	GAME_PARTY_NO_CHARM_BUFF_REGISTERED,					// ��ϵ� ���� ������ �����ϴ�.
	GAME_PARTY_UNKNOWN_ZENNY_LOOTING_METHOD,				// �߸��� ���� �й� ����Դϴ�.
	GAME_PARTY_UNKNOWN_ITEM_LOOTING_METHOD,					// �߸��� ������ �й� ����Դϴ�.
	GAME_PARTY_CANT_CHANGE_LOOTING_METHOD_YET,				// �ٽ� ����ǰ �й� ����� �ٲ� �� ���� ������ �ð��� �ʿ��մϴ�.
	GAME_PARTY_INVALID_INVENTORY_SLOT_INDEX,				// ��Ƽ �κ��丮�� ������ ��ġ�� �߸� �����Ǿ����ϴ�.

	GAME_PARTY_TOO_MANY_CONTRIBUTION_POINTS_TO_INVEST,		// ������ �� �ִ� �⿩���� ������ �Ѿ����ϴ�.
	GAME_PARTY_NOBODY_CANT_RECEIVE_ITEM_RIGHT_NOW,			// �������� ���� �� �ִ� ����� �ƹ��� �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_INVENTORY,					// �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_PARTY_INVENTORY,			// ��Ƽ �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_MEMBER_IS_TOO_FAR,							// ����� �ʹ� �ָ� ������ �ֽ��ϴ�. ����Ʈ ���� �Ҷ� ��� by niam
	GAME_PARTY_INVITING_IS_NOT_ALLOWED,						// �� ��Ƽ������ �ʴ밡 ������ �ʽ��ϴ�.
	GAME_PARTY_LEAVING_IS_NOT_ALLOWED,						// �� ��Ƽ������ Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_KICKING_OUT_IS_NOT_ALLOWED,					// �� ��Ƽ������ ���� Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_APPOINTING_A_LEADER_IS_NOT_ALLOWED,			// �� ��Ƽ������ ��Ƽ�� �Ӹ��� ������ �ʽ��ϴ�.
	GAME_PARTY_SHARETARGET_NOTFINDOBJECT,					// �ش� ������Ʈ�� �����ϴ� [3/28/2008 SGpro]

	GAME_PARTY_SHARETARGET_SLOTID_FAIL,						// ����Ÿ�� ����ID�� �߸��Ǿ����ϴ�[3/28/2008 SGpro]
	GAME_PARTY_ONLY_EQUIP_ITEM_ALLOWED_FOR_CHARM_POINT,		// ���� ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_IDENTIFIED_ITEM_NEEDED_FOR_CHARM_POINT,		// ������ ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_DUNGEON_IN_PLAYER_FOUND,						// 1372 // ������ ���� �����ִ� ĳ���Ͱ� �ֽ��ϴ�. 
	GAME_PARTY_DICE_FAIL,									// ��Ƽ �ֻ��� ��� ����
	GAME_PARTY_INVEN_ITEM_EXIST,							// ��Ƽ�κ��� �������� �����ֽ��ϴ�.
	GAME_PARTY_INVEN_INVEST_ZENNY_NOT_ENOUGH,				// ��Ƽ�κ��� ������ ���� �����մϴ�.
	GAME_PARTY_INVEN_LOCKED,								// ��Ƽ�κ��� �����ϴ�.
	GAME_PARTY_ITEM_DICE_USING_NOW,							// ��Ƽ ������ ���̽��� ������Դϴ�.
	GAME_PARTY_INVEN_ITEM_NON_EXIST,						// ��Ƽ�κ� �ش� ���Կ� ������ �����ϴ�.

	GAME_PARTY_ITEM_DICE_NOT_USING_NOW,						// ��Ƽ ������ ���̽��� �� ������Դϴ�.
	GAME_PARTY_DUNGEON_MIN_PLAYER_FAIL,						// ��Ƽ ������ �ּ��ο��� �����մϴ�.
	GAME_PARTY_DUNGEON_OUT_RESERVED,						// ��Ƽ ���� ������ ���� NTL_MIN_DUNGEON_PARTYOUT_TIME ���ҽ��ϴ�..(���ǵ� ���� �ٲ�� �ݵ�� ��ȹ�� GUI ����ڿ��� �˷� �ּ���)
	GAME_PARTY_INVEN_DISTRIBUTE_METHOD_NOT_MATCH,			// �й����� ���� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_LOCK,						// ��Ƽ ����� ���ϰ� ��� ���°� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_NOT_SAME,								// ��Ƽ�κ��� ����� �ٸ��ϴ�.
	GAME_PARTY_INVEN_LOCK_FIRST,							// ��Ƽ�κ��� �����ֽ��ϴ�. ���� �ݾ��ֽʽÿ�.
	GAME_PARTY_INVEN_UNDER_INVEST,							// ��Ƽ�κ��� ���ڵ� �ִ�ݾ� ���� ���ƾ��մϴ�.
	GAME_PARTY_DUNGEON_ENTER_PARTY_FAIL,					// ��Ƽ������ ���÷��� ��Ƽ�� �����Ͻʽÿ�.
	GAME_PARTY_DUNGEON_IN_CHANGE_DIFF_NOW,					// ��Ƽ�����ȿ��� ���̵� ������ �Ұ����մϴ�.

	GAME_PARTY_CANT_INVITE_YOURSELF,						// �ڱ� �ڽ��� ��Ƽ�� �ʴ��� �� �����ϴ�.
	//-----------------------------------------------------------------
	GAME_HTB_NO_HTB_RESULT = 1400,							// ������ HTB�� �����ϴ�
	GAME_HTB_CANT_FORWARD_ANYMORE,							// ���̻� ������ HTB�ܰ谡 �����ϴ�.
	GAME_HTB_NOT_ENOUGH_RP_BALL,							// RP ������ ������� �ʽ��ϴ�.
	GAME_HTB_YOU_ALREADY_USED_RP_BALL,						// �̹� RP ������ ����� �����Դϴ�.
	GAME_HTB_YOU_HAVE_NO_RELATION_WITH_HTB,					// 1404 // HTB�� ���� ���� �����Դϴ�.

	GAME_WORLD_ENTER_NEED_LOW_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_HIGH_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_ITEM, // �ش� ������ �����ϱ����� �ʿ�  �������� �����ϴ�.

	GAME_FREEBATTLE_TARGET_HAS_NO_MATCH, // ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_WRONG_PLACE, // ������ �� �� ���� �����Դϴ�.
	GAME_FREEBATTLE_ALREADY_HAS_MATCH, // �̹� �������Դϴ�.
	GAME_FREEBATTLE_TARGET_ALREADY_HAS_MATCH, // �̹� �������� ����Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_TIME_REMAIN, // ���� ���� ��� �ð��Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_DENIED, // ���� ��û�� �������߽��ϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_TIME_DENIED, // ���� ��û�� ������ ���� �ʾ� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_CHALLENGE_WAIT_TIME_DENIED, // ���� ��û�� ���� ������ ���� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_ERROR_HAS_NO_MATCH, // ����(�����ڵ�) - ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_HAS_NO_MATCH, // ����(�����ڵ�)  - ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_WRONG_PEER, // ����(�����ڵ�) - �߸��� ���� ����� ������ �ֽ��ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_WRONG_PEER, // ����(�����ڵ�) - ����� �߸��� ���� ����� ������ �ֽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_WORLD_ENTER_NEED_REPUTATION, // �ش� ������ �����ϱ����� �ʿ� ���� �����ϴ�.
	GAME_WORLD_NOT_FOUND,			  // �ش� ������ ã�� �� �����ϴ�.

	GAME_WORLD_ENTER_DISAPPROVAL,	 // �ش� ������ ������ �� �����ϴ�.

	GAME_SCOUTER_TARGET_SELF_FAIL,	 // �ڱ� �ڽ��� ������� �Ұ����մϴ�.
	//	Game_ENTER_GAME_NO_CHARACTER_FOUND,
	//	Game_ENTER_GAME_WRONG_CHARACTER_POSITION,
	//	Game_NO_SUCH_AN_ITEM,
	//	Game_TRIED_TO_EQUIP_WRONG_ITEM,
	//	Game_TRIED_TO_EQUIP_ITEM_INTO_WRONG_SLOT,
	//	Game_TRIED_TO_TAKE_OFF_ITEM_FROM_WRONG_SLOT,
	//	Game_TRIED_TO_TAKE_OFF_WRONG_ITEM,
	//	Game_NO_SPACE_TO_HOLD_ITEM_TAKEN_OFF,
	//	Game_WRONG_DESTINATION_IN_INVENTORY,
	//	Game_CAPSULE_CANT_BE_PUT_INTO_CAPSULE,
	//	Game_ONLY_CAPSULE_CAN_BE_PUT_THERE

	//////////////////////////////////////////////////////////////////////////
	//
	// Trigger system ���� �޽�����
	//
	//////////////////////////////////////////////////////////////////////////

	GAME_TS_WARNING_BEGIN = 1500,						// Trigger warning message ����

	GAME_TS_WARNING_NOT_SATISFY_REWARD_CONDITIONS = 1500,	// ���� ���� �� �ִ� ������ �������� ���մϴ�.
	GAME_TS_WARNING_MUST_SELECT_ONE_SEL_REWARD,		// ���� ������ �����մϴ�. �ݵ�� �ϳ��� ���ú����� �����ؾ� �մϴ�.
	GAME_TS_WARNING_PROCESSING_PRE_CONFIRM_REQ,		// ���� ���� ��û�� ó�����Դϴ�. (����)
	GAME_TS_WARNING_NOW_TIME_WAIT,					// ���� ���� ��û�� ó�����Դϴ�. (�ð�)
	GAME_TS_WARNING_OVERFLOW_MAX_TS_NUM,			// ���డ���� �ִ� Ʈ���� ������ �Ѿ����ϴ�.

	GAME_TS_WARNING_SYSTEM_WAIT,					// �ٸ� �ý��۰� �浹�� �Ͼ ���. ��� ��ٷ� �ּ���.
	GAME_TS_WARNING_INVENTORY_IS_LOCK,				// ������ �κ��丮�� lock�� �ɷ� ����
	GAME_TS_WARNING_INVENTORY_IS_FULL,				// ������ �κ��丮�� ����á��
	GAME_TS_WARNING_QUEST_INVENTORY_IS_FULL,		// ����Ʈ �κ��丮�� ���� á��
	GAME_TS_WARNING_INVALID_QUEST_ITEM_DELETE_COUNT,// ����Ʈ �������� ���� ��û ������ Ʋ��
	GAME_TS_WARNING_REWARD_FAIL,					// ������ ���� ����(�Ƹ� �� �޽����� ������ ��������)
	GAME_TS_WARNING_EQUIP_SLOT_NOT_EMPTY,			// ��� ������ ������� �ʽ��ϴ�.
	GAME_TS_WARNING_EQUIP_SLOT_LOCK,				// ��� ������ ����ֽ��ϴ�.
	GAME_TS_WARNING_CLASS_CHANGE_CLASS_FAIL,		// ���� Ŭ������ �ٸ�
	GAME_TS_WARNING_CLASS_CHANGE_LEVEL_FAIL,		// ���� ������ �ȵ�
	GAME_TS_WARNING_NOT_YET_PROCESSED,				// ó������ �ʾ���
	GAME_TS_WARNING_ROLLBACK,						// ���� ó�� �Ͽ����� �ѹ��Ŵ
	GAME_TS_WARNING_ROLLBACK_FAIL,					// �ѹ��� ������
	GAME_TS_WARNING_ESCORT_EXCEED_MEMBER,			// ��� �ʰ�
	GAME_TS_WARNING_ESCORT_NOT_SHARED,				// ���� ��尡 �ƴ�
	GAME_TS_WARNING_ESCORT_TRIGGER_TYPE_WRONG,		// Ʈ���� Ÿ���� �ٸ�
	GAME_TS_WARNING_ESCORT_TRIGGER_ID_WRONG,		// Ʈ���� ���̵� �ٸ�
	GAME_TS_WARNING_ESCORT_PARTY_WRONG,				// ��Ƽ�� �ٸ�
	GAME_TS_WARNING_ESCORT_ALREADY_EXIST,			// �̹� ��ϵǾ� ����
	GAME_TS_WARNING_TMQ_COUPON_NOT_ENOUGH,			// TMQ���� ������ ������

	GAME_TS_WARNING_WPS_ALREDY_USED_BY_OTHER_PLAYER,// �̹� �ٸ� ������ �������Դϴ�.
	GAME_TS_WARNING_WPS_CAN_NOT_JOIN_NOW,			// ������ ���� �� �� �����ϴ�.

	GAME_TS_WARNING_CAN_NOT_FIND_VISIT_EVT,			// ���õ� �湮 �̺�Ʈ�� �����ϴ�. for visit event
	GAME_TS_WARNING_ALREADY_VISITED,				// �̹� �Ϸ��߽��ϴ�. for visit event
	GAME_TS_WARNING_WRONG_CONDITION,				// ���� ������ ���� �ʽ��ϴ�.
	GAME_TS_WARNING_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_WARNING_DEL_FORBIDDENDEL_QUEST_ITEM,	// ����� ���� ����Ʈ �������Դϴ�.
	//-----------------------------------------------------------------
	GAME_TS_WARNING_END = 1700,							// Trigger warning message ����

	GAME_TS_ERROR_BEGIN = 1700,							// Trigger error message ����

	GAME_TS_ERROR_RUN_ERROR = 1700,	// Ʈ���� ���� ����
	GAME_TS_ERROR_CS_SCRIPT_MISSMATCH,				// ������ �����ؾ��� �����̳� Ÿ���� CS ���� ��ġ���� �ʽ��ϴ�.
	GAME_TS_ERROR_NO_IMP_CONT_TYPE,					// �������� ���� �����̳� Ÿ���� ���Ǿ����ϴ�.
	GAME_TS_ERROR_CANNOT_CREATE_TS_OBJECT,			// Ʈ���� ������Ʈ ���� ����.
	GAME_TS_ERROR_CANNOT_FIND_TID,					// Ʈ���Ÿ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_TCID,					// �����̳ʸ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_PROGRESS_REPEAT_QUEST,		// �ݺ� ����Ʈ�� ������ �ѹ��� ������ �� �ֽ��ϴ�


	GAME_TS_ERROR_SYSTEM,							// �Ϲ����� �ý��ۻ��� ����[����]
	GAME_TS_ERROR_TRIGGER_SYSTEM,					// Trigger System ���� ������ �� ���
	GAME_TS_ERROR_QUERY_SERVER,						// ���� ���� ����
	GAME_TS_ERROR_CANNOT_FIND_ITEM_TBLIDX,			// ���̺��� �������� ã���� ����
	GAME_TS_ERROR_CANNOT_FIND_SKILL_TBLIDX,			// ��ų�� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_LEARN_SKILL,				// ��ų�� ��� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_ADD_QUEST_EVENT_DATA,		// �̺�Ʈ �������� �̺�Ʈ�� ����� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CREATE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���.
	GAME_TS_ERROR_DELETE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���
	GAME_TS_ERROR_CANNOT_FIND_PC,					// PC�� ã�� �� ����
	GAME_TS_ERROR_TRIGGER_OBJECT_NOT_EXIST,			// �������� �ʴ� Ʈ���� ������Ʈ �Դϴ�.
	GAME_TS_ERROR_TRIGGER_OBJECT_INVALID_FUNCFLAG,	// ����� �ùٸ��� ���� Ʈ���� ������Ʈ�Դϴ�.
	//-----------------------------------------------------------------
	GAME_TS_ERROR_END = 1900,							// Trigger error message ����
	//-----------------------------------------------------------------
	GAME_PET_CANT_MAKE_MORE_SUMMON_PET = 2000,			// �� �̻� ��ȯ���� �θ� �� �����ϴ�.
	GAME_PET_CANT_MAKE_MORE_ITEM_PET,					 // �� �̻� ������ ���� �θ� �� �����ϴ�.
	GAME_PET_COULDNT_BE_DONE_FOR_SOME_REASON,			// �ý��� ������ ��û�� ó���� �� �����ϴ�.
	GAME_PET_TARGET_IS_NOT_SPAWNED,						// ����� ��ȯ�Ǿ� ���� �ʽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_GUILD_NO_GUILD_MANAGER_NPC_FOUND = 2100,			// ��� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_GUILD_MANAGER_NPC,						// ��� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_GUILD_MANAGER_IS_TOO_FAR,					// ������ ��� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NEED_MORE_ZENNY_FOR_NEW_GUILD,				// ��� ������ ���ؼ��� ���ϰ� �� �ʿ��մϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME_LENGTH,				// ��� �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_GUILD_GUILD_NAME_HAS_INVALID_CHARACTER,			// ��� �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME,						// ��� �̸��� �������� �ʽ��ϴ�.
	GAME_GUILD_SAME_GUILD_NAME_EXIST,						// ���� ��� �̸��� �����մϴ�.
	GAME_GUILD_NOT_EXIST,									// �ش� ��尡 �������� �ʽ��ϴ�.
	GAME_GUILD_NON_EXISTING_GUILD_FUNCTION,					// �� �� ���� ��� ����Դϴ�.

	GAME_GUILD_ALREADY_HAS_GUILD_FUNCTION,					// �̹� ������ �ִ� ��� ����Դϴ�.
	GAME_GUILD_NEED_PREREQUISITE_GUILD_FUNCTION,			// �� �ܰ� ���� ��� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_NEED_MORE_GUILD_POINT,						// �� ���� ��� ����Ʈ�� �ʿ��մϴ�.
	GAME_GUILD_NEED_MORE_ZENNY,								// �� ���� ���ϰ� �ʿ��մϴ�.
	GAME_GUILD_NEED_LEVEL_MORE,								// ������ �����մϴ�.
	GAME_GUILD_GIVE_ZENNY_NOT_MATCHED,						// ��� ����Ʈ�� ������ؼ��� 1000���� ������ �������� 1000 �̻��̿��� �մϴ�.
	GAME_GUILD_NO_GUILD_FOUND,								// ��忡 ���ԵǾ� ���� �ʽ��ϴ�.
	GAME_GUILD_MARK_ARLEADY_CREATED,						// ��帶ũ�� �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_MARK_NOT_CREATED,							// ��帶ũ�� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_NEED_DOJO_NOT_FOUND,							// ������ ã�� �� �����ϴ�.

	GAME_GUILD_MAKE_DOJO_ALREADY_TAKEN,						// �̹� ���İ� ������ �����ϰ� �־� ������ ������ �� �����ϴ�.
	GAME_GUILD_NEED_GUILD_FUNCTION,							// ����� ����� �����ϴ�. ���ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_NO_DOJO_MANAGER_NPC_FOUND,					// ���� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_DOJO_MANAGER_NPC,						// ���� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_DOJO_MANAGER_IS_TOO_FAR,						// ������ ���� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NON_EXISTING_DOJO_FUNCTION,					// �� �� ���� ���� ����Դϴ�.
	GAME_GUILD_MAKE_DOJO_NOT_TAKEN,							// ������ ������ �����ϴ�.
	GAME_GUILD_DOGI_NOT_CREATED,							// ���� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_DOGI_ARLEADY_CREATED,						// ������ �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_ALREADY_HAS_DOJO_FUNCTION,					// �̹� ������ �ִ� ���� ����Դϴ�.

	GAME_GUILD_NEED_PREREQUISITE_DOJO_FUNCTION,				// �� �ܰ� ���� ���� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_FOUND,					// ȣ�����̶� �������� ã�� ���߽��ϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_MATCHED,					// ȣ�����̶� �������� �ƴմϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_COUNT_FAIL,					// ȣ�����̶� ������ ������ �����մϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE,				// ���� ��Ż ��û��尡 �̹� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_A_PARTY_LEADER,				// ������ ������ ���� �ְ������� �����մϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_OWNNER,						// ������ ������ �ƴմϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_STATUS_FAIL,			// ������Ż�� ��û���� ���°� �ƴմϴ�. 
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE_DOJO,			// ������ ������ ���Ĵ� ��Ż���� ��û�� �� �����ϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_REJECT_STATUS_FAIL,			// ������Ż�� ��û�źΰ��� ���°� �ƴմϴ�. 

	GAME_GUILD_DOJO_NOT_FOUND_TABLE,						// �������̺��� ã���� �����ϴ�. 
	GAME_GUILD_DOJO_NEED_FUNCTION,							// ���弳�� ������ �����ϴ�. ����ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_DOJO_SCRAMBLE_MAX_COUNT_OVER,				// ������Ż���� ���� �ִ� �ο� ���� �ʰ� �߽��ϴ�.	
	GAME_GUILD_DOJO_NOT_FOUND,								// �ش� ������ ã�� �� �����ϴ�.	
	GAME_GUILD_DOJO_SELF_SCRAMBLE_FAIL,						// �ڽ��� ���� ���忡 ��Ż���� ��û�Ҽ� �����ϴ�.	
	GAME_GUILD_DOJO_SCRAMBLE_NOT_A_PARTY_LEADER,			// ��Ż���� ��û�� �ְ����� �� �� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_REPUTATION,			// ��Ż���� ��û�ϱ⿡�� ���� ����Ʈ�� ������� �ʽ��ϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_ZENNY,				// ��Ż���� ��û�ϱ⿡�� ������ ���ϰ� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT,				// ��Ż���� �źδ��� ��û�� �� ���� �����Դϴ�. ���� ��û�Ⱓ�� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_ANY_DOJO,			// ���忡 ���� ���� �ʽ��ϴ�.

	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_THAT_DOJO,			// �ش� ���忡 ���� ���� �ʽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT_ONE_TIME,		// ��Ż�� �źδ� �ѹ��� �����մϴ�.
	GAME_GUILD_DOJO_YOU_CANT_ATTACK_YOUR_TEAM_SEAL,			// �ڽ��� ���� ���� ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_SEAL_CANT_BE_ATTACKED,					// ������ ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_TOO_MANY_ATTACKER_ON_SEAL,				// �̹� ���� �÷��̾ ������ �����ϰ� �ֽ��ϴ�.
	GAME_GUILD_YOUR_GUILD_CANT_DO_DOJO_TELEPORT,			// 2155 // �ڷ����� ����� ����� �� ���� ���Ŀ� ���� �ֽ��ϴ�.
	GAME_GUILD_DOJO_FUNCTION_ADD_FIRST,						// ������ ����� ���� �����Ͻ� �� ����� �ּ���. 
	//-----------------------------------------------------------------
	GAME_ROOM_ENTER_EXCEED_MAX_MEMBER_COUNT = 2200,			// �濡 �ο��� ���� á���ϴ�.
	GAME_ROOM_ENTER_EXCEED_MAX_ROOM_COUNT,					// ���̻� ���� ���� �� �����ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_MEMBER,						// �濡 �ο��� �� �ʿ� �մϴ�.
	GAME_ROOM_ENTER_TOO_LOW_LEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_TOO_HIGHTLEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ITEM,					// �濡 �����ϱ����� �ʿ� �������� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ZENNY,					// �濡 �����ϱ����� ���ϰ� �����մϴ�.
	GAME_ROOM_ENTER_ROOM_NOT_EXIST,							// ���� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_ROOMMANAGER_NOT_EXIST,					// �Խ����� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_PARTY_MEMEBER,				// ��Ƽ����� �� �ʿ��մϴ�.
	GAME_ROOM_ENTER_NOT_MATCH_MEMBER,						// ���� ����� �ƴմϴ�.
	GAME_ROOM_ENTER_NOT_WAIT_STATE,							// ��� ���°� �ƴմϴ�.
	GAME_ROOM_ENTER_FAIL,									// ������ �õ��� �����Ͽ����ϴ�
	GAME_ROOM_LEAVE_LIMIT_TIME_ELAPSED,						// ���뿡�� ������ ���� �ð� �Դϴ�
	GAME_ROOM_LEAVE_FAIL,									// ���� ������ ����
	GAME_ROOM_NOT_OWNER,									// ���� �����ڰ� �ƴմϴ�.
	GAME_ROOM_CAN_NOT_FIND_PARTY_MEMBER,					// ��Ƽ����� ã�� �� �����ϴ�.

	GAME_RANKBATTLE_NOR_REGISTERED,							// ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_NOW,						// ��� �� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_IN_MATCH,					// ����߿��� ����� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_ARENA,						// ������� ã�� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_OPPONENT,					// ��븦 ã�� �� �����ϴ�.
	GAME_RANKBATTLE_MEMBER_ALREADY_JOINED_RANKBATTLE,		// ��Ƽ���� �̹� ��ũ��Ʋ ���Դϴ�.
	GAME_RANKBATTLE_ARENA_IS_FULL,							// ����ִ� ������� �����ϴ�.
	GAME_RANKBATTLE_OBJECT_IS_TOO_FAR,						// �ʹ� �ָ� ������ �ֽ��ϴ�.

	GAME_MATCH_CAN_NOT_USE_SKILL_IN_THIS_WORLD,				// ���� ���忡���� ����� �� ���� ��ų�Դϴ�.
	GAME_MATCH_CAN_NOT_USE_SKILL_IN_OUTOFAREA,				// ����϶��� ��ų�� ����� �� �����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_RANKBATTLE,	// ��ũ��Ʋ ���϶����� ��Ƽ���� ���� �� �����ϴ�.


	//-----------------------------------------------------------------
	GAME_TIMEQUEST_WORLD_NOT_FOUND = 2300,					// Ÿ�Ӹӽ� ����Ʈ�� �ش��ϴ� ���带 ã�� �� �����ϴ�
	GAME_TIMEQUEST_ROOM_NOT_FOUND,							// Ÿ�Ӹӽ� ����Ʈ ������ ã�� �� �����ϴ�
	GAME_TIMEQUEST_ALREADY_JOINED,							// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� �����ϰ� �ֽ��ϴ�
	GAME_TIMEQUEST_HAVE_NO_JOIN_ROOM,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �����ϰ� ���� �ʽ��ϴ�
	GAME_TIMEQUEST_CANT_MAKE_PARTY,							// Ÿ�Ӹӽ� ����Ʈ�� �ڵ� ��Ƽ�� ������ �� �����ϴ�.
	GAME_TIMEQUEST_NEED_MORE_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� �� �ο��� ������� �ʽ��ϴ�
	GAME_TIMEQUEST_NOT_ALLOWED_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� ������ �㰡���� ���� ��� �Դϴ�.
	GAME_TIMEQUEST_EXCEED_MAX_MEMBER_COUNT,					// Ÿ�Ӹӽ� ����Ʈ �����ִ� �ο��� �ʰ��Ǿ����ϴ�.
	GAME_TIMEQUEST_TOO_LOW_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_TOO_HIGH_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_MUST_HAVE_NEED_ITEM,						// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� �������� �����ϴ�
	GAME_TIMEQUEST_MUST_HAVE_NEED_ZENNY,					// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� ���ϰ� �����մϴ�.
	GAME_TIMEQUEST_ROOM_NOT_WAIT_STATE,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ������ �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_JOIN_FAIL,					// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ��Ƽ����� �� �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_ALREADY_JOINED,				// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� ��Ƽ����� �Ǿ� �ֽ��ϴ�.
	GAME_TIMEQUEST_ROOM_OUT_OF_ENTER_RANGE,					// Ÿ�Ӹӽ� ����Ʈ�� ���� ������ ������ϴ�.
	GAME_TIMEQUEST_ROOM_CANNOT_TELEPORT_NOW,				// ������ Ÿ�Ӹӽ��� ��ġ�� �̵��� �� �����ϴ�.
	GAME_TIMEQUEST_DAYRECORD_IS_ALREADY_RESET,				// ���̷��ڵ� ������ �̹� ó���Ǿ����ϴ�.
	GAME_TIMEQUEST_WORLD_ENTER_FAIL,						// Ÿ�Ӹӽ� ����Ʈ ������ �����Ͽ����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_TMQ,	// Ÿ�Ӹӽ� ����Ʈ�� ���� �� ������ ��Ƽ���� ���� �� �����ϴ�.

	//-----------------------------------------------------------------
	GAME_TUTORIAL_CHAR_ALREADY_TUTORIAL_ACCOMPLISHED = 2350, // ĳ���Ͱ� �̹� Ʃ�丮���� �����߽��ϴ�
	GAME_TUTORIAL_CANT_FIND_TUTORIAL_WAIT_ROOM,				// Ʃ�丮�� ������ ���� ���� �ʽ��ϴ�
	GAME_TUTORIAL_CANT_ENTER_TUTORIAL_WAIT_ROOM,			// Ʃ�丮�� ���뿡 ������ �� �����ϴ�
	GAME_TUTORIAL_YOU_HAVE_NO_JOIN_ROOM,					// Ʃ�丮�� ��⸦ �ϰ� ���� �ʽ��ϴ�.


	//-----------------------------------------------------------------
	GAME_PRIVATESHOP = 2400,
	GAME_PRIVATESHOP_NOTAUTH,												// ������ �����ϴ�
	GAME_PRIVATESHOP_NOTRUNSTATE,											// ���� ���¿����� ���� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NOT_CREATE_PLACE,							// ���� ������ ���� ���� ��� �Դϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_PRIVATESHOP,						// ��ó�� �ٸ� ���λ����� �־ ���λ����� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NULL,										// ������ �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,					// ���� �κ��丮�� �󽽷��� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SLOT_ALREADY_ITEM,				// ���� �κ��丮 ���Կ� �̹� �������� �ֽ��ϴ�
	GAME_PRIVATESHOP_ITEM_NULL,												// �������� �����ϴ�
	GAME_PRIVATESHOP_ITEM_NOTVALID,											// �ȼ� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_NULL,											// �մ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_MONEY,										// �մԿ� ���� ���ڸ��ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_INVENTORY_EMPTY,							// �մԿ� �κ��丮 ���Կ� �����۵��� �� �� �ֽ��ϴ�
	GAME_PRIVATESHOP_VISITOR_ALREADYENTER,									// �մ��� �̹� ������ �����߽��ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_NULL,								// �մ��� ���� �������� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_OVER,								// ���̻� �������� ���� �� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADY,							// �̹� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALLSELL,							// ������ �����۵��� ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_INVENSOLT_SHORTOF,					// �κ��丮�� �� ������ �����մϴ�
	GAME_PRIVATESHOP_VISITOR_FULL,											// ������ �մ��� �� �� �ִ� ���ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_MONEY_FULL,										// ���� ���� ���� ���̻� �þ�� �����ϴ�
	GAME_PRIVATESHOP_OWNER_THEREISNO,										// ���� ������ �ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_REFUSED,								// ������ ������ �ź����̴�
	GAME_PRIVATESHOP_INVENTORY_NOTINVENTTORY,								// �߸��� �κ��丮 �Դϴ�
	GAME_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,								// Inventory�� �� ������ �����ϴ�
	GAME_PRIVATESHOP_STOP_PROGRESS,											// �������Դϴ�
	GAME_PRIVATESHOP_OWNER_BARGAINS,										// ������ �ٸ������ �������Դϴ�
	GAME_PRIVATESHOP_ITEM_TABLE_ITEMID_DIFFERENT,							// �������� �������� �ʽ��ϴ�
	GAME_PRIVATESHOP_ITEM_SELECTITEM_NOTBUSINESS,							// �̹� ������ �������� ������ �� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_NOT_CONSENT,							// ���� ������ ������ �ź��߽��ϴ�
	GAME_PRIVATESHOP_SAMENOT_PRICEFLUCTUATIONSCOUNTER,						// ������ ���� ������ Ƚ���� �մ��� ���� ���� ��Ŷ�� ���� ���� �ٸ��ϴ�.
	GAME_PRIVATESHOP_ZENNY_LOCK,											// �ٸ� ����� Item Buy���̿��� Zenny�� Lock�� �Ǿ����ϴ�. ó���� ���������� ��ٷ� �ּ���
	GAME_PRIVATESHOP_NOT_PROGRESS_COMPLETE,									// ���� ��û�� ó���ɶ����� ���������� ��ٷ� �ּ��� (��Ŷ�� Qry Srv�� �ӹ��� �ִ�)
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADYBUYANDBUSINESSITEM,			// �̹� �ٸ� �մ��� ������ �������Դϴ�.
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_NPC,								// ��ó�� NPC�� �־ ���λ����� �� �� �����ϴ�
	//-----------------------------------------------------------------
	GAME_MAIL_TARGET_AWAY_STATE = 2500,						// ���� �޴� ����� �������̶� ���źҰ����մϴ�.
	GAME_MAIL_NOT_FOUND,									// ���� ã�� ���߽��ϴ�.
	GAME_MAIL_ALREADY_READ,									// ������ �̹� ���� �����Դϴ�.
	GAME_MAIL_INVALID_DEL,									// �ش������ ���� �� �����ϴ�.
	GAME_MAIL_INVALID_RETURN,								// �ش������ ������ �� �����ϴ�.
	GAME_MAIL_INVALID_ACCEPT,								// �ش������ ���� �� ���� �����Դϴ�.
	GAME_MAIL_INVALID_LOCK,									// �ش������ ��ݼ����� ���� �Ұ����մϴ�.
	GAME_MAIL_INVALID_ZENNY,								// ���� �� �ִ� ������ �ѵ��� �ʰ��߽��ϴ�.
	GAME_MAIL_NOT_EXISTING_PLAYER,							// �ش� ĳ���ʹ� �������� ���� ĳ�����Դϴ�.
	GAME_MAIL_CANT_SEND_MAIL_TO_YOURSELF,					// �ڱ� �ڽſ��Դ� ������ ���� �� �����ϴ�.
	GAME_MAIL_MAILING_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_TRANSMIT_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_SCOUTER_FAIL,									// ���������� ���� ��ī���͸� ����� �� ���� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PORTAL_ARLEADY_ADDED = 2600,						// �̵̹�ϵ� ��Ż�Դϴ�.
	GAME_PORTAL_NOT_EXIST,									// �̵�� ��Ż�Դϴ�. 

	GAME_WARFOG_ARLEADY_ADDED = 2610,						// �̵̹�ϵ� �������Դϴ�.
	//-----------------------------------------------------------------
	GAME_PROCESSING_DB = 2620,						// ���ó�����Դϴ�.
	//-----------------------------------------------------------------
	GAME_RIDE_ON_STATE = 2630,						// ���� Ÿ �ִ� ���� �Դϴ�.
	GAME_VEHICLE_CANNOT_WHILE_DRIVING,						// ���� �߿� �� �� �����ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STARTED,					// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STOPED,						// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_INVALID_FUEL_ITEM,							// 
	GAME_VEHICLE_FAIL_TO_USE_FUEL_ITEM,						// ���� ������ ��뿡 �����߽��ϴ�.
	GAME_VEHICLE_NO_FUEL_ITEM_REMAINING,					// ���� ���� �������� �����ϴ�.
	GAME_VEHICLE_END_BY_USER,								// ������ Ż�Ϳ��� �����⸦ ��û�߽��ϴ�.
	GAME_VEHICLE_END_BY_HIT,								// �ǰ� ���߱� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_CONVERTCLASS,						// �������� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_TELEPORT,							// �ڷ���Ʈ�� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORCED,								// Ż �� ���°� ������ Ǯ�Ƚ��ϴ�.
	GAME_VEHICLE_END_BY_TMQ,								// TMQ ���¿� �����ϱ� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORBIDDEN_ZONE,						// Ż ���� ������ �ʴ� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PETITION_NOTAUTH = 2700,							//������ �����ϴ�
	GAME_PETITION_TOO_LONG_NAME,							//ĳ���͸��� ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_NAME,							//ĳ���͸��� ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_TOO_LONG_QUESTION_CONTENT,				//���� ������ ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_QUESTION_CONTENT,				//���� ������ ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_CATEGORY_1_FAIL,							//ī�װ� 1�� ���� �̻��մϴ�.
	GAME_PETITION_CATEGORY_2_FAIL,							//ī�װ� 2�� ���� �̻��մϴ�.
	GAME_PETITION_CREATE_PETITION_FAILE,					//���� ������ �����߽��ϴ�
	GAME_PETITION_DELETE_FAILE_STARTED,					//�̹� ����߿� ������ �����̱⿡ ������ �� �����ϴ�
	GAME_PETITION_ISNOT_STARTED,							//���� ���°� ������ �ƴմϴ�
	GAME_PETITION_ALREADYSTARTED,							//�̹� �������Դϴ�
	GAME_PETITION_INSERT_ERROR_ZERO_ID,					//����Ÿ ���� ���� - ID�� 0�Դϴ�
	GAME_PETITION_INSERT_FAILE,							//����Ÿ ���� ���� (std::map���� ������ �뺸, �� �� ���� ����
	GAME_PETITION_INSERT_ALLREADY_ID,						//����Ÿ ���� ���� (�̹� ��ϵǾ� �ִ� ID �Դϴ�
	GAME_PETITION_CREATE_PETITION_ID_FAILE,				//Petition ID ���� ����
	GAME_PETITION_NOTRUNSTATE,								//���� ���¿����� ���� �� �� �����ϴ�
	GAME_PETITION_ACCOUNTNOTPETITION,						//�ش� ������ ������ �����ϴ�
	GAME_PETITION_ALREADY_INSERT,							//�̹� ������ ������ Account�Դϴ�.
	GAME_PETITION_LOCK,										// Petition�� Lock�Ǿ� �ֽ��ϴ�
	GAME_PETITION_PETITIONID_INVALID,						// Petition ID�� invalid �Դϴ�.
	GAME_PETITION_ALREADYFINISH,							//�̹� �Ϸ�� �����Դϴ�.

	//-----------------------------------------------------------------
	GAME_BUDOKAI_INVALID_TEAM_NAME = 2800,					// ���� �̸��� �ùٸ��� �ʽ��ϴ�.
	GAME_BUDOKAI_TOO_LONG_TEAM_NAME,						// ���� �̸��� �ʹ� ��ϴ�.
	GAME_BUDOKAI_TOO_SHORT_TEAM_NAME,						// ���� �̸��� �ʹ� ª���ϴ�.
	GAME_BUDOKAI_NEED_MORE_MEMBER,							// ������ �ʹ� �����ϴ�.
	GAME_BUDOKAI_NOT_REGISTER_PERIOD,						// ��� �Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_OVER_COUNT,								// �����ο��� �ʰ��Ǿ����ϴ�.
	GAME_BUDOKAI_CHARACTER_ALREADY_JOIN,					// �̹� ��û�� �����Դϴ�.
	GAME_BUDOKAI_CHARACTER_NOT_JOINED,						// ��û���� ���� �����Դϴ�.
	GAME_BUDOKAI_MEMBER_ALREADY_JOINED,						// �̹� ��û�� ����� �ֽ��ϴ�.
	GAME_BUDOKAI_YOU_ARE_NOT_A_TEAM_LEADER,					// �� ������ �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_PLAYING,							// �������� ��Ⱑ �����ϴ�.
	GAME_BUDOKAI_NOT_OPENED,								// ���±Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_WORLD,							// õ�����Ϲ���ȸ ������� �ƴմϴ�.

	GAME_CAN_NOT_TELEPORT,									// �̵��� �� �����ϴ�.
	GAME_CAN_NOT_TELEPORT_THIS_STATE,						// �̵��� �� ���� �����Դϴ�. ��� �� �ٽ� �õ��ϼ���.

	GAME_MUDOSA_NOT_OPEND,									// ���� �Ⱓ�� �ƴմϴ�.
	GAME_MUDOSA_POINT_CANT_BE_USED_RIGHT_NOW,				// �Ͻ������� ������ ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_MUDOSA_POINT_NOT_ENOUGH,							// ������ ������ ������� �ʽ��ϴ�.
	GAME_MUDOSA_POINT_MAX_OVER,								// ������ ������ �ִ븦 �ʰ��Ͽ����ϴ�.

	GAME_MINORMATCH_CANNOT_TELEPORT_THIS_STATE,				// ������ ������ ���׿����� ������ �� �����ϴ�.

	GAME_NETP_POINT_CANT_BE_USED_RIGHT_NOW,					// �Ͻ������� NetPY ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_NETP_POINT_MAX_OVER,								// NetPY Point�� �ִ븦 �ʰ��Ͽ����ϴ�.
	GAME_NETP_POINT_NOT_ENOUGH,								// NetPY Point�� ������� �ʽ��ϴ�.
	GAME_NETPY_IS_LOCK,										// NetPY�� ��� �����Դϴ�.
	GAME_NETPY_NOT_ENOUGH,									// NetPY�� �����մϴ�.	

	GAME_BUILDING_VERSION_IS_NOT_CJI_KOR,					// The Building Version is not CJI Kor

	GAME_NETMARBLEMEMBER_IS_NOT,							// Netmarble Member�� �ƴմϴ�.

	GAME_CASHITEM_CANT_MOVE,								// �ش� ĳ���������� ������ �� �����ϴ�.
	GAME_CASHITEM_NOT_LOADED,								// ĳ�������� �ε��� �Ϸ���� �ʾҽ��ϴ�.
	GAME_CASHITEM_NOT_FOUND,								// �ش� ĳ���������� ã�� �� �����ϴ�.
	//-----------------------------------------------------------------
	// Game, Item ����. 800���뿡�� �̾���. ( 3000 ~ )
	//-----------------------------------------------------------------
	GAME_ITEM_UPGRADE_ITEM_IS_ZERO_GRADE = 3000,			// �� ȣ������ ������ ����� �� �����ϴ�.
	GAME_DRAGONBALL_NOT_SAME_EXIST,							// �ٸ� ������ �巡�ﺼ �Դϴ�.
	GAME_ITEM_DURATIONTIME_ZERO,							// ��� �Ⱓ�� �������ϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_NORMAL_TYPE,				// �⺻ ���� ����� ������ �� �����ϴ�.
	GAME_ITEM_NOT_USE_THIS_PLACE,							// ���⼭ ����� �� ���� �������Դϴ�.
	GAME_ITEM_STACK_FAIL_ITEMTYPE_DURATION,					// ���Ⱓ�� �ִ� �������� Stack�� �� �����ϴ�.
	GAME_ITEM_RECIPE_NORMAL_RECIPE_ALREADY_STARTED,			// �⺻ ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_SPECIAL_RECIPE_ALREADY_STARTED,		// Ư�� ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_CAUSE_NOT_STARTED_YET,	// ���� ����� ���� ����� �ʱ�ȭ �� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_HIGHER_LEVEL,		// ������ �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_MORE_ZENNY,		// ���ϰ� �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_CANT_USE_CAUSE_CAPSULE_ITEM_ALREADY_IN_USE,	// ĸ�� �������� �̹� ������Դϴ�.

	GAME_SCOUTER_CHIP_NOT_EXIST,							// ��ī���� Ĩ�� �������� �ʽ��ϴ�.

	//-----------------------------------------------------------------
	REPORT_SUCCESS = 6000,									// ������ ����
	REPORT_FAIL,											// ������ ����

	//-----------------------------------------------------------------
	// Petition System ( 10000 ~ )
	//-----------------------------------------------------------------
	PETITION_SUCCESS = 10000,								// Petition ����
	PETITION_FAIL,											// Petition ����

	PETITION_NOT_STARTED_CLEINT_GM_CHAT,					// Ŭ���̾�Ʈ�� GM ä���� ���۵��� �ʾҽ��ϴ�
	PETITION_DIFFERENT_CHAATING_GM_ID,						// Ŭ���̾�Ʈ�� ä������ GM�� ID�� �ٸ� GM ID�̴�.
	PETITION_NOT_YET_ENTER_WORLD,							// ������ ���忡 ���� �ʾҴ�
	PETITION_AREADY_GM_CHATTING,							// ������ �̹� GM ä�����̴�

	RESULT_DUMMY = 0xFFFF
	//////////////////////////////////////////////////////////////////////////
};