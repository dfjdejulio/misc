/* iota.c: Act like the APL iota operator. */
/* Author: Doug DeJulio, ddj@aisb.org */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc,
     char *argv[])
{
  register int i;
  int end,start=1,step=1;

  switch (argc) {
  case 4:
    step=atoi(argv[3]);
  case 3:
    start=atoi(argv[2]);
  case 2:
    end=atoi(argv[1]);
    break;
  default:
    fprintf(stderr, "usage: %s end [start [step]]\n", argv[0]);
    return 1;
  }

  for (i=start; i != end; i += step) {
    printf("%d ", i);
  }
    
  printf("%d\n", i);

  return 0;
}
