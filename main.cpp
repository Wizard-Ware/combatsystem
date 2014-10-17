#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Developers
Kevin
Clint

To do list
-done- Fix overfow of defend, ward and healing touch
-done- Add mp and mp bar
-done- Add in random chance of miss based off accuracy and evade rate
-done- Add in random damage amount base of 1 - attack stat
5| Add in speed modifier
6| Add in multiple ememies
7| Add in party members
8| Add in asist attack for party members
9| Make offensive magic miss

Change log
Removed extra text from fight
Added an HP bar and MP bar for player and monster
*/

using namespace std;

struct stats
    {
    int attack;
    int maxdefense;
    int defense;
    int hp;
    int maxhp;
	int armor;
	int mp;
    int maxmp;
    };

struct magic
    {
    int fireball;
    int fireball_cost;
    int healing_touch;
    int healing_touch_cost;
    int ward;
    int ward_cost;
    };

//added new monster with stats and the random number generator//
stats encounter ()//generates a random monster to fight//
{
	int roll;

	stats troll;{
		troll.attack = 7;
		troll.maxdefense = 4;
		troll.defense = 4;
		troll.hp = 10;
		troll.maxhp = 25;
		troll.armor = 14;
		troll.mp = 0;
		troll.maxmp = 0;
	};
	stats goblin;{
		goblin.attack = 3;
		goblin.maxdefense = 1;
		goblin.defense = 1;
		goblin.hp = 7;
		goblin.maxhp = 7;
		goblin.armor = 15;
		goblin.mp = 0;
		goblin.maxmp = 0;
	};
	stats orc;{
		orc.attack = 5;
		orc.maxdefense = 3;
		orc.defense = 3;
		orc.hp = 16;
		orc.maxhp = 16;
		orc.armor = 16;
		orc.mp = 0;
		orc.maxmp = 0;
	};
	srand (time(0));
	roll = (rand() % 3)+1;
	if (roll ==1){
		cout << "You are attacked by a Troll!" << endl;
		return troll;
	}
	else if (roll == 2){
		cout << "You are attacked by a Goblin!" << endl;
		return goblin;
	}
	else if (roll == 3){
		cout << "You are attacked by a Orc!" << endl;
		return orc;
	}
	else{
		cout << "You find nothing." << endl;
	}
}

int combat_system_mob (int atk, int armor, int health, int def, int maxhp)
	{
	int roll, damage;
	srand (time(0)+3);
	roll = (rand() % 20) + 1;
	if (roll == 20){
		int damage = (atk*2) - def;
		cout << "The monster attacks and get a critital\n";
		cout << "It hits you for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll+atk){
		int damage = atk - def;
		cout << "The monster hits for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor> roll+atk){
		cout << "The monster misses you." << endl;
	}
	return health;
}



//battle system for physical attacks options 1//
int combat_system_player (int atk, int armor, int health, int def, int maxhp)
{
	int roll, damage;
	srand (time(0));
	roll = (rand() % 20) + 1; //generates roll between 1 and 20
	if (roll == 20){ // if roll is a 20 they score a crit
		int damage = (atk*2) - def;
		cout << "You swing your sword and get a critital\n";
		cout << "You hit for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll+atk){
		int damage = atk - def;
		cout << "You hit for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor> roll+atk){
		cout << "You miss." << endl;
	}
	return health; //returns the health of mob after attack
}
/*

Work in progress of spell combat system

int magic_system_player (int atk, int armor, int health, int def, int maxhp)
{
	int roll, damage;
	srand (time(0));
	roll = (rand() % 20) + 1; //generates roll between 1 and 20
	if (roll == 20){ // if roll is a 20 they score a crit
		int damage = 1;
		cout << "The spell blows up in your face\n";
		cout << "You hit for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll+atk){
		int damage = atk - def;
		cout << "You hit for " << damage <<" points of damage \n";
		health = health - damage;

	}
	else if (armor> roll+atk){
		cout << "You miss." << endl;
	}
	return health; //returns the health of mob after attack
}
*/


