/*******************************************************************************************************
**Program: Combat Engine
**Author: Clint Levitski, Kevin Feyder
**Date: 11/05/14
**Description: Very basic turned based combat system. Taking pull from a lot of fantasy tabletop rpg
** elements.
**Input: Basic numbers denoted in menu choices.
**Output: Damage dealt to player and monster
*******************************************************************************************************/

#include <iostream>
#include "encounter.h"
#include "combat.h"
#include "story.h"
#include "magic.h"
using std::cout;
using std::endl;
using std::cin;

int main(){
	bool game = true;	//loops game until either monster or player is dead.
	int choice;		//used in the outer menu switch.
	int spell;		//used in the spell menu switch.
	int damage;		//holds damage to be subtracted from hp.

	stats mob;
	mob.attack = 0;			//attack damage
	mob.maxdefense = 0;		//max defense for a reset defense after use of ward.
	mob.defense = 0;		//defense.
	mob.hp = 0;			//current hit points.
	mob.maxhp = 0;			//maximum hit points a creature can have.
	mob.armor = 0;			//subtracts from damage before it is applied to hp.
	mob.mp = 0;			//magic points.
	mob.maxmp = 0;			//maximum magic points a creature can have.

	stats player;
	player.attack = 5;
	player.maxdefense = 5;
	player.defense = 2;
	player.hp = 20;
	player.maxhp = 20;
	player.armor = 0;
	player.mp = 15;
	player.maxmp = 15;

	magic spellbook;
	spellbook.fireball = 5;			//fireball damage
	spellbook.fireball_cost = 5;		//fireball mp cost
	spellbook.healing_touch = 10;		//healing touch damage
	spellbook.healing_touch_cost = 5;	//healing touch mp cost
	spellbook.ward = 3;			//ward amount added to armor
	spellbook.ward_cost = 3;		//ward mp cost

	cout << "You run into a monster perpare for a fight." << endl;
	mob = encounter();
	while (game != false){
		//first menu//
		cout << "\n";
		cout << "Player HP: " << player.hp << " / " << player.maxhp << " MP: " << player.mp << " / " << player.maxmp << endl;
		cout << "Mobs HP: " << mob.hp << " / " << mob.maxhp << " MP: " << mob.mp << " / " << mob.maxmp << endl;;
		cout << "************************************* \n";
		cout << "What do you want to do \n";
		cout << "1 - Attack \n";
		cout << "2 - Defend \n";
		cout << "3 - Magic \n";
		cout << "4 - Run (This doesn't work don't use) \n";
		cout << "************************************* \n";

		cin >> choice;
		//end of first menu
		switch (choice){//players options//
		case 1://Attack option//
			// call to the function that calculates combat when player attacks//
			mob.hp = combat_system_player(player.attack, mob.armor, mob.hp, mob.defense, mob.maxhp);
			break;
		case 2://defend option the same as ward spell for now//
			if (player.defense < player.maxdefense){
				player.defense = spellbook.ward + player.defense;
				cout << "You prepare for the imcoming attack \n";
			}
			else{
				cout << "Your defense would go any higher. \n";
			}
			break;
		case 3://spell option//
			cout << "************************************* \n";
			cout << "What Spell do you want to use.  \n";
			cout << "1 - Fireball \n";
			cout << "2 - Healing Touch \n";
			cout << "3 - Ward \n";
			cout << "4 - <- Back \n";
			cout << "************************************* \n";

			cin >> spell;
			switch (spell){ //start of spell submenu//
			case 1://fireball spell//
				fireball(spellbook.fireball_cost, player.mp, spellbook.fireball, mob.hp, mob.armor, mob.defense);
				break;
			case 2://Healing Touch spell
				healing(spellbook.healing_touch_cost, player.mp, spellbook.healing_touch, player.maxhp, player.hp);
				break;
			case 3://Ward spell
				ward(spellbook.ward_cost, player.mp, spellbook.ward, player.maxdefense, player.defense);
				break;
			case 4://back to first menu need to implement
				break;
			default:
				break;
			}//end of spell submenu
		default:
			break;
		}//end of player switch

		//code runs if the monster died but player still lives
		if (mob.hp <0 && player.hp >= 1){
			cout << "You defeated the monster" << endl;
			game = false;
		}
		//code runs if mob has hp and player still has hp
		else if (game = true && mob.hp > 0 && player.hp > 0){
			// call to the fucntion that calculates combat when mob attacks
			player.hp = combat_system_mob(mob.attack, player.armor, player.hp, player.defense, player.maxhp);
			if (player.hp <= 0){
				cout << "You have been defeated." << endl;
				game = false;
			}
		}
		//code runs if player dies and mob still has hp
		else if (player.hp <= 0 && mob.hp >= 1){
			cout << "You have been defeated. \n";
			game = false;
		}
	}//end of game loop
	cout << endl << "This Chapter is over." << endl;
	cin >> damage;
	return 0;
}//end of main
