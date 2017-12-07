#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int
main(int argc,
     char *argv[])
{
  int counts[256];
  int i, c;

  bzero(counts, sizeof(int) * 256);

  switch (argc) {
  case 2:
    if (!freopen(argv[1], "r", stdin)) {
      fprintf(stderr, "%s: can't open %s for reading.\n",
	      argv[0], argv[1]);
      return 34;
    }
  case 1:
    break;
  default:
    fprintf(stderr,
	    "usage: %s [infile]\n",
	    argv[0]);
    return 17;
  }

  while ((c=getchar()) != EOF) {
    counts[c]++;
  }

  for (i=0; i<256; i++) {
    if (counts[i]) {
      printf("0x%02X: %d\n", i, counts[i]);
    }
  }

  return 0;
}
