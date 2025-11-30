#if 0
#pysea.c
#polyglot-file
import sys
print ('Hello, world - Python\ngcc -o pysea', sys.argv[0])
#endif

#include <stdio.h>
#define exit int main(int argc, char** argv)
#define quit { printf ("Hello, world - C.\npython3 %s.c\n", argv[0]); return 0; }

exit
quit
