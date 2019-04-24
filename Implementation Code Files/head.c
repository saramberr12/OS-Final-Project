/*
 * Sarah Higgins
 * Operating Systems Final Project
 * head.c
 * This program allows the user to find the beginning/ head characters within the program.
 *      -c, --bytes=[-]K
 *            print  the first K bytes of each file; with the leading '-', print all
 *            but the last K bytes of each file
 *      -n, --lines=[-]K
 *            print the first K lines instead of the first 10; with the leading '-',
 *            print all but the last K lines of each file
 */
 
 #define O_WRONLY 1
 #define SEEK_CUR 10
 
 int main(int argc, char* argv[]) {

  char buffer[1];   /* make the buffer local rather than global */
  open(argv[1], 0);
  
  while ( read(3 , buffer, 1) ) {    /* put in file descriptor 3 for fd; don't need > 0 */
    write(4 , buffer, 1);
  }
    
  close(3);     /* close file descriptor 3 */
  close(4);     /* close file descriptor 4 */
  
}
