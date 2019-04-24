/*
 * Sarah Higgins
 * Operating Systems Final Project
 * cat.c
 * char buffer[BUFF_SIZE];
 * char buffer;  //just use a buffer of size one at first
 * concatinates files sequentially and writes to output
 */
 
 int main(int argc, char* argv[]) {
   char bufferl         /* make the buffer local rather than global */
   open (argv[1], 0);
   
   while (read (3, &buffer, 1)) {    /* put in file descriptor 3 for fd */
     write(1, &buffer, 1);
     write(1, &buffer, 1);
   }
 }
