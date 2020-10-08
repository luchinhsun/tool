#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	FILE *f = NULL;
	FILE *out = NULL;
	char *input;
	int c = 0;

	if(argc != 3 || strlen(argv[1])==0 || strlen(argv[2])==0){
		printf("Please use by following\n");
		printf("read_file inputfile outputfile\n");
		return 0;
	}

	f = fopen(argv[1], "rb");
	if(f){

		//calculate size of file(move ptr to file end)
		fseek(f, 0, SEEK_END);
		c = ftell(f);

		//create memory for saving data
		input = (char *)malloc((c+1)*sizeof(char));
		memset(input, 0, sizeof(input));

		//move ptr back to file begin
		fseek(f, 0, SEEK_SET);

		//read data
		fread(input, c+1, 1, f);
		// printf("file : %s\n", input);
		input[c] = '\0';
		// for(int i=0; i<c; i++){
		// 	printf("%c ", input[i]);
		// 	if(i!=0 && i%16 == 0)	printf("\n");
		// }
		printf("filelen : %d\n", c);
		fclose(f);
	}

	out = fopen(argv[2], "wb");
	if(out){
		fwrite(input, c, 1, out);
		fclose(out);
	}

	
	return 0;
}