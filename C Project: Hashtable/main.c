#include "HashTable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	//declare new hashtable of size 100
	HashTable h = newHashTable(100);

	//open the nbaTeamNames file
	FILE *fp;
	fp = fopen("nbaTeamNames.csv", "r");

	if(fp == NULL)
	{
		printf("Error: file could not be opened\n");
	}	

	else
	{
		//read in each team name and use put to insert each one into the hash table
		char buffer[100];
		char name[30];

		while(fgets(buffer, 100, fp) != NULL)
		{
			sscanf(buffer, "%[^\r\n]", name);

			//create element, assign word to teamName, set wins and losses to 0
			Element e;

			strcpy(e.teamName, name);
			e.wins = 0;
			e.losses = 0;

			//use put to insert element
			put(h, e);
		}

		//next, open the nbaData2019 file
		FILE *fp2;
		fp2 = fopen("nbaData2019.csv", "r");

		if(fp2 == NULL)
		{
			printf("Error: file could not be opened\n");
		}

		else
		{
			//for each line, determine the 2 teams, who won and who lost, then use get to increment the teams' total wins and losses
			char buffer2[100];
			char team1[30];
			char team2[30];
			int score1;
			int score2;
			Element *eTeam1;
			Element *eTeam2;

			while(fgets(buffer2, 100, fp2) != NULL)
			{

				sscanf(buffer2, "%[^,],%d,%[^,],%d", team1, &score1, team2, &score2);

				//compare scores and assign values appropriately
				//if team1 beat team2
				if(score1 > score2)
				{
					//winning team
					eTeam1 = get(h, team1);

					//check that team exists on hashtable
					if(eTeam1 == NULL)
					{

					}

					else
					{
						eTeam1->wins = eTeam1->wins + 1;
					}

					//losing team
					eTeam2 = get(h, team2);

					if(eTeam2 == 0)
					{
						
					}

					else
					{
						eTeam2->losses = eTeam2->losses + 1;
					}
				}

				//team2 beats team1
				else if(score2 > score1)
				{
					//winning team
					eTeam2 = get(h, team2);

					if(eTeam2 == NULL)
					{
						
					}

					else
					{
						eTeam2->wins = eTeam2->wins + 1;
					}

					//losing team
					eTeam1 = get(h, team1);

					if(eTeam1 == NULL)
					{

					}

					else
					{
						eTeam1->losses = eTeam1->losses + 1;
					}
				}

				//tie
				else
				{

				}
			
			}
			
			//once all wins and losses have been added, use the nbaTeamNames file once again along with the get function to 
			//print out all teams and their records
			char teamFinal[30];
			Element *eFinal;

			rewind(fp);

			while(fgets(buffer, 100, fp) != NULL)
			{
				sscanf(buffer, "%[^\r\n]", teamFinal);

				eFinal = get(h, teamFinal);

				if(eFinal == NULL)
				{
					printf("No team\n");
				}

				else
				{
					printf("%s: %d Wins - %d Losses\n", eFinal->teamName, eFinal->wins, eFinal->losses);
				}
			}

		//end of second else
		}

		//close the second file
		close(fp2);
		

	//end of first else
	}

	//close the first file
	close(fp);

	//free the hashtable
	freeHashTable(h);

		
	return 0;
}


