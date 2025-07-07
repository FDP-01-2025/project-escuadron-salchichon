#include "historia.h"
#include "utils.h"
#include "gamestate.h"
#include <iostream>

using namespace std;

// This fuction is for a small introduction before the game starts
void introduction(GameState &state)
{
    slowPrint(" HISTORY OF CHEPE DUTY\n", 40);
    pause(1000);
    slowPrint(state.playerName + ", leader of the Apopa guerrilla, has been unjustly accused...", 30);
    pause(2000);
    slowPrint("President Cristiani blames him for a massacre against workers.", 30);
    pause(2000);
    slowPrint("Now, " + state.playerName + " must escape, recover evidence, and clear his name.", 30);
    pause(2000);
    cout << "\nPress ENTER to start...";
    cin.ignore();
    cin.get();
}

// This appears when you beat the Mine field.
void goodFinal(GameState &state)
{
    slowPrint("Congratulations!", 30);
    slowPrint(state.playerName + " managed to cross the minefield and found the documents that prove his innocence.", 30);
    slowPrint("The people now know the truth. Justice has triumphed!", 30);
    pause(3000);
}

// This appears when you lose the Mine field.
void badFinal(const string &reazon)
{
    gameOver(("You failed the duty...: " + reazon).c_str());
}

// This one is to show the first part ot the story
void storyStart(GameState &state){
    int option;
    int coffee;
    int fight = 0;
    
    // This are two structs used in this part
    struct Soldier
    {
        string name;
        string weaponType;
        int age;
    };

    struct Kid
    {
        string name;
        string weapon;
        int age;
    };

    Soldier alberto;
    alberto.name = "Albert";
    alberto.weaponType = "Pistol";
    alberto.age = 20;

    Kid luis;
    luis.name = "Luis";
    luis.weapon = "none";
    luis.age = 12;

    // The first dialogues and choices to make

    slowPrint("\n It was early in the morning, you were still half asleep.\n", 30);
    pause(1000);
    slowPrint("While you still could not differentiate between dream and reality, you hear loud knocking at the door.\n", 30);
    pause(1000);
    slowPrint("You don't know what to do, you are in a daze and the person outside is repeatedly yelling at you to open the door.\n", 30);
    pause(1000);
    slowPrint("There you get it, it's your right hand...\n", 30);
    cout << alberto.name;
    pause(1000);
    slowPrint("\n Do you want to open the door?\n", 30);
    pause(1000);
    slowPrint("   1. Yes, open the door.\n", 30);
    pause(1000);
    slowPrint("   2. No, do not open.\n", 30);
    pause(1000);
    slowPrint("Choose an option (1 or 2): ", 30);
    pause(1000);
    cin >> option;

    //First interaction in game, a switch to see if you open or no

    switch (option)
    {
    case 1:
        slowPrint("\nYou are on the other side to ", 30);
        cout << alberto.name;
        slowPrint(", very distressed and furious, holding a piece of paper.\n", 30);
        state.honor += 4;
        state.friendship += 1;
        saveProgress(state);
        break;
    case 2:
        slowPrint("\n ");
        cout << alberto.name;
        slowPrint(" shouts that it is urgent, and receiving no response, breaks down the door, entering and shaking you.\n", 30);
        state.honor -= 5;
        state.friendship -= 1;
        saveProgress(state);
        break;
    default:
        slowPrint("\n(INVALID OPTION). ", 10);
        cout << alberto.name;
        slowPrint(" decides to force his way in.\n", 30);
        state.honor -= 10;
        state.friendship -= 2;
        saveProgress(state);
        break;
    }

    slowPrint("\nYou ask him what's wrong, and he gives you the newspaper.\n", 30);
    pause(1000);

    slowPrint("\n", 30);
    pause(1000);
    slowPrint("+--------------------------------------------------------------------+\n", 10);
    pause(1000);
    slowPrint("|                            NEWSPAPER                               |\n", 10);
    pause(1000);
    slowPrint("|                                                                    |\n", 10);
    pause(1000);
    slowPrint("|   The leader of the Apopa guerrilla  is accused by the president of|\n", 10);
    pause(1000);
    slowPrint("|            ordering the killing of a group of peasants.            |\n", 10);
    pause(1000);
    slowPrint("|                                                                    |\n", 10);
    pause(1000);
    slowPrint("+--------------------------------------------------------------------+\n", 10);
    pause(1000),

        slowPrint("\n You only need to read the headline to realize where all of this was going...", 30);
    pause(1000);
    slowPrint("It took you a while, but you recover and walk outside... ", 30);
    pause(1000);

    cout << alberto.name;
    slowPrint(" asks you if you want a coffee to swallow all of this... Accept a coffee? (1.Yes/2.No)", 30);
    cin >> coffee;

    // Another choice, stil with Albert, this time for coffee

    switch (coffee)
    {
    case 1:
        cout << alberto.name;
        slowPrint(" goes to the kitchen, you wait right outside of your room \n", 30);
        pause(1000);
        slowPrint("After a while ", 30);
        cout << alberto.name;
        slowPrint(" shouts that there is no more coffee... or food at all\n", 30);
        pause(1000);
        slowPrint("...And suggests you should go buy more at the town center.", 30);
        pause(1000);
        state.friendship += 3;
        state.honor += 4;
        saveProgress(state);
        break;
    case 2:
        slowPrint("\n ", 5);
        cout << alberto.name;
        slowPrint(" suggests that you should go to the center of the town to see the mood around after the news.\n", 30);
        pause(1000);
        state.friendship -= 1;
        state.honor -= 1;
        saveProgress(state);
        break;
    default:
        slowPrint("\n(INVALID OPTION). You walk outside of your house for fresh air.\n", 30);
        pause(1000);
        state.friendship -= 2;
        state.honor -= 5;
        saveProgress(state);
        break;
    }

    // After those choices, the game leads you to a third one ehile giving context

    slowPrint("\n Now, you find yourself walking alone in the forest, on your way to the town... when something suddenly hits you.", 30);
    pause(1000);
    slowPrint("\nIt is a kid... trying to steal from you... without a weapon.", 30);
    pause(1000);
    slowPrint("\nGive some money to this kid? (1.Yes/2.No)", 30);
    pause(1000);
    cin >> fight;

    //First encounter with a major decition, give or hit.

    switch (fight)
    {
    case 1:
        slowPrint("\nYou decide to give this kid some money... he does not fight and leaves.", 30);
        pause(1000);
        if (state.honor > -200 && state.honor <= 100)
        {
            state.honor += 10;
            saveProgress(state);
        }
        break;
    case 2:
        slowPrint("\n You do not support this and choose to fight. The kid runs after the first hit.\n", 30);
        pause(1000);
        if (state.honor > -200 && state.honor <= 100)
        {
            state.honor -= 10;
            saveProgress(state);
        }
        break;
    default:
        slowPrint("\n(INVALID OPTION). You choose to fight. The kid runs after the first hit.\n", 30);
        pause(1000);
        if (state.honor > -200 && state.honor <= 100)
        {
            state.honor -= 15;
            saveProgress(state);
        }
        break;
    }

    //Some more context and end of the first part, before the levels

    slowPrint("\n That kid was surely something... You keep walking, but in a moment, you see them... soldiers in the town.", 30);
    pause(1000);
    slowPrint("\nYou just need to see one to know they are there for you... And you do not have any weapon... and then... He sees you.", 30);
    pause(1000);
    slowPrint("\nYou run... what else could you do? But then... you remember, in the forest, you did hide some weapons...", 30);
    pause(1000);
}


    //After the first level, this fuction shows what goes next
