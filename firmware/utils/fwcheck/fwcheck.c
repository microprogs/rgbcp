/* Simple firmware checker for LPC1343 (Code Read Protect disabled) */

#include <stdio.h>

#define FLASH_SIZE		((unsigned int)0x00008000)
#define CRP_ADDRESS		((unsigned int)0x000002FC)
#define NO_CRP_MAGIC	((unsigned int)0xFFFFFFFF)

int main(int argc, char **argv)
{
	unsigned int flash_size = 0;
	unsigned int magic = 0;
	unsigned int checksum = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: fwcheck <firmware_file.bin>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "rb");
	if (f == NULL)
	{
		fprintf(stderr, "Can't open firmware file: %s\n", argv[1]);
		return 1;
	}

	fseek(f, 0, SEEK_END);
	flash_size = ftell(f);

	fseek(f, CRP_ADDRESS, SEEK_SET);
	fread(&magic, 4, 1, f);

	int i;
	fseek(f, 0, SEEK_SET);
	for (i = 0; i < 8; ++i)
	{
		unsigned int w;
		fread(&w, 4, 1, f);
		checksum += w;
	}
	
	fclose(f);

	if (flash_size != FLASH_SIZE)
	{
		fprintf(stderr, "fwcheck: ERROR: Incorrect flash size\n");
		return 1;
	}

	if (magic != NO_CRP_MAGIC)
	{
		fprintf(stderr, "fwcheck: ERROR: Incorrect NO_CRP magic\n");
		return 1;
	}

	if (checksum != 0)
	{
		fprintf(stderr, "fwcheck: ERROR: Checksum error\n");
		return 1;
	}

	fprintf(stderr, "fwcheck: OK\n");
	return 0;
}

