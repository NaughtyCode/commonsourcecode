#include "FileIO.h"

int FileExists( const char * filename ){
    FILE * pFile=fopen(filename, "r" );
	if (pFile)
    {
		fclose(pFile);
        return 1;
    }
    return 0;
}

char* ReadFileData(const char *filename){
	FILE * file;
	char * buffer;
	size_t size;
	file = fopen(filename, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s\n", filename);
		return 0;
	}
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	buffer = (char *)malloc((size + 1) * sizeof(char *));
	fread(buffer, sizeof(char), size, file);
	buffer[size] = 0;
	fclose(file);
	return buffer;
}
