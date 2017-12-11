#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int
main(int argc,
     char *argv[])
{
  int counts[256];
  int i, c;
  char *name;

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
      printf("0x%02X", i);
      if (i > 0x20 && i < 0x7f) {
	printf(" (%c)", i);
      } else {
	switch (i) {
	case 0x09:
	  name = " (tab)";
	  break;
	case 0x0A:
	  name = " (newline)";
	  break;
	case 0x20:
	  name = " (space)";
	  break;
	case 0x1B:
	  name = " (escape)";
	  break;
	case 0x1C:
	  name = " (field separator)";
	  break;
	case 0x1D:
	  name = " (group separator)";
	  break;
	case 0x1E:
	  name = " (record separator)";
	  break;
	case 0x1F:
	  name = " (unit esparator)";
	  break;
	case 0x7f:
	  name = " (del)";
	  break;
	default:
	  name = "";
	}
	fputs(name, stdout);
      }
      printf(": %d\n", counts[i]);
    }
  }

  return 0;
}
