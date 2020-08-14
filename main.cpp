
//=========================================================
// Name        : SqLite_Test.cpp
// Author      : Adam
// Version     : 0.01
// Copyright   : Licensed under the MIT License
// Description : SqLite_Test.cpp in C++, Ansi-style
//=========================================================

#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
using namespace std;

// This is the callback function to display the select data in the table
static int callback(void *NotUsed, int argc, char **argv, char **szColName)
{
  std::cout << "Callback successful." << std::endl;
  for (int i = 0; i < argc; i++)
  {
    if (argv[i] == NULL)
    {
      std::cout << szColName[i] << " = " << "NULL" << std::endl;
    }
    else
    {
      std::cout << szColName[i] << " = " << argv[i] << std::endl;
    }
  }
  std::cout << "\n";
  return (0);
}

static int view_booklist()
{
  std::cout << "Function called successfully." << std::endl;
  sqlite3 *db;
  char *szErrMsg = 0;

  // open database
  int conn = sqlite3_open("db/library.db", &db);

  if (conn)
  {
    std::cout << "SQLite Database access error: %s\n", sqlite3_errmsg(db);
    return(0);
  }
  else
  {
    std::cout << "SQLite Database access successful. Congratulations!\n";
  }

  // prepare our sql statements
  const char *pSQL[0];
  //pSQL[0] = "INSERT INTO booklist(author, title, completed) VALUES ('David Goggins', 'Can''t Hurt Me', 1)";
  pSQL[0] = "SELECT * FROM booklist";

  // execute sql statements
  for(int i = 0; i < 1; i++)
  {
    conn = sqlite3_exec(
      db, // an open database 
      pSQL[i], // SQL statements to be evaluated
      callback, // callback function (oh god)
      0, // 1st argument to callback 
      &szErrMsg // error message
    );

    if(conn != SQLITE_OK)
    {
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      break;
    }
  }
  // close database
  if (db)
  {
    sqlite3_close(db);
  }

  return (0);
};

int view_booklist();

int main()
{
  while (true) {
    std::vector<std::string> main_menu_vec;

    main_menu_vec.push_back("Welcome to PVL Deluxe. Please select an option:");
    main_menu_vec.push_back("1. Add book");
    main_menu_vec.push_back("2. View list of books");
    main_menu_vec.push_back("3. Update book");
    main_menu_vec.push_back("4. Remove book");
    main_menu_vec.push_back("5. Exit");

    for(int i = 0; i < main_menu_vec.size(); i++)
    {
      std::cout << main_menu_vec[i] << std::endl;
    }

    int option;

    std::cout << "Your option: ";
    std::cin >> option;
    
    /*
    if (isdigit(option) == false)
    {
      std::cout << "Please enter a number." << std::endl;
      break;
    }
    */

    switch (option)
    {
      case 1:
        std::cout << "Selected: " << main_menu_vec[option] << std::endl;
        break;
      case 2:
        {
          std::cout << "Selected: " << main_menu_vec[option] << std::endl;
          int view = view_booklist();
          break;
        }
      case 3:
        std::cout << "Selected: " << main_menu_vec[option] << std::endl;
        break;
      case 4:
        std::cout << "Selected: " << main_menu_vec[option] << std::endl;
        break;
      case 5:
        std::cout << "Shutting down. Goodbye" << std::endl;
        return (0);
      default:
        std::cout << "Option not recognized. Please try again." << std::endl;
        break;
    }
  }
  return (0);
}