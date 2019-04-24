/*
 * Sarah Higgins
 * Operating Systems Final Project
 * Program to do what the cp command does in the Linux terminal.
 */
 
 #define O_WRONLY 1
 #define O_CREAT 0100
 
 int main(int argc, char* argv[]) {
   char buffer[1];      /* makes the buffer local rather than global */
   open(argv[1],0);    
   open(argv[2], 0101, 0600);
   
   while(read(3, buffer, 1)) {  /* copies arg 1 to arg 4 */
     write(4, buffer, 1);       /* which is the destination file */
   }
   
   close(3);
   close(4);
 
 }
 
 
