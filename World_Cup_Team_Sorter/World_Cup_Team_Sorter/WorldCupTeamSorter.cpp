// WorldCupTeamSorter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Groups { A, B, C, D, E, F, G, H };

class Team
{
public:
	
	int team_ID;
	static int NUMBER_OF_TEAMS;
	string team_name;
	int team_section;
	Groups group;
	Team()
	{
		NUMBER_OF_TEAMS = 0;
		NUMBER_OF_TEAMS++;
	}
	Team(int teamID, string teamname, int teamsection, Groups assignedGroup)
	{
		team_ID = teamID;
		team_name = teamname;
		team_section = teamsection;
		group = assignedGroup;
		NUMBER_OF_TEAMS++;
	}
};

class Person
{
public:
	int person_ID;
	static int NUMBER_OF_PEOPLE;
	string person_name;
	Team teams[4];
	Person(int personID, string name)
	{
		person_ID = personID;
		person_name = name;
		NUMBER_OF_PEOPLE++;
	}
};

int Team::NUMBER_OF_TEAMS = 0;
int Person::NUMBER_OF_PEOPLE = 0;
vector<Person*> AllPeople;

void Swapper(int currentPersonToInspect, int firstIndexToInspect, int secondIndexToInspect, vector<Person*> AllPeopleVector);

