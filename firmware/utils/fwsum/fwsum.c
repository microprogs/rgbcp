/* Simple firmware checksum corrector for LPC1343 */

#include <stdio.h>

#define MIN_SIZE		((unsigned int)0x00000020)
#define SUM_ADDRESS		((unsigned int)0x0000001C)

int main(int argc, char **argv)
{
	unsigned int flash_size = 0;
	unsigned int checksum = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: fwsum <firmware_file.bin>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r+b");
	if (f == NULL)
	{
		fprintf(stderr, "Can't open firmware file: %s\n", argv[1]);
		return 1;
	}

	fseek(f, 0, SEEK_END);
	flash_size = ftell(f);

	if (flash_size < MIN_SIZE)
	{
		fprintf(stderr, "fwsum: ERROR: Incorrect flash size\n");
		fclose(f);
		return 1;
	}

	int i;
	fseek(f, 0, SEEK_SET);
	for (i = 0; i < 7; ++i)
	{
		unsigned int w;
		fread(&w, 4, 1, f);
		checksum += w;
	}
	checksum = (~checksum) + 1;

	fseek(f, SUM_ADDRESS, SEEK_SET);
	fwrite(&checksum, 4, 1, f);
	fclose(f);

	fprintf(stderr, "fwsum: OK\n");
	return 0;
}

