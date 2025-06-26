#include <iostream>
#include <cstdlib> 
#include <ctime>   


using namespace std;


int main() {
   srand(time(0)); 


   int player, computer;
   int card;
   char option;
   int hands = 3;
   int playerwins = 0;
   int computerwins = 0;
   int tie = 0;


   for(int hand=1; hand<=hands; hand++) {
       player = 0;
       computer = 0;


       cout << "hand " << hand << "\n";


      
       do {
           card = (rand() % 10) + 1; 
           player += card;
           cout << "You drew a card: " << card << ". Total: " << player << "\n";
           if(player >= 21) break;


           cout << "Do you want another card? (y/n): ";
           cin >> option;
       } while(option == 'y' || option == 'Y');


      
       while(computer < 17) {
           card = (rand() % 10) + 1;
           computer += card;
       }


       cout << "Computer points: " << computer << "\n";




       bool playerpast = (player > 21);
       bool computerpast = (computer > 21);


       if(playerpast && computerpast) {
           cout << "It is a draw: both players busted\n";
           tie++;
       } else if(playerpast) {
           cout << "Computer wins\n";
           computerwins++;
       } else if(computerpast) {
           cout << "You win\n";
           playerwins++;
       } else {
           if(player > computer) {
               cout << "You win\n";
               playerwins++;
           } else if(computer > player) {
               cout << "Computer wins\n";
               computerwins++;
           } else {
               cout << "Tie: same score\n";
               tie++;
           }
       }
       cout << "---------------------------\n";
   }


   cout << "Final results:\n";
   cout << "Player wins: " << playerwins << " hands\n";
   cout << "Computer wins: " << computerwins << " hands\n";
   cout << "Ties: " << tie << "\n";


   if(playerwins > computerwins)
       cout << "You won!\n";
   else if(computerwins > playerwins)
       cout << "Computer wins\n";
   else
       cout << "Game ends in a tie\n";


   return 0;
}
