/*
 * pwd.c
 * Sarah Higgins
 * This program recreates what the pwd system call does within the Linux Terminal.
 * 
 */
 
 #include <dirent.h> 
 #include <string.h>
 #include <stdio.h> 

 int main(int argc, char* argv[]) { 
   printPath();
 }
 
 int printPath() {    /* finds the current working directory(ies) */
   struct dirent *entry;
   DIR *d = opendir(".");
   long inode;
   char *currDir;
   
   while ((entry = readdir(d)) != NULL) {    /* while read directory is not empty */
     if (strcmp(entry->d_name, ".") == 0) { 
       inode = entry->d_ino;
     }
   }
   
   d = opendir("..");
   
   while ((entry = readdir(d)) != NULL) {  
     if (inode == entry->d_ino) {
       printf("%s\n", entry->d_name);
     }
   }
 }
