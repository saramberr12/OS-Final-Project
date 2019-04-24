/* 
 * Sarah Higgins
 * Operating Systems Final Project
 * SarahShell.c is a mini shell that closes with CTRL"C".
 * Performs ls, ls -l, pwd, cat, cp, head, tail, vi, ping,
 *          fdisk, whoami, echo, less, and more!  It does not, 
 *          however, perform cd because cd is built into the
 *          Linux shell already and is not a binary. 
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/wait.h>
 #define CMD_LENGTH 100
 #define TOKENS 10
 
 /*
  * Main function runs the program
  * @param int argc
  * @param char* argv[]
  *    
  */
 int main(int argc, char* argv[]) {
   long line_size = CMD_LENGTH;                 
   char* input_line;                            
   input_line = (char*) malloc(CMD_LENGTH + 1); 
                                                
   
   char* command[TOKENS];   
   int cmd_pid;             
   int cmd_status;         
   
   while(1) {            /* while SarahShell is running */
     printf("|SarahShell> ");
     getline(&input_line, &line_size, stdin);
     
     cmd_pid = fork();   /* creates another process */
     
     if (cmd_pid == 0) { /* if the command PID is zero, tokenize */
       command_tokenize(command, input_line);
       if (execvp(command[0], command) == -1) {  /* if the command PID is not binary, */
         printf("Invalid command.\n");           /* prints "Invalid Command" output. */
       }
     }
      else {
       wait(&cmd_status);  /* waits for another command to be entered */
     }
   }
   exit(0);
 }
 
/*
 * Void function command_tokenize
 * -------------------------------
 *   char** command: pointer of the String command from the user
 *   char* command_text: String of command_text from the user
 *   
 *   Breaks string into a series of tokens
 */
 void command_tokenize(char** command, char* command_text) {
   char* token = strtok(command_text, " ");
   int token_index = 0;
   while(token != NULL) {          /* while SarahShell has a command */
     command[token_index] = token;
     token = strtok(NULL, " ");
     token_index++;
   }
                              
   char * last_token = command[token_index -1];  /* the last token of command */
   int length = strlen(last_token);
   last_token[length - 1] = 0;
   command[token_index] = 0;
 }
