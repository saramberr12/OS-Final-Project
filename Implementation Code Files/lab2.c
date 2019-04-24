/*  
 *  Sarah Higgins
 *  Operating Systems Final Project
 *  program to copy one file to another file
 *  the program uses C runtime functions fopen, fclose, fread, fwrite
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define BUF_SIZE 80

/* argument argc is a count.  argv is an array of pointers.  The first */
/* pointer is the name of the program.  The second pointer is file1. */

int main(int argc, char* argv[]) {
  char record[BUF_SIZE];
  size_t bytesIn, bytesOut;
  struct timeval t0, t1;
  double elapsed;
  
  FILE *infile, *outfile;    /* file desriptors */
  
  if (argc < 3) {
    printf("UsageLfcopy <source> <target>\n");  /* this is the only line printing */
    exit(EXIT_FAILURE);
  }
  
  infile = fopen(argv[1], "rb");    /* open source file for read */
  
  if (infile == NULL) {         /* could not open file */
    printf("Could not open input file.\n");
  }
  
  gettimeofday(&t0, 0);
  
  /* read record at a time from source file and write it to the target file. */
  /* infile is the input file descriptor. */
  while (bytesIn = fread(record, 1, BUF_SIZE, infile) > 0) {
    bytesOut = fwrite(record, 1, bytesIn, outfile);
    if (bytesOut != bytesIn) {
      printf("Fatal write error.\n");
      exit(EXIT_FAILURE);
    }
  }
}

