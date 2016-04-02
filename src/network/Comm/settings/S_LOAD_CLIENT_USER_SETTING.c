#include "Player.h"

void S_LOAD_CLIENT_USER_SETTING_f(player_t *player)
{
	char FName[strlen(Cfg_Server_DirSave)+14+10+1];
	sprintf(FName, "%s/USER_SETTING/%i", Cfg_Server_DirSave, player->Character_Id);
	FILE *fp = fopen(FName, "rb");
	if (fp) {
		P_Buffer_t buffer;
		set_WBuffer(&buffer, S_LOAD_CLIENT_USER_SETTING);
		int size = fread(buffer.Data + buffer.Pos, 1, buffer.Size-buffer.Pos, fp);
		fclose(fp);
		buffer.Pos += size;
		Player_Send(player, &buffer);
	} else USER_SETTING_Saved(player, S_LOAD_CLIENT_USER_SETTING);
}
