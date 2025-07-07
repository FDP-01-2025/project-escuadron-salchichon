#include <iostream>
#include <string>
using namespace std;




// Struct for a soldier
struct Soldado {
  string nombre;
  string categoriaArma;
  int edad;
};


struct Kid {
   string name;
   string weapon;
   int edad;
};


//Username part
int main() {


   string name;
   string surname;
   int option;
   int coffee;
   char confirmation;
   int honor = 0;
   int fight = 0;
   cout << "Do you want to enter a name or use the default name? (1.Enter a name / 2.Default)";
   cin >> option;
 
   switch(option) {
   case 1:
         
       do {
           cout << "Enter the character name: " << endl;
           cin >> name;
           cout << "Enter the character surname: " << endl;
           cin >> surname;
           cout << "Are you sure you want to use " << name << " " << surname << "? (y/n): ";
           cin >> confirmation;
       } while (confirmation != 'y' && confirmation != 'Y');
     
       break;
   case 2:
          name = "Chepe";
          surname = "Buquele";
           cout << "You are " << name <<" "<<surname<< " now"<<endl;
         
          break;
   default:
           cout << "(INVALID OPTION). The default name will be used."<<endl;
           name = "Chepe";
           surname = "Buquele";
           break;
   }
   cout << "Welcome to the start of your story " << name <<" "<<surname<< ". Good luck in this big world" << endl;
//call of structs
  Soldado alberto;
  alberto.nombre = "Albert";
  alberto.categoriaArma = "Pistol";
  alberto.edad = 20;


  Kid Luis;
  Luis.name = "Luis";
  Luis.weapon = "none";
  Luis.edad = 12;
//first dialogues




  cout << "\n It was early in the morning, you were still half asleep.\n";
  cout << "While you still could not differentiate between dream and reality, you hear loud knocking at the door.\n";
  cout << "You don't know what to do, you are in a daze and the person outside is repeatedly yelling at you to open the door.\n";
  cout << "There you get it, it's your right hand, " << alberto.nombre << "...\n";




  int opcion;
  cout << "\n Do you want to open the door?\n";
  cout << "   1. Yes, open the door.\n";
  cout << "   2. No, do not open.\n";
  cout << "Choose an option (1 or 2): ";
  cin >> opcion;




  switch(opcion) {
      case 1:
          cout << "\nYou are on the other side to " << alberto.nombre << ", very distressed and furious, holding a piece of paper.\n";
          break;
      case 2:
          cout << "\n " << alberto.nombre << " shouts that it is urgent, and receiving no response, breaks down the door, entering and shaking you.\n";
          break;
      default:
          cout << "\n(INVALID OPTION). " << alberto.nombre << " decides to force his way in.\n";
          break;
  }




  cout << "\nYou ask him what's wrong, and he gives you the newspaper.\n";




  // Dibujar el periodico
  cout << "\n";
  cout << "+----------------------------------------------+\n";
  cout << "|                NEWSPAPER                     |\n";
  cout << "|                                              |\n";
  cout << "|  " << name <<" "<< surname << " is accused by the president of|\n";
  cout << "|  ordering the killing of a group of peasants.|\n";
  cout << "|                                              |\n";
  cout << "+----------------------------------------------+\n";


  cout <<"\n You only need to read the headline to realize where all of this was going...";
  cout <<"It took you a while, but you recover and walk outside... ";


  cout << alberto.nombre << " Ask you if you want a coffee to swallow all of this...Accept a coffee? (1.Yes/2.No)";
  cin >> coffee;


  switch(coffee) {
   case 1:
       cout <<  alberto.nombre <<" goes to the kitchen, you wait right outside of your room " << endl;
       cout << "After a while "<< alberto.nombre <<"shouts that there is no more coffee..or food at all"<< endl;
       cout << "...And sugests you should go buy more at the town center."<<endl;
 
   break;
   case 2:
       cout << "\n " << alberto.nombre << " sugests that you should go to the center o f the town, to see the mood around after the new\n";
       break;
   default:
       cout << "\n(INVALID OPTION). " << " You walk outside of your house for fresh air\n";
       break;
}






   cout << "\n Now, you find yourself walking alone in the forest, in your way to the town...when something suddenly hits you.";


   cout << "It is a kid...trying yo steal from you...without a weapon";


   cout << "Give some money to this kid? (1.Yes/2.No)"<<endl;
   cin >> fight;


   switch(fight) {
       case 1:
           cout << " You decide to give this kid some money...he does not fight and leave " << endl;
           if(honor > -200 && honor <=100){
           honor += 10;}
       break;
       case 2:
           cout << "\n You do not support this..and choose to fight, the kid runs after the first hit.\n";
           if(honor > -200 && honor <=100){
           honor -= 10;}
           break;
       default:
           cout << "\n(INVALID OPTION). " << " You choose to fight, the kid runs after the first hit.\n";
           if(honor > -200 && honor <=100){
           honor -= 15;}
           break;
   }
  
   cout << "\n That kid was surely a thing...You keep walking..but, in a moment...you see it..soldiers in the town.";
   cout << "You just need to see one to know they are there for you...And you do not have any weapon..and then..He sees you";
   cout << "You run...what else could you do? But then...you remeber, in the forest, you did hide some weapons..."


  return 0;
}
