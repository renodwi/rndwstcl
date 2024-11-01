#if defined _RndwstCL_included
	#endinput
#endif
#define _RndwstCL_included

#define MAX_RNDWSTCL_FUNCTION 31
#define RNDWSTCL_DIALOG 3923
#define ColorSelector:%0(%1) \
	forward RndwstCL_%0(%1); public RndwstCL_%0(%1)
#define ShowPlayerColorList(%0,%1, \
        RndwstCL_Open(%0, #%1,

new eRndwstCL_ColorList[] = {
    0xF9FAFBFF,
    0xF3F4F6FF,
    0xE5E7EBFF,
    0xD1D5DBFF,
    0x9CA3AFFF,
    0x6B7280FF,
    0x4B5563FF,
    0x374151FF,
    0x1F2937FF,
    0x111827FF,
    0xFFFBEBFF,
    0xFEF3C7FF,
    0xFDE68AFF,
    0xFCD34DFF,
    0xFBBF24FF,
    0xF59E0BFF,
    0xD97706FF,
    0xB45309FF,
    0x92400EFF,
    0x78350FFF,
    0xEFF6FFFF,
    0xDBEAFEFF,
    0xBFDBFEFF,
    0x93C5FDFF,
    0x60A5FAFF,
    0x3B82F6FF,
    0x2563EBFF,
    0x1D4ED8FF,
    0x1E40AFFF,
    0x1E3A8AFF,
    0xF0F5FFFF,
    0xE0E7FFFF,
    0xC7D2FEFF,
    0xA5B4FCFF,
    0x818CF8FF,
    0x6366F1FF,
    0x4F46E5FF,
    0x4338CAFF,
    0x3730A3FF,
    0x312E81FF,
    0xECFDF5FF,
    0xD1FAE5FF,
    0xA7F3D0FF,
    0x6EE7B7FF,
    0x34D399FF,
    0x10B981FF,
    0x059669FF,
    0x047857FF,
    0x065F46FF,
    0x064E3BFF,
    0xDFF6FFFF,
    0xBFEFFFFF,
    0x82DAFFFF,
    0x29B6F6FF,
    0x00A5FFFF,
    0x0086C3FF,
    0x005F9EFF,
    0x003E6BFF,
    0x00213CFF,
    0xFFF5F5FF,
    0xFED7D7FF,
    0xFEB2B2FF,
    0xFC8181FF,
    0xF56565FF,
    0xE53E3EFF,
    0xC53030FF,
    0x9B2C2CFF,
    0x742A2AFF,
    0x63171BFF,
    0xFFF0F6FF,
    0xFFC1CCFF,
    0xFF88A2FF,
    0xFF4D78FF,
    0xE11E5CFF,
    0xBE123CFF,
    0x9F1239FF,
    0x7F0E28FF,
    0x650014FF,
    0x4A0011FF,
    0xECECECFF,
    0xD9D9D9FF,
    0xBFBFBFFF,
    0x8C8C8CFF,
    0x595959FF,
    0x404040FF,
    0x262626FF,
    0x0F0F0FFF,
    0x000000FF
};

new RndwstCL_function[MAX_PLAYERS][MAX_RNDWSTCL_FUNCTION];
new bool:RndwstCL_playerusing[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    RndwstCL_playerusing[playerid] = false;
    return 1;
}

stock RndwstCL_Open(playerid, const function[], const caption[], const button1[], const button2[])
{
    new bool:status = true;

    new function_fix[MAX_RNDWSTCL_FUNCTION];
    format(function_fix, MAX_RNDWSTCL_FUNCTION, "RndwstCL_%s", function);
    strpack(RndwstCL_function[playerid], function_fix, 32 char);

    new panjang_fungsi = strlen(RndwstCL_function[playerid]);
    if(panjang_fungsi > MAX_RNDWSTCL_FUNCTION)
        printf("[Rndwst - Color Selector] The Colour Picker with the '%s' function cannot have a size greater than 31 characters!", RndwstCL_function[playerid]), status = false;

    if(RndwstCL_isstringcontainspace(function))
        printf("[Rndwst - Color Selector] The Colour Picker with the '%s' function cannot have a space in it!", RndwstCL_function[playerid]), status = false;

    if(status == false)
    {
        SendClientMessage(playerid, 0xFF0000FF, "[Rndwst - Color Selector] An error occurred, please check the SA:MP terminal.");
        return 1;
    }

    new message[4096];
    for(new i = 0; i < sizeof eRndwstCL_ColorList; i++)
	{
		format(message, sizeof message, "%s{%06x}####################\n", message, (eRndwstCL_ColorList[i] >>> 8));
	}
    ShowPlayerDialog(playerid, RNDWSTCL_DIALOG, DIALOG_STYLE_LIST, caption, message, button1, button2);

    RndwstCL_playerusing[playerid] = true;
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == RNDWSTCL_DIALOG)
    {
        new bool:status = true;
        if(RndwstCL_playerusing[playerid] == false)
            printf("[Rndwst - Color Selector] Please do not use dialog id %d as it is used for Color Selector", RNDWSTCL_DIALOG), status = false;

        if(status == false)
        {
            SendClientMessage(playerid, 0xFF0000FF, "[Rndwst - Color Selector] An error occurred, please check the SA:MP terminal.");
            return 1;
        }

        RndwstCL_playerusing[playerid] = false;
        CallLocalFunction(RndwstCL_function[playerid], "ddd", playerid, response, eRndwstCL_ColorList[listitem]);
    }
    return 1;
}

stock RndwstCL_isstringcontainspace(const string[]) {
    for (new i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            return true;
        }
    }
    return false;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect RndwstCL_OnPlayerConnect

#if defined RndwstCL_OnPlayerConnect
	forward RndwstCL_OnPlayerConnect(playerid);
#endif

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse RndwstCL_OnDialogResponse

#if defined RndwstCL_OnDialogResponse
	forward RndwstCL_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif