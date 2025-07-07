#include <iostream>
#include <string>




using namespace std;




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


   return 0;
}
