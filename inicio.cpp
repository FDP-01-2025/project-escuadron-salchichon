#include <iostream>
#include <string>
using namespace std;


// Definir la estructura Soldado
struct Soldado {
   string nombre;
   string categoriaArma;
   int edad;
};


int main() {

    string name;
    string surname;
    int option;
    char confirmation;
 
 
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
            cout << "Invalid option. The default name will be used."<<endl;
            name = "Chepe";
            surname = "Buquele";
 
 
           
            break;
    }
 
 
    cout << "Welcome to the start of your story " << name <<" "<<surname<< ". Good luck in this big world" << endl;
 
 
 
 
 




   Soldado alberto;
   alberto.nombre = "Albert";
   alberto.categoriaArma = "Pistol";
   alberto.edad = 20;




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
           cout << "\nInvalid option. " << alberto.nombre << " decides to force his way in.\n";
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


   return 0;
}
