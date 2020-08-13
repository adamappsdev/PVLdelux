#include <iostream>
#include <string>
using namespace std;

int main()
{
   while (1)
   {
      int option, year;
      char exit;
      string name;
      string title;
      string publisher;
      string genre;
      string password;
      cout << "Welcome to PVL Deluxe.\n";
      cout << "Please select option below:\n";
      cout << "1. Add new book.\n";
      cout << "2. View books in database.\n";
      cout << "3. Edit existing books.\n";
      cout << "4. Remove books from database.\n";
      cout << "5. Exit program.\n";
      cout << "Enter a valid option: ";
      cin >> option;
      switch (option) {
         case 0:
            cout << "Your option: " << option << ". Option NULL.\nPlease enter password: ";
            cin >> password;
            cout << "Entered password: " << password << "\n";
            break;
         case 1:
            cout << "Your option: " << option << ". Add new book.\n";
            break;
         case 2:
            cout << "Your option: " << option << ". View books in database.\n\n";
            break;
         case 3:
            cout << "Your option: " << option << ". Edit existing books.\n\n";
            break;
         case 4:
            cout << "Your option: " << option << ". Remove books from database.\n\n";
            break;
         case 5:
            cout << "Your option: " << option << ". Exit Program.\n";
            while (1)
            {
               cout << "Are you sure you want to exit? y/n: ";
               cin >> exit;
               if (exit == *"y")
               {
                  cout << "Program shutting down. Goodbye.";
                  return 0;
               }
               else if (exit == *"n")
               {
                  break;
               }
               else 
               {
                  cout << "Option not recognized. Please try again.\n";
               }
            }
            break;
         default:
            cout << "Option not recognized. Please try again.\n\n";
            break;
      }
      if (exit == *"y")
      {
         return 0;
      }
   }
   return 0;
}