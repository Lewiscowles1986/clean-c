#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>

bool hasStdIn();
unsigned char * createBuffer(long size);
long getFileSize(FILE *fhandlein);

int main(int argc, char **argv) {

	// check stdin
	long insize = getFileSize(stdin);
	if(insize <= 0) {
		fprintf(stderr, "no input to stdin\n");
		exit(2);
	}

	// create buffer
	unsigned char * inbuf = createBuffer(insize);

	// read stdin to buffer
	size_t readnbytes;
	if ((readnbytes = fread(inbuf, sizeof(char), sizeof(inbuf), stdin)) <= 0) {
		fprintf(stderr, "error reading from stdin\n");
		free(inbuf);
		exit(3);
	}

	// pipe out
	if (fwrite(inbuf, sizeof(char), readnbytes, stdout) != insize) {
		fprintf(stderr, "error writing to stdout\n");
		free(inbuf);
		exit(3);
	}

	// clean up
	free(inbuf);

	return 0;
}
