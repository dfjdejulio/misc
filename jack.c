#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROLL(x) ((random())%(x)+1)

int
main(void) {
  int i=0;
  int r=0;

  setbuf(stdout, NULL);
  while (8675309) {
    r = ROLL(5);
    fputs("All work and no play makes Jack a dull boy.", stdout);
    for (i=-5; i<r; i++) {
      putchar(' ');
    }
    sleep(2+r);
  }

  return 0;
}
