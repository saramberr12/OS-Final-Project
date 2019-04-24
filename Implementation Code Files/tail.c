/* 
 * Sarah Higgins
 * Operating Systems Final Project
 * head.c
 * this program allows the user to find the end/ tail of the characters within the program
 * Type [tail, -int, file used]
 */
 
 #include <unistd.h>
 #include <sys/types.h>
 #define O_WRONLY 1
 
 int main(int argc, char* argv[]) {

  char buffer[1]; /* make the buffer local rather than global */
  open(argv[1], 0);
  //cd
  while ( read(3 , buffer, 1) ) { /* put in file descriptor 3 for fd; don't need > 0 */
    lseek( 4, buffer, 1);
    write(4 , buffer, 1);
  }
    
  close(3);    /* close file descriptor 3 */
  close(4);    /* close file descriptor 4 */
  
}
 

