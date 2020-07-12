#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> // for checking if a directory exists
#include <unistd.h>

int main ()
{
   FILE *fp;
   int n, year, isint, i;
   char resp[20], author[100], title[200], caption[200], line[256];

   while (1)
   {
      printf ("Enter an author...\n");
      gets (author);
      printf ("Enter a book title...\n");
      gets (title);
      printf ("Enter the book's caption...\n");
      gets (caption);
      while (1)
      {
         printf ("Enter the year the book was published...\n");
         fgets (line, sizeof line, stdin); // scans through the length of the input line
         isint = sscanf (line, "%d", &year); // checks whether it's an integer; if so, then assigns it to a variable
         if (isint) break; // breaks once a valid input is added (in this case an n-digit year)
         printf ("You did not enter a valid year. Please enter a valid year\n"); // repeats indefinitely if mistakes are perpetually made
      }

      struct stat st = {0};
      char filepath[256];

      sprintf (filepath, "C:\\Users\\20200507s\\Documents\\PVLdeluxe");
      if (stat (filepath, &st) == -1) 
      {
         mkdir (filepath);
      }

      sprintf (filepath, "C:\\Users\\20200507s\\Documents\\PVLdeluxe\\Authors");
      if (stat (filepath, &st) == -1) 
      {
         mkdir (filepath);
      }

      char fulldir[256], titleformat[204];
      strcpy(titleformat, title); // since str array variables are not modifiable, it is copied to the new variable

      sprintf (filepath, "C:\\Users\\20200507s\\Documents\\PVLdeluxe\\Authors\\%s", author);
      if (stat (filepath, &st) == -1) // if such filepath does not exist
      {
         mkdir (filepath);

         strcpy (fulldir, filepath);
         strcat (fulldir, "\\");
         strcat (titleformat, ".txt");
         strcat (fulldir, titleformat);

         fp = fopen (fulldir, "w");
         if (fp != NULL) // create file inside created folder
         {
            printf ("File created.\n");
            fprintf (fp, "Author: %s", author); // printing
            fprintf (fp, "\nTitle: %s: %s", title, caption); // printing
            fprintf (fp, "\nYear: %i", year); // printing
            fprintf (fp, "\nGenre: "); // printing, for use later
            fprintf (fp, "\nSummary: "); // printing, for use later
            fprintf (fp, "\nSeries: "); // printing, for use later
            fprintf (fp, "\nTags: "); // printing, for use later
            fprintf (fp, "\nSets: "); // printing, for use later
            fclose (fp); // close the open file
         } 
         else
         {
            printf ("Unable to create file.\n");
         }
      } 
      else // if such filepath does exists
      {
         strcpy (fulldir, filepath);
         strcat (fulldir, "\\");
         strcat (titleformat, ".txt");
         strcat (fulldir, titleformat);

         fp = fopen (fulldir, "w");
         if (fp != NULL) // create file inside created folder
         {
            printf ("File created.\n");
            fprintf (fp, "Author: %s", author); // printing
            fprintf (fp, "\nTitle: %s: %s", title, caption); // printing
            fprintf (fp, "\nYear: %i", year); // printing
            fprintf (fp, "\nGenre: "); // printing, for use later
            fprintf (fp, "\nSummary: "); // printing, for use later
            fprintf (fp, "\nSeries: "); // printing, for use later
            fprintf (fp, "\nTags: "); // printing, for use later
            fprintf (fp, "\nSets: "); // printing, for use later
            fclose (fp); // close the open file
         } 
         else
         {
            printf ("Unable to create file.\n");
         }
      }

      if (fp == NULL) // error catcher
      {
         perror ("Error while opening the file.\n");
         exit (EXIT_FAILURE);
      }

      while (1)
      {
         printf ("Would you like to fill in another entry? y/n\n");
         gets (resp); // scans through the length of the input line
         if (!strcmp(resp, "y") || !strcmp(resp, "n")) break; // breaks once a valid input is added (char arrays compared to other char arrays)
         printf ("You did not enter a valid answer. Please enter a valid answer\n"); // repeats indefinitely if mistakes are perpetually made
      }
      if (!strcmp(resp, "n")) break;
   }
   printf ("Have a nice day.\n");
   return 0; // end of program
}