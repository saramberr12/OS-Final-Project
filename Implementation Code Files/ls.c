/* 
 * Sarah Higgins
 * ls.c
 * This program recreates what the ls command does within the Linux terminal.  The 
 * ls command lists the files within the current working directory.
 */
 
 #include <dirent.h> 
 #include <stdio.h> 

 int main(int argc, char* argv[]) {   /* finds the working directory */
   struct dirent *entry;
   DIR *d = opendir(".");

   while ((entry = readdir(d)) != NULL) {    /* while entry is not null */
     if (entry->d_name[0] != '.') {          /* print the programs within working direcory */
       printf("%s ", entry->d_name);
     }
   }
 }