void storyContinuation(GameState &state){

    //Just a small if, uses the honor to see how good person you are

    if (state.honor >= 25)
    {
        slowPrint("That forest experience was something...and now, you are in their hands...", 30);
        pause(1000);
        slowPrint("But...then you hear it, all the villagers screaming for you", 30);
        pause(1000);
        slowPrint("But the soldiers...started shooting...and in all the mess...you scape", 30);
        pause(1000);
        slowPrint("But...you want revenge for all these people...you take a hat from a fallen soldier...and go to their base", 30);
        pause(1000);
    }
    else
    {
        slowPrint("You are in enemies hands now...all the villagers watch in silence as they take you to their base", 30);
        pause(1000);
        slowPrint("In a moment...you free from them...but to scape now, you need the key in the main house...Cristiani's house", 30);
        pause(1000);
    }

    //Last lline before the continuation ends

    slowPrint("In a blink of an eye...you are near Cristiani's door...", 30);
    pause(1000);
}

    // We are near the story end, this next part goes after the second level

void almostFinal(GameState &state)
{
    slowPrint("You are inside the room now...but you do not like what you see.", 30);
    pause(1500);
    slowPrint("It is him...Cristiani, you can only stare and hear.", 30);
    pause(1000);
}

    //And now, the end is near, and this fuction shows it

