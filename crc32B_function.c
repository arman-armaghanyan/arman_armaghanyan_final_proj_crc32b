#include <stdio.h>
#include <stdlib.h>

//checking errors during opening file
void checkFileOpening(FILE* file){
   	if (file == NULL) {
		printf("Error\n");
	} else {
		printf("Done\n");
	};
}

unsigned int crc32b(unsigned char *message) {
	int i, j;
   	unsigned int byte, crc, mask;
	
   	i = 0;
   	crc = 0xFFFFFFFF; //11111111 11111111 11111111 11111111 in binary value
	//execute algorithm i times before reaching to last "\0" of stroke
   	while (message[i] != 0) {
		//assigning every symbol from our message
      		byte = message[i];
		//xor byte with crc
      		crc = crc ^ byte;
		//masking crc 8 times
      		for (j = 7; j >= 0; j--){
         		mask = -(crc & 1);

       		  	crc = (crc >> 1) ^ (0xEDB88320 & mask); 
      		}
     		i++;
   	}
	return ~crc;
}

int main() {
	//opening read.txt file	
	FILE* fp = fopen("read.txt","r");
	checkFileOpening(fp);
	
	//calculating the length of our file
	int len;
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	
	//creating data for our input and allocate memory for it
	unsigned char* data = NULL;
	data = (unsigned char*)malloc(len);

	//assigning data from read.txt to our data
	rewind(fp);
	fscanf(fp, "%[^\n]", data);
	fclose(fp);
	
	//printing data and hash value of data
	printf("Your data is: \"%s\"\n", data);
	unsigned int result = crc32b(data);
	printf("Your hash is: \"%x\"\n", result);

	return 0;
}
