#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL(x) ((random())%(x)+1)

static int
mycompar(const void * xp,
	  const void * yp)
{
  const int *x = (const int *) xp;
  const int *y = (const int *) yp;

  return *y - *x;
}


int
roll(int best,
     int dice,
     int die)
{
  int i;
  int results[dice];
  int sum=0;

  for (i=0; i<dice; i++) {
    results[i] = ROLL(die);
  }

  qsort(results, dice, sizeof(int), mycompar);

  for (i=0; i<best; i++) {
    sum += results[i];
  }

  return sum;
}

int
rolls(char *dstring)
{
  int b=1, q=1, d=8;

  if (index(dstring, 'b')) {
    sscanf(dstring, "%db%dd%d", &b, &q, &d);
  } else {
    sscanf(dstring, "%dd%d", &q, &d);
    b = q;
  }
  return roll(b,q,d);
}

int
main(int argc,
     char **argv)
{
  int i,j;
  int r=1;
  int count=0;
  char *newline = "\n";
  char *tab = "\t";
  char *spacer = tab;

  srandom(time(NULL));

  for (i=1; i<argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'r':
	r = atoi(argv[++i]);
	break;
      case 'n':
	spacer = newline;
	break;
      case 't':
	spacer = tab;
	break;
      default:
	fprintf(stderr, "unknown switch '%c'\n", argv[i][1]);
      }
    } else {
      for (j=0; j<r; j++) {
	if (count++) {
	  printf(spacer);
	}
	printf("%d", rolls(argv[i]));
      }
    }
  }

  printf("\n");

  return 0;
}