int main ()
{
//sets game from start needed for switch//
bool game = true;
//needed for the switch//
int choice;
//monster turn//
int turn;
//needed for spells//
int spell;


stats mob
    {
    mob.attack = 8,//attack//
    mob.maxdefense = 2,//max defense for a reset defense after use of ward//
    mob.defense = 2,//defense//
    mob.hp = 10,//hp//
    mob.maxhp = 10,//maxhp used to reset hp when healing is adding//
    mob.mp = 0,
    mob.maxmp = 0,
    };

stats player
    {
    player.attack = 5,
    player.maxdefense = 5,
    player.defense = 2,
    player.hp = 20,
    player.maxhp = 20,
    player.armor = 0,
    player.mp = 15,
    player.maxmp =15
    };

magic cast
    {
    cast.fireball = 5,//fireball//
    cast.fireball_cost = 5,//fireball cost//
    cast.healing_touch = 10,//healing touch//
    cast.healing_touch_cost = 5,//healing touch cost//
    cast.ward = 3,//ward//
    cast.ward_cost = 3//ward cost//
    };
cout << "You run into a monster perpare for a fight." << endl;
mob = encounter();
while (game !=false)
    {
//first menu//
    cout << "\n";
    cout << "Player HP: " << player.hp << " / " << player.maxhp << " MP: " << player.mp << " / " << player.maxmp << endl;
    cout << "Mobs HP: "<< mob.hp << " / " << mob.maxhp << " MP: " << mob.mp << " / " << mob.maxmp << endl;;
    cout << "************************************* \n";
    cout << "What do you want to do \n";
    cout << "1 - Attack \n";
    cout << "2 - Defend \n";
    cout << "3 - Magic \n";
    cout << "4 - Run \n";
    cout << "************************************* \n";

    cin >> choice;
//end of first menu

switch (choice)//players options//
    {
        case 1://Attack option//
        {
        // call to the function that calculates combat when player attacks//
        mob.hp = combat_system_player(player.attack, mob.armor, mob.hp, mob.defense, mob.maxhp);
        turn = 1;
        }
        break;
        case 2://defend option the same as ward spell for now//
        {
        if (player.defense < player.maxdefense)
        {
        player.defense = cast.ward + player.defense;
        cout << "You prepare for the imcoming attack \n";
        turn = 1;
        }
        else
        {
        cout << "Your defense would go any higher \n";
        turn = 2;
        }
        }
        break;
        case 3://spell option//
        {
        cout << "What Spell do you want to use  \n";
        cout << "1 - Fireball \n";
        cout << "2 - Healing Touch \n";
        cout << "3 - Ward \n";
        cout << "4 - <- Back \n";

        cin >> spell;
            switch (spell) //start of spell submenu//
            {
                case 1://fireball spell//
                {

                 if (player.mp >= cast.fireball_cost)
                    {
                    player.mp = player.mp - cast.fireball_cost;
                    int damage = cast.fireball;
                    cout << "You shot a fireball from you hand \n";
                    cout << "You hit for " << damage <<" points of damage \n";
                    mob.hp = mob.hp - damage;
                    turn = 1;
                    }
                    else
                    {
                    cout << "You dont have enough MP to cast this spell. \n";
                    turn = 2;
                    }
                }
                break;

                case 2://healing spell need to fix hp overflow//
                {
                //need to add limit how much it heals//
                if (player.mp >= cast.healing_touch_cost)
                    {
                        if (player.hp < player.maxhp)
                        {
                        player.mp = player.mp - cast.healing_touch_cost;
                        player.hp = cast.healing_touch + player.hp;
                        cout << "You restore " << cast.healing_touch << " points of health \n";
                        turn = 1;
                        }
                        else
                        {
                        cout << "You already have full HP \n";
                        turn = 2;
                        }
                     }

                else
                    {
                    cout << "You dont have enough MP to cast this spell. \n";
                    turn = 2;
                    }
                    }

                break;

                case 3://ward spell need to fix defense overflow//
                {
                    if (player.mp >= cast.ward_cost)
                    {
                        if (player.defense < player.maxdefense)
                        {
                        player.mp = player.mp - cast.ward_cost;
                        player.defense = cast.ward + player.defense;
                        cout << "A magic arua surronds you. \n";
                        turn = 1;
                        }
                        else
                        {
                        cout << "Your defense would go any higher \n";
                        turn = 2;
                        }
                    }
                    else
                    {
                    cout << "You dont have enough MP to cast this spell. \n";
                    turn = 2;
                    }
                }


                break;

                case 4://back to first menu need to implement//
                {
                turn = 2;
                }
                }
                break;

            }//end of spell submenu//
        break;
        case 4://run away option//
        {
        cout << "You managed to run away" << endl;
        game = false;
        turn = 2;
        }
        break;
        case 5://secret end program//
        {
        cout << "Secret shut down operation activated";
        turn = 2;
        game = false;
        }
        break;
        default:
        {
        cout << "Not a valid choice. \n";
        cout << "Choose again. \n";
        turn = 2;
        }
        break;
    }//end of switch//

    switch (turn)//The mobs options
    {
    case 1://mobs attack//
        {
//code runs if the monster died but player still lives//
                    if(mob.hp <0 && player.hp >=1)
                    {
                    cout << "You defeated the monster" << endl;
                    game = false;
                    }
//code runs if mob has hp and player still has hp//
                    if(game = true && mob.hp >0 && player.hp >0)
                    {
                    // call to the fucntion that calculates combat when mob attacks//
                    player.hp = combat_system_mob(mob.attack, player.armor, player.hp, player.defense, player.maxhp);
                    }
//code runs if player dies and mob still has hp//
                    if (player.hp <= 0 && mob.hp >= 1)
                    {
                    cout << "game over \n";
                    game = false;
                    }
                    }
        break;
        case 2://blank line for the mob doing nothing//
        {
        cout << "             \n";
        }
        break;
        default:
        {
        cout << "mob switch is not working. \n";
        cout << "Please fix \n";
        }
        break;
        }//end of turn switch//






    }//end of while loop//

}//end of main//
