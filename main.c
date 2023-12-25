#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Player{
	char name[10];
	int hp;
	int atk;
	int spd;
};

struct Monster{
	char name[10];
	int hp;
	int atk;
	int spd;
};

int randomNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int playerAttack(int playerAttackPower) {
    return randomNum(playerAttackPower - 5, playerAttackPower + 5);
}

int enemyAttack(int enemyAttackPower) {
    return randomNum(enemyAttackPower - 3, enemyAttackPower + 3);
}

void monsterTurn(char name[], int *playerHP, int *playerAtk, int *enemyHP, int *enemyAtk) {
    int action = randomNum(1, 3);

    switch (action){
        case 1: //attack
            printf("%s attacks!\n", name);
            int enemyDamage = enemyAttack(*enemyAtk);
            printf("%s deals %d damage!\n\n", name, enemyDamage);
            *playerHP -= enemyDamage;
            break;
        case 2: //guard
            printf("%s guards and lowers your attack!\n\n", name);
            *playerAtk -= 3;
            break;
        case 3: //heal
            printf("%s heals!\n", name);
            int enemyHeal = randomNum(5, 10);
            printf("%s heals for %d health!\n\n", name, enemyHeal);
            *enemyHP += enemyHeal;
            break;
    }
}

void battle(char player[], char enemy[], int *playerHP, int *playerAtk, int *enemyHP, int *enemyAtk){
    int round = 1;
    int action;

    while (*playerHP > 0 && *enemyHP > 0) {
        printf("---Round %d---\n", round);

        // Player's turn
        printf("%s HP: %d, Attack Power: %d\n", player, *playerHP, *playerAtk);
        printf("%s HP: %d, Attack Power: %d\n", enemy, *enemyHP, *enemyAtk);
        printf("Choose an action \n");
        printf("1) Attack\n");
        printf("2) Guard\n");
        printf("3) Heal");
        printf("\nChoose your action: "); scanf("%d", &action); printf("\n");
        
        int playerDamage = playerAttack(*playerAtk);
        int playerHeal = randomNum(5, 20);
        
        
        switch(action){
        	case 1: //attack
        		printf("%s attack for %d damage!\n\n", player, playerDamage);
        		*enemyHP -= playerDamage;
        		break;
        	case 2: //guard
        		printf("%s guards and lowers %s attack!\n\n", player, enemy);
            	*enemyAtk -= 3;
            	break;
            case 3: //heal
            	printf("%s heals!\n", player);
        	    printf("%s heals for %d health!\n\n", player, playerHeal);
            	*playerHP += playerHeal;
            	break;
		}

        if (*enemyHP <= 0) {
            printf("%s defeated! You win!\n", enemy);
            break;
        }

        // Slime's turn
        printf("%s HP: %d\n", enemy, *enemyHP);
        monsterTurn(enemy, playerHP, playerAtk, enemyHP, enemyAtk);

        if (*playerHP <= 0) {
            printf("You were defeated! %s wins!\n", enemy);
            break;
        }
        getch(); system("cls");

        round++;
    }
}


