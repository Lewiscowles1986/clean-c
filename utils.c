#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>


bool hasStdIn() {
	char c;
	c = getchar();
	putchar(c);
	return (c != EOF);
}

unsigned char * createBuffer(long size) {
        unsigned char *buffer;
	buffer=malloc(size);
	if (!buffer) {
		fprintf(stderr, "not enough memory\n");
		exit(3);
	}
	return buffer;
}

long file_size(FILE *fp) {
  struct stat buf;

  if (!fp) return -1;
  if (fstat(fileno(fp),&buf)) return -2;
  return (long)buf.st_size;
}

long getFileSize(FILE *fp) {
	long insize = 0;
	if((insize=file_size(fp)) < 0) { return 0; }
	return insize;
}

