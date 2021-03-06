// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜    
#define _CRT_SECURE_NO_WARNINGS 1
#define INPUT_SIZE 80	// максимальная длинна команд в интерактивном режиме

#include <stdio.h>
#include <string.h>
#include <crtdbg.h>  
#include <assert.h>
#include <stdbool.h>
#include "linked_list.h"
#include "contest.h"

int main(int argc, char *argv[])
{
	bool inf_loop = true;

	CONTEST *contest = NULL;

	do
	{
		char input_cmd[INPUT_SIZE];
		fgets(input_cmd, INPUT_SIZE, stdin);
		
		if (strcmp(input_cmd, "exit\n") == 0)
			break;
		else if (strcmp(input_cmd, "add\n") == 0)
		{
			printf("NAME, TEAM, ELO >> ");
			char *name = (char*)malloc(16);
			char *team = (char*)malloc(16);
			int elo = 0;
			scanf("%s%s%d", name, team, &elo);
			CONTEST_registration(&contest, name, team, elo);
		}
		else if (strcmp(input_cmd, "delete\n") == 0)
		{
			printf("NAME >> ");
			char *name = (char*)malloc(16);
			scanf("%s", name);
			CONTEST_delete_player(&contest, name);
		}
		else if (strcmp(input_cmd, "printall\n") == 0)
		{
			CONTEST_show_players(contest);
		}
		else if (strcmp(input_cmd, "elo\n") == 0)
		{
			int elo;
			printf("ELO, +/- ~ GT/LT >> ");
			scanf("%d", &elo);
			CONTEST_filter_by_elo(contest, elo);
		}
		else if (strcmp(input_cmd, "team\n") == 0)
		{
			char team[32];
			printf("TEAM >> ");
			scanf("%s", &team);
			CONTEST_filter_by_team(contest, team);
		}
		else if (strcmp(input_cmd, "save\n") == 0)
		{
			char filename[32];
			printf("FILENAME  >> ");
			scanf("%s", &filename);

			FILE *db = fopen(filename, "w");
			if (db == NULL)
			{
				printf("wrong path\n");
				continue;
			}
			CONTEST_save(db, contest);
			fclose(db);
		}
		else if (strcmp(input_cmd, "load\n") == 0)
		{
			char filename[32];
			printf("FILENAME  >> ");
			scanf("%s", &filename);

			FILE *db = fopen(filename, "r");
			if (db == NULL)
			{ 
				printf("wrong path\n");
				continue;
			}
			CONTEST_load(db, &contest);
			fclose(db);
		}

	} while (inf_loop);


	//небольшой ShowCase
	//CONTEST *QuakeCon2004 = NULL;
	//CONTEST_registration(&QuakeCon2004, "Cooller", "Mousesports", 9000);
	//CONTEST_registration(&QuakeCon2004, "Fatal1ty", "-", 3622);
	//CONTEST_registration(&QuakeCon2004, "k1llsen", "-", 3441);
	//CONTEST_registration(&QuakeCon2004, "av3k", "SeriousGaming", 2222);
	//CONTEST_registration(&QuakeCon2004, "Cypher", "Titan", 3748);
	//CONTEST_registration(&QuakeCon2004, "Polosaty", "NiP", 3524);
	//CONTEST_registration(&QuakeCon2004, "Strenx", "fnatic", 2732);

	//FILE *db = fopen("playerlist.txt", "w");
	//CONTEST_save(db, QuakeCon2004);
	//fclose(db);

	//FILE *db = fopen("QuakeCon.txt", "r");
	//CONTEST_load(db, &QuakeCon2004);
	//fclose(db);
	//
	//printf("all:\n");
	//CONTEST_show_players(QuakeCon2004);			// участники
	//printf("\nno team:\n");
	//CONTEST_filter_by_team(QuakeCon2004, "-");		// участники без команды
	//printf("\nelo > 3000:\n");
	//CONTEST_filter_by_elo(QuakeCon2004, +3000);		// ELO выше N
	//printf("\nelo < 3000:\n");
	//CONTEST_filter_by_elo(QuakeCon2004, -3000);		// ELO ниже N

	//printf("\n Av3k had been arrested =( :\n");		// удаление участника
	//CONTEST_delete_player(&QuakeCon2004, "av3k");
	//CONTEST_show_players(QuakeCon2004);
	

	return 0;
}
