
//=========================================================
// Name        : SqLite_Test.cpp
// Author      : Adam
// Version     : 0.01
// Copyright   : Licensed under the MIT License
// Description : SqLite_Test.cpp in C++, Ansi-style
//=========================================================

#include <iostream>
#include <sqlite3.h>
using namespace std;

// This is the callback function to display the select data in the table
static int callback(void *NotUsed, int argc, char **argv, char **szColName)
{
  for (int i = 0; i < argc; i++)
  {
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int main()
{
  sqlite3 *db;
  char *szErrMsg = 0;

  // open database
  int conn = sqlite3_open("db/library.db", &db);

  if (conn)
  {
    std::cout << "SQLite Database Access Error: %s\n", sqlite3_errmsg(db);
    return(0);
  }
  else
  {
    std::cout << "SQLite Database Access Successful. Congratulations!\n";
  }

  // prepare our sql statements
  const char *pSQL[6];
  //pSQL[0] = "INSERT INTO booklist(author, title, completed) VALUES ('David Goggins', 'Can''t Hurt Me', 1)";
  pSQL[0] = "SELECT * FROM booklist";

  // execute sql
  for(int i = 0; i < 1; i++)
  {
    conn = sqlite3_exec(db, pSQL[i], callback, 0, &szErrMsg);
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
}