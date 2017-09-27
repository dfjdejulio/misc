#include <stdio.h>
#include <stdlib.h>
#include <sys/attr.h>
#include <sys/clonefile.h>

int
main(int argc,
     char **argv)
{
  int r;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s sourcefile clonedfile\n", argv[0]);
    return 1;
  }

  /* Clone source to destination with no flags set. */
  r = clonefile(argv[1], argv[2], 0);

  if (r) {
    perror(argv[0]);
    return r;
  }

  return 0;
}