void Final(GameState &state)
{

    //We have the strcut for Cristiani, the final boss

    struct Cristiani
    {
        string name;
        string cweapon;
        int damage;
        int health;
    };

    Cristiani p;
    p.name = "Cristiani";
    p.cweapon = "Hands";
    p.damage = 0.5;
    p.health = 10;

    int coward;
    char shoot;
    int battle;

    //All of this goes after the third level, here, you run home

    slowPrint("And now...you are outside his house...you walk outside the base..but as you step outside...the soldiers start running at you", 30);
    pause(1000);
    slowPrint("You know there is nothing to do but run...so you run", 30);
    pause(1000);
    slowPrint("The only place you know is home...and even tho it is dangerous...you go there", 30);
    pause(1000);
    slowPrint("As you arrive...you see Albert, holding a shootgun.", 30);
    pause(1000);

    //In this part, if you did good with Albert, he will help you if you need it

    if (state.friendship >= 3)
    {
        slowPrint("Albert screams at you to get inside....as soon as you enter..the shooting starts", 30);
        pause(1000);
        slowPrint("Albert gets injured...he screams you have to run...and he stares at you...", 30);
        pause(1000);
        slowPrint("will you try to help, or run as a coward? (1.Help, 2.Coward)", 30);
        cin >> coward;

        switch (coward)
        {
        // Here you try to help him
        case 1:
            slowPrint("You will not just go...and take the shootgun to cover him...", 30);
            pause(1000);

            slowPrint("Shoot? (y/n)", 30);
            cin >> shoot;
            //You already choosed to help him, you now can shoot or not
            do
            {
                cout << "Do you want to shoot? (y/n): ";
                cin >> shoot;

                if (shoot == 'y' || shoot == 'Y')
                {
                    if(state.score <= 29){
                    slowPrint("You decided to shoot... but because of the nerves, the knockback hurts your arm.", 30);
                    state.health -= 1;
                    state.honor += 30;
                    state.friendship += 20;
                    pause(1000);
                    }else if(state.score >=30){
                    slowPrint("You decided to shoot..and with experience, you hit a soldier without getting hurt",30);
                    state.honor +=30;
                    state.friendship += 20;
                    pause(1000);
                    }

                }
                else if (shoot == 'n' || shoot == 'N')
                {
                    state.honor += 10;
                    state.friendship += 2;
                    slowPrint("You decide not to shoot.", 30);
                    pause(1000);
                }
                else
                {
                    cout << "Invalid option.\n";
                    slowPrint("You decide not to shoot.", 30);
                    pause(1000);
                    state.honor -= 10;
                    state.friendship -= 2;
                }
            } while (shoot != 'y' && shoot != 'Y' && shoot != 'n' && shoot != 'N');
            //Still, you could not save him
            pause(1000);
            slowPrint("But...there is nothing you can do.....they are still comming...", 30);
            pause(1000);
            slowPrint("Albert: Just run and do not look back...If you really care oabout our friendship, run away.", 30);
            //Here is where he helps you if you need it, gives you a weapon
            if(state.weapon == 0){
            slowPrint("Albert: And take this....",30);
            state.weapon += 1;
            }

            pause(1000);
            slowPrint("And so...you start running, you hear them still shooting at Albert...", 30);
            break;

        case 2:
            //Here you show how coward you are, and decide to run
            slowPrint("He did not even said his sentence when you started running", 30);
            pause(1000);
            state.honor -= 30;
            state.friendship -= 10;
            slowPrint("As you run..the fear makes you see things..all the trees have a word writen in them...COWARD", 30);
            break;

        default:
            //If you try to be funny, this will show
            slowPrint("You are just a coward.", 30);
            state.honor -= 40;
            state.friendship -= 15;
            break;
        }
    }// If you did not made it right with Albert, this will happen
    else if (state.friendship <= 1)
    {
        slowPrint("Albert screams at you to stop....and he points the shootgun at you.", 30);
        pause(1000);
        slowPrint("You run away from there...you do not know what happened..you just hear, and feel a shot in your arm, it does not stop you...", 30);
        state.health -= 2;
        pause(1000);
    }


    //If you won the first level, or if Albert gave you the knife, this shows
    if (state.weapon == 1)
    {
        slowPrint("You are now in the forest...injured and alone..with a knife.", 30);
        pause(1000);
        slowPrint("You see some fruits in a tree..and take them", 30);
        pause(1000);

        state.food += 3;

        slowPrint("But... suddenly, Cristiani arrives, he is holding a gun..a shootgun...Albert's shootgun.", 30);
        pause(1000);
        slowPrint("Cristiani: This is it...this is the end " + state.playerName, 30);
        pause(1000);
        slowPrint(state.playerName + ": You...you are a coward!! Using a shootgun against an injured man with only a knife!?", 30);
        pause(1000);
        slowPrint("Those words came from your heart...and he, smirks", 30);
        pause(1000);
        slowPrint("Cristiani: If you want a 1 v 1 fight, I will give it to you...consider it as a last wish...", 30);
        state.currentStage = 4;
        saveProgress(state);

        slowPrint("THE FINAL FIGHT STARTED", 30);
        pause(1000);
        //Here starts the fight, you can protect, figtht or use an item
        while (p.health > 0 && state.health > 0)
        {

            cout << "What will you do?\n";

            cout << " +---------------------------+ \n";
            cout << " | 1.Fight.                  | \n";
            cout << " | 2.Bag.                    | \n";
            cout << " | 3.Protect                 | \n";
            cout << " +---------------------------+ \n";
            cin >> battle;

            cout << "\n";

            switch (battle)
            {

            case 1:
                slowPrint("You choose to fight", 30);
                p.health -= 2.0;
                if (p.health < 0){
                    p.health = 0;}
                slowPrint(" You hit the enemy for 2 damage!", 30);
                break;

            case 2:

                if (state.food > 0)
                {
                    slowPrint("You try to use an item, but the enemy takes the opportunity to attack you!", 30);
                    state.health += 1;
                    state.health -= 0.5;
                    state.food -= 1;
                }
                else
                {
                    slowPrint("You do not have any item, the enemy takes the opportunity to attack you!", 30);
                    state.health -= 0.5;
                }
                break;

            case 3:

                slowPrint("You defend, but the enemy still manages to scratch you.", 30);
                state.health -= 0.2;

                break;

            default:
                slowPrint("INVALID OPTION, You did nothing and took damage", 30);
                state.health -= 0.5;
            }
        }
// If the boss runs out of health, you win
if(state.health >0 && p.health <0){
slowPrint("You...You won, for you, for the town...for Albert.",30);
pause(1000);
slowPrint("The last problem you have to face is...the landmines...",30);
pause(1000);
// If the you run out of health, he wins
}else if(state.health < 0 && p.health > 0){
slowPrint("You did all you could....but it was not enough...",30);
pause(1000);
slowPrint("Cristiani: One more or one less...no one cares.",30);
pause(1500);
return;
}
// If you failed the first and Albert did not gave you a weapon, this happens
}else if(state.weapon == 0){

    slowPrint("You are now in the forest...injured and alone..unarmed.", 30);
    pause(1000);
    slowPrint("You see some fruits in a tree..and take them", 30);
    pause(1000);

    state.food += 3;

    slowPrint("But... suddenly, Cristiani arrives, he is holding a gun..a shootgun...Albert's shootgun.", 30);
    pause(1000);
    slowPrint("Cristiani: This is it...this is the end " + state.playerName, 30);
    pause(1000);
    slowPrint(state.playerName + ": There is no need for this...why are you doing this!?", 30);
    pause(1000);
    slowPrint("Cristiani:Because I know you would do the same if you could..", 30);
    pause(1000);
    slowPrint("Cristiani aims...and shoots, but no bullet came out...he looks at the shootgun angry...but you can run now", 30);
    state.currentStage = 4;
    saveProgress(state);
}
}
