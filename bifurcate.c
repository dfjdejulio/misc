/* bifurcate.c: Split alternate lines of input into two output files. */
/* Author: Doug DeJulio, ddj@cmu.edu */

#include <stdio.h>
#include <strings.h>

#define MY_BUFSIZ (1024)

int
main(int argc,
     char *argv[])
{
  FILE *outfile1, *outfile2;

  char buf[MY_BUFSIZ];
  register int evenline=0;
  
  switch (argc) {
  case 4:
    if (!freopen(argv[3], "r", stdin)) {
	fprintf(stderr, "%s: can't open %s for reading.\n",
		argv[0], argv[3]);
	return 1;
    }
    case 3:
      if (!(outfile1 = fopen(argv[1], "w"))) {
	fprintf(stderr, "%s: can't open %s for writing.\n",
		argv[0], argv[1]);
	return 1;
      }
      if (!(outfile2 = fopen(argv[2], "w"))) {
	fprintf(stderr, "%s: can't open %s for writing.\n",
		argv[0], argv[2]);
	return 1;
      }
      break;
    default:
      fprintf(stderr,
	      "usage: %s outfile1 outfile2 [infile]\n"
	      "warning: input lines greater than around %d won't work.\n",
	      argv[0], MY_BUFSIZ);
      return 1;
  }

  bzero(buf, MY_BUFSIZ);
  while (fgets(buf, MY_BUFSIZ, stdin)) {
    if (buf[MY_BUFSIZ-2]) {
      fprintf(stderr, "%s: line longer than %d detected, terminating\n",
	      argv[0], MY_BUFSIZ);
      return 1;
    }
    if (evenline) {		/* even-numbered line */
      if ((fputs(buf, outfile2)) == EOF) {
	fprintf(stderr, "%s: error writing to %s\n",
		argv[0], argv[2]);
	return 1;
      }
    } else {			/* odd-numbered line */
      if ((fputs(buf, outfile1)) == EOF) {
	fprintf(stderr, "%s: error writing to %s\n",
		argv[0], argv[1]);
	return 1;
      }
    }
    evenline = (!evenline);
  }
  if (ferror(stdin)) {
    fprintf(stderr, "%s: error reading input.\n", argv[0]);
    return 1;
  }

  return 0;
}
