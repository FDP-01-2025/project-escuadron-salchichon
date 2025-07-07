[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# C++ PROJECT- CHEPE DUTY


## PROJECT DESCRIPTION


Our project consists of a visual novel type game set in the time of the civil war in El Salvador, we take the role of a guerrilla leader who comes face to face with President Cristiani. It contains fights, decision making and different ways to increase honor or friendship. The game uses all the themes we saw in class, to expose the story, make it interactive and demonstrate that we learned how to use them.


Our project has many Themes and Settings:


1.Albert house: A house, owned by Albert, a friend of our protagonistt.
2.The forest: A forest between Albert house and the main town.
3.The main town: The town where all the villagers live.
4.Military base: The place where Cristiani's house is.


## MAIN MECHANIC:


Narrative adventure game with branching choices that affect attributes and unlock different endings, combined with exploration mini-games (knife-finding, password guessing) and turn-based combat.


## General idea of gameplay:


The gameplay mixes interactive narrative reading, decisions that affect variables, mini-games of exploration and precision, and strategic turn-based combat.


## Application of the topics discussed (one by one with examples):


1. Conditional structures:
We use them right at the beggining, when we ask the player if he wantss to load the game, and in the first interaction with Albert.


if (loadChoice == 1) {  // Load progress
       loadProgress(state);
       slowPrint("Game loaded. Continue...", 30);
   } else {  // The game starts here
       state = GameState();


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




2. Cycles:
We use cycles a lot, like when the game is near the end, and you decide to shoot.


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


3. Functions:
We use void a lot, the example will be a short one that is near the end.


void almostFinal(GameState &state)
{
   slowPrint("You are inside the room now...but you do not like what you see.", 30);
   pause(1500);
   slowPrint("It is him...Cristiani, you can only stare and hear.", 30);
   pause(1000);
}


4. Data structures:
We use a lot of structs, the main antagonist one.


struct Cristiani
   {
       string name;
       string cweapon;
       int damage;
       int health;
   };


5. File handling:
We use ifstram and ofstream, the example will be ofstream.


void saveProgress(const GameState& state) {
   ofstream file("savegame.txt");
   if (file.is_open()) {
       // Writes all the parts that want to be saved
       file << "PlayerName: " << state.playerName << "\n"
            << "Honor: " << state.honor << "\n"
            << "Score: " << state.score << "\n"
            << "Lives: " << state.lives << "\n"
            << "CurrentStage: " << state.currentStage << "\n"
            << "Friendship: " << state.friendship << "\n"
            << "Weapon: " << state.weapon << "\n"
            << "Health: " << state.health << "\n"
            << "Food: " << state.food << "\n";
       file.close();
       cout << "Progress saved successfully.\n";
   } else {
       cerr << "Error: Could not save progress.\n";
   }
}


6. Error handling:
We can use the same example as before, because we use an if to decide what happens if there is a mistake.


void saveProgress(const GameState& state) {
   ofstream file("savegame.txt");
   if (file.is_open()) {
       // Writes all the parts that want to be saved
       file << "PlayerName: " << state.playerName << "\n"
            << "Honor: " << state.honor << "\n"
            << "Score: " << state.score << "\n"
            << "Lives: " << state.lives << "\n"
            << "CurrentStage: " << state.currentStage << "\n"
            << "Friendship: " << state.friendship << "\n"
            << "Weapon: " << state.weapon << "\n"
            << "Health: " << state.health << "\n"
            << "Food: " << state.food << "\n";
       file.close();
       cout << "Progress saved successfully.\n";
   } else {
       cerr << "Error: Could not save progress.\n";
   }
}


7. Console interface:
We use a lot of cin for the player to enter things, and cout/slowPrint to show messages.


slowPrint("\n Now, you find yourself walking alone in the forest, on your way to the town... when something suddenly hits you.", 30);
   pause(1000);
   slowPrint("\nIt is a kid... trying to steal from you... without a weapon.", 30);
   pause(1000);
   slowPrint("\nGive some money to this kid? (1.Yes/2.No)", 30);
   pause(1000);
   cin >> fight;


## TECHNICAL DEVELOPEMENT CONSIDERATIONS:


1. Lenguage and enviroment:


We used c++ as it was the language we used in class


We made all the code in visual studio code.


2. Modularity


The code was split into multiple files (.h and .cpp) according to responsibility:


historia.cpp: story and narrative.


level1.cpp, level2.cpp, level3.cpp: individual levels.


utils.cpp: utility functions (pause, slow printing).


gamestate.cpp: game state management and save/load progress.


3. Interaction


All interface is console-based, with menus, numbered options and input validation.


### RECOMENDATIONS


1. Please, if the game ask you to do something, do it as it said, because if you try to do other things, it will take more honor than
if you just fail or choose a bad option.


2. Please wait until the game ask you to do something, if you do not wwait, it will also be taken as an invalid option.




### MOCKUPS


1.The forest:




                     #########                                         
                    ###########                           ###         ###
         ###       #############                         #####       #####
        #####       ###########                         #######     #######
       #######       #########                            ###         ###
         ###            | |                ######          |         # | /
          |/            | |               ########         |          \|/
          |             | |                ########        |           |


2.Military base:


      \|/
       |
 /‾‾‾‾‾‾‾‾‾‾‾‾‾‾\      /‾‾‾‾‾‾‾‾‾‾‾‾\       /‾‾‾‾‾‾‾‾‾‾‾‾\
/      /\        \    /              \     /              \
|     |  |       |    |              |     |              |
|_____|__|_______|    |______________|     |______________|






## TEAM


- **TEAM NAME:** Escuadron salchichon.


### TEAM MEMBERS:


1. **Complete Name:** Mauricio Ernesto Hernandez Marroquin.
  **Carnet:** 00013525.


2. **Complete Name:** Oscar Lizandro Escobar Sibrian 
  **Carnet:** 00019025

## EXECUTION INSTRUCTIONS:


1. Clone this repository on your local machine:
  ```bash
  git clone [Repository URL]


2. Enter vscode and search for the folder of the repository.


3. Open the Folder, you will see a file named main.cpp


4. Enter that file and use the terminal, you will have to write "g++ main.cpp -o [.exe name]"


5. The game will start just like that.