int main()
{
	Team Brazil(Team::NUMBER_OF_TEAMS + 1, "Brazil", 1, E);
	Team Germany(Team::NUMBER_OF_TEAMS + 1, "Germany", 1, F);
	Team Spain(Team::NUMBER_OF_TEAMS + 1, "Spain", 1, B);
	Team France(Team::NUMBER_OF_TEAMS + 1, "France", 1, C);
	Team Argentina(Team::NUMBER_OF_TEAMS + 1, "Argentina", 1, D);
	Team Belgium(Team::NUMBER_OF_TEAMS + 1, "Belgium", 1, G);
	Team England(Team::NUMBER_OF_TEAMS + 1, "England", 1, G);
	Team Portugal(Team::NUMBER_OF_TEAMS + 1, "Portugal", 1, B);

	Team Croatia(Team::NUMBER_OF_TEAMS + 1, "Croatia", 2, D);
	Team Uruguay(Team::NUMBER_OF_TEAMS + 1, "Uruguay", 2, A);
	Team Columbia(Team::NUMBER_OF_TEAMS + 1, "Columbia", 2, H);
	Team Russia(Team::NUMBER_OF_TEAMS + 1, "Russia", 2, A);
	Team Poland(Team::NUMBER_OF_TEAMS + 1, "Poland", 2, H);
	Team Switzerland(Team::NUMBER_OF_TEAMS + 1, "Switzerland", 2, E);
	Team Denmark(Team::NUMBER_OF_TEAMS + 1, "Denmark", 2, C);
	Team Mexico(Team::NUMBER_OF_TEAMS + 1, "Mexico", 2, F);
	
	Team Sweden(Team::NUMBER_OF_TEAMS + 1, "Sweden", 3, F);
	Team Egypt(Team::NUMBER_OF_TEAMS + 1, "Egypt", 3, A);
	Team Serbia(Team::NUMBER_OF_TEAMS + 1, "Serbia", 3, E);
	Team Senegal(Team::NUMBER_OF_TEAMS + 1, "Senegal", 3, H);
	Team Peru(Team::NUMBER_OF_TEAMS + 1, "Peru", 3, C);
	Team Iceland(Team::NUMBER_OF_TEAMS + 1, "Iceland", 3, D);
	Team Nigeria(Team::NUMBER_OF_TEAMS + 1, "Nigeria", 3, D);
	Team Japan(Team::NUMBER_OF_TEAMS + 1, "Japan", 3, H);


	Team Australia(Team::NUMBER_OF_TEAMS + 1, "Australia", 4, C);
	Team Morocco(Team::NUMBER_OF_TEAMS + 1, "Morocco", 4, B);
	Team Iran(Team::NUMBER_OF_TEAMS + 1, "Iran", 4, B);
	Team Costa_Rica(Team::NUMBER_OF_TEAMS + 1, "Costa Rica", 4, E);
	Team Tunisia(Team::NUMBER_OF_TEAMS + 1, "Tunisia", 4, G);
	Team South_Korea(Team::NUMBER_OF_TEAMS + 1, "South Korea", 4, F);
	Team Saudi_Arabia(Team::NUMBER_OF_TEAMS + 1, "Saudi Arabia", 4, A);
	Team Panama(Team::NUMBER_OF_TEAMS + 1, "Panama", 4, G);

	Person Chris(Person::NUMBER_OF_PEOPLE + 1, "Chris");
	Person Lynn(Person::NUMBER_OF_PEOPLE + 1, "Lynn");
	Person Steve(Person::NUMBER_OF_PEOPLE + 1, "Steve");
	Person Michael(Person::NUMBER_OF_PEOPLE + 1, "Michael");
	Person Jenna(Person::NUMBER_OF_PEOPLE + 1, "Jenna");
	Person Nanna(Person::NUMBER_OF_PEOPLE + 1, "Nanna");
	Person Grandad(Person::NUMBER_OF_PEOPLE + 1, "Grandad");
	Person Shirley(Person::NUMBER_OF_PEOPLE + 1, "Shirley");

	//cout << Shirley.person_ID << endl;
	//cout << Panama.team_ID << endl;



	vector<Person*> AllPeople = { &Chris, &Lynn, &Steve, &Michael, &Jenna, &Nanna, &Grandad, &Shirley };

	//cout << AllPeople[0]->person_name << endl;
	vector<Person*> CurrentPeople = AllPeople;

	vector<Team*> AllTeams = { &Brazil, &Germany, &Spain, &France, &Argentina, &Belgium, &England, &Portugal, &Croatia, &Uruguay, &Columbia, &Russia, &Poland, &Switzerland, &Denmark, &Mexico, 
		&Sweden, &Egypt, &Serbia, &Senegal, &Peru, &Iceland, &Nigeria, &Japan, &Australia, &Morocco, &Iran, &Costa_Rica, &Tunisia, &South_Korea, &Saudi_Arabia, &Panama };
	vector<Team*> CurrentTeams;


	int count = 0;




	for (int i = 0; i < 4; i++)
	{
		count++;
		CurrentPeople = AllPeople;
		
		for (int j = 0; j < 32; j++)
		{
			if (AllTeams[j]->team_section == i + 1)
			{
				cout << AllTeams[j]->team_name << " is part of team section: " << i+1 << endl;
				//cout << AllTeams[j].team_name << " is part of team section: " << i + 1 << endl;
				
				cout << endl;

				CurrentTeams.push_back(AllTeams[j]);
				

			}
		}

		for (int k = 0; k < Person::NUMBER_OF_PEOPLE; k++)
		{
			//cout << CurrentTeams[k].team_name << endl;
			int randomPersonIndex = rand() % CurrentPeople.size();
			int randomTeamIndex = rand() % CurrentTeams.size();
			
			//CurrentPeople[randomPersonIndex]->teams[i] = CurrentTeams[randomTeamIndex]->team_ID;
			CurrentPeople[randomPersonIndex]->teams[i] = *CurrentTeams[randomTeamIndex];


			//cout << CurrentPeople[randomPersonIndex].person_name << " now has " << CurrentPeople[randomPersonIndex].teams[i] << endl;
		//	cout << endl;
			

			
			CurrentPeople.erase(CurrentPeople.begin() + (randomPersonIndex));
			CurrentTeams.erase(CurrentTeams.begin() + (randomTeamIndex ));

			//cout << AllPeople[2].person_name << " now has " << AllPeople[2].teams[0] << endl;
			
		}

	}
	

	
	
	
	for (int i = 0; i < Person::NUMBER_OF_PEOPLE; i++)
	{
		if (AllPeople[i]->teams[0].group == AllPeople[i]->teams[1].group)
		{
			/*bool loopcondition = false;
			do
			{
				int randomPersonIndex = rand() % AllPeople.size();

				if (randomPersonIndex == i)
				{
					continue;
				}
				Team teamholder1;
				Team teamholder2;


				teamholder1 = AllPeople[i]->teams[0];
				AllPeople[i]->teams[0] = AllPeople[randomPersonIndex]->teams[0];
				AllPeople[randomPersonIndex]->teams[0] = teamholder1;

				if ((AllPeople[i]->teams[0].group == AllPeople[i]->teams[1].group) || (AllPeople[randomPersonIndex]->teams[0].group == AllPeople[randomPersonIndex]->teams[1].group))
				{
					loopcondition = false;
					//revert back to normal
					teamholder1 = AllPeople[i]->teams[0];
					AllPeople[i]->teams[0] = AllPeople[randomPersonIndex]->teams[0];
					AllPeople[randomPersonIndex]->teams[0] = teamholder1;
				}
				else
				{
					loopcondition = true;
				}
			} while (loopcondition == false);*/
			cout << AllPeople[i]->person_name << " has got a problem with team 1 and 2" << endl;
			Swapper(i, 0, 1, AllPeople);
		}
		else if (AllPeople[i]->teams[0].group == AllPeople[i]->teams[2].group)
		{
			cout << AllPeople[i]->person_name << " has got a problem with team 1 and 3" << endl;
			Swapper(i, 0, 2, AllPeople);
		}
		else if (AllPeople[i]->teams[0].group == AllPeople[i]->teams[3].group)
		{
			cout << AllPeople[i]->person_name << " has got a problem with team 1 and 4" << endl;
			Swapper(i, 0, 3, AllPeople);
		}
		else if (AllPeople[i]->teams[1].group == AllPeople[i]->teams[2].group)
		{
			cout << AllPeople[i]->person_name << " has got a problem with team 2 and 3" << endl;
			Swapper(i, 1, 2, AllPeople);
		}
		else if (AllPeople[i]->teams[1].group == AllPeople[i]->teams[3].group)
		{
			cout << AllPeople[i]->person_name << " has got a problem with team 2 and 4" << endl;
			Swapper(i, 1, 3, AllPeople);
		}
		else if (AllPeople[i]->teams[2].group == AllPeople[i]->teams[3].group)
		{
			cout << AllPeople[i]->person_name << " has got a problem with team 3 and 4" << endl;
			Swapper(i, 2, 3, AllPeople);
		}

	}
	/*
	for (int i = 0; i < Person::NUMBER_OF_PEOPLE; i++)
	{
		if (AllPeople[i]->teams[2].group == AllPeople[i]->teams[3].group)
		{
			bool loopcondition = false;
			do
			{
				int randomPersonIndex = rand() % AllPeople.size();

				if (randomPersonIndex == i)
				{
					continue;
				}
				Team teamholder1;
				Team teamholder2;


				teamholder1 = AllPeople[i]->teams[2];
				AllPeople[i]->teams[2] = AllPeople[randomPersonIndex]->teams[2];
				AllPeople[randomPersonIndex]->teams[2] = teamholder1;

				if ((AllPeople[i]->teams[2].group == AllPeople[i]->teams[3].group) || (AllPeople[randomPersonIndex]->teams[2].group == AllPeople[randomPersonIndex]->teams[3].group))
				{
					loopcondition = false;
					//revert back to normal
					teamholder1 = AllPeople[i]->teams[2];
					AllPeople[i]->teams[2] = AllPeople[randomPersonIndex]->teams[2];
					AllPeople[randomPersonIndex]->teams[2] = teamholder1;
				}
				else
				{
					loopcondition = true;
				}
			} while (loopcondition == false);
		}
	}*/


	
	//cout << AllPeople[2]->person_name << " now has " << AllPeople[2]->teams[0] << endl;
//	cout << Chris.person_name << " now has: " << Chris.teams[0] << endl;


	for (int i = 0; i < Person::NUMBER_OF_PEOPLE; i++)
	{
		cout << AllPeople[i]->person_name << " got " << AllPeople[i]->teams[0].team_name << " , " << AllPeople[i]->teams[1].team_name << " , " << AllPeople[i]->teams[2].team_name << " , " << AllPeople[i]->teams[3].team_name << endl;

	}
	cin.get();
    return 0;
}