int main(){
	int choiceMenu, choice1, choice2, role;
	struct Player player;
	struct Monster monster;
//	struct Fighter fighter;
//	struct Hero hero;

	srand(time(NULL));

    // Generate a random number between 1 and 100
//    int randomNumber = rand() % 100 + 1;
	
	mainmenu:
	printf("\tWelcome to Simple Fighting Game\n\n");
	printf("1) START\n");
	printf("0) QUIT\n");
	printf("Choose your options: "); scanf("%d", &choiceMenu); printf("\n");
	
	switch (choiceMenu){
		case 1:
			system("cls");
			printf("\tWelcome to Simple Fighting Game\n\n");
			printf("---Main Menu---\n");
			printf("1) New Game\n");
			printf("2) Highscore\n");
			printf("0) Back\n");
			printf("Choose your option: "); scanf("%d", &choice1); printf("\n");
			break;
		case 0:
			printf("Thanks for playing!\n");
			return 1;
		default:
			system("cls");
			printf("Please choose from the above options...\n\n\n");
			goto mainmenu;
	}
	
	if(choice1==1){
		system("cls");
		printf("\tWelcome to Simple Fighting Game\n\n");
		printf("---NEW GAME---\n");
		printf("Choose your role:\n");
		printf("1) Archer\n");
		printf("2) Fighter\n");
		printf("3) Hero\n");
		printf("0) Back\n");
		printf("Choose your option: "); scanf("%d", &role); printf("\n");
	} else if(choice1==2){
		printf("ua");
		// nanti tambahin opsi load file
	} else if(choice1==0){
		system("cls");
		goto mainmenu;
	} else{
		system("cls");
		printf("Please choose from the above options...\n\n\n");
		goto mainmenu;
	}
	
	switch(role){
		case 1:
			strcpy(player.name, "Archer");
			player.hp = 75;
			player.atk = 25;
//			player.spd = 70;
			break;
		case 2:
			strcpy(player.name, "Fighter");
			player.hp = 120;
			player.atk = 10;
//			player.spd = 35;
			break;
		case 3:
			strcpy(player.name, "Hero");
			player.hp = 90;
			player.atk = 30;
//			player.spd = 60;
			break;
		case 0:
			system("cls");
			goto mainmenu;
		default:
			system("cls");
			printf("Please choose from the above options...\n\n\n");
			goto mainmenu;
	}
	
	system("cls");
	printf("---GAME START---\n\n");
	
	if(role==1){
		printf("Archer is an agile combatant, relying on his ranged attack and speed to win.\n\n"); getch();
		printf("This is your warrior stats,\nClass: %s\nHP: %d\nAtk: %d\n", player.name, player.hp, player.atk); getch();
	} else if(role==2){
		printf("Fighter is a tanky combatant, relying on his toughness to win.\n\n"); getch();
		printf("This is your warrior stats,\nClass: %s\nHP: %d\nAtk: %d\n", player.name, player.hp, player.atk); getch();
	} else {
		printf("Hero is an all-rounder combatant, relying on both his toughness and speed to win.\n\n"); getch();
		printf("This is your warrior stats,\nClass: %s\nHP: %d\nAtk: %d\n", player.name, player.hp, player.atk); getch();
	}
	
	// This one is an rpg route and it might take too long to finish so we'll choose the alternative where player just fight
//	printf("\n\nYou enter the dungeon to seek for treasure, the dungeon is dark and evil.\n\n"); getch();
//	int monsterNum = rand() % 4 + 1;
//	printf("Suddenly a\n"); getch();
	int opponent;
	
	fight:
	printf("\n\nChoose your opponent:\n");
	printf("1) Slime\n");
	printf("2) Goblin\n");
	printf("3) Demon\n");
	printf("Choose your option: "); scanf("%d", &opponent); printf("\n");
	
	switch(opponent){
		case 1:
			strcpy(monster.name, "Slime");
			monster.hp = 25;
			monster.atk = 10;
//			monster.spd = 20;
			break;
		case 2:
			strcpy(monster.name, "Goblin");
			monster.hp = 50;
			monster.atk = 25;
//			monster.spd = 45;
			break;
		case 3:
			strcpy(monster.name, "Demon");
			monster.hp = 100;
			monster.atk = 40;
//			monster.spd = 70;
			break;
		default:
			system("cls");
			printf("Please choose from the above options...\n\n\n");
			goto fight;
	}
	
//	int turn
	
	system("cls");
	battle(player.name, monster.name, &player.hp, &player.atk, &monster.hp, &monster.atk);
//	printf("---Round %d---\n\n", turn);
//	printf("1) Slime\n");
//	printf("2) Goblin\n");
//	printf("3) Demon\n");
//	printf("Choose your option: "); scanf("%d", &opponent); printf("\n");
	
//	printf("Class:%s\nHP:%d\nAtk:%d\nSpd:%d", player.name, player.hp, player.atk, player.spd);
//	printf("\n");
	
	return 0;
}
