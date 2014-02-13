/* Simple firmware extender for LPC1343 */

#include <stdio.h>

#define FLASH_SIZE		((unsigned int)0x00008000)

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: fwext <firmware_file.bin>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r+b");
	if (f == NULL)
	{
		fprintf(stderr, "Can't open firmware file: %s\n", argv[1]);
		return 1;
	}
	fseek(f, 0, SEEK_END);
	int flash_size = ftell(f);

	unsigned char c = '\xFF';
	int rest = FLASH_SIZE - flash_size;
	int i;
	for (i = 0; i < rest; ++i)
		fwrite(&c, 1, 1, f);
		
	fclose(f);

	if (rest < 0)
	{
		fprintf(stderr, "fwext: ERROR: Very large firmware file\n");
		return 1;
	}

	fprintf(stderr, "fwext: OK\n");
	return 0;
}