void Swapper(int currentPersonToInspect, int firstIndexToInspect, int secondIndexToInspect, vector<Person*> AllPeopleVector)
{
	bool loopcondition = false;
	do
	{
		cout << "Looping is fun" << endl;
		int randomPersonIndex = rand() % AllPeopleVector.size();


		

		if (randomPersonIndex == currentPersonToInspect)
		{
			continue;
		}
		Team teamholder1;
		Team teamholder2;


		teamholder1 = AllPeopleVector[currentPersonToInspect]->teams[firstIndexToInspect];
		AllPeopleVector[currentPersonToInspect]->teams[firstIndexToInspect] = AllPeopleVector[randomPersonIndex]->teams[firstIndexToInspect];
		AllPeopleVector[randomPersonIndex]->teams[firstIndexToInspect] = teamholder1;

		if ((AllPeopleVector[currentPersonToInspect]->teams[firstIndexToInspect].group == AllPeopleVector[currentPersonToInspect]->teams[secondIndexToInspect].group) || (AllPeopleVector[randomPersonIndex]->teams[firstIndexToInspect].group == AllPeopleVector[randomPersonIndex]->teams[secondIndexToInspect].group))
		{
			Swapper(currentPersonToInspect, firstIndexToInspect, secondIndexToInspect, AllPeopleVector);
			loopcondition = false;
			//revert back to normal
			teamholder1 = AllPeopleVector[currentPersonToInspect]->teams[firstIndexToInspect];
			AllPeopleVector[currentPersonToInspect]->teams[firstIndexToInspect] = AllPeopleVector[randomPersonIndex]->teams[firstIndexToInspect];
			AllPeopleVector[randomPersonIndex]->teams[firstIndexToInspect] = teamholder1;
		}
		else
		{
			loopcondition = true;
		}
	} while (loopcondition == false);
}

