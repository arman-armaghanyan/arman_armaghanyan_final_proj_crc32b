#include <stdio.h>
#include <string.h>

const char characters[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};


const char* morsecode[] = {"/", ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-", ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....", "--...","---..","----.","-----"};

void textEncoder(unsigned char *message) {
        int i = 0;
        while (message[i] != 0) {
                int j = 0;
                while (characters[j]!=0){
                        if(message[i] == characters[j]) {
                                printf("%s\n",morsecode[j]);
                        }
                        j++;
                }
                i++;
        }
}

char compareArray(char **a,char *b,int size){
	int i;
	for(i=0;i<size;i++){
		if(*a[i]!=b[i])
			return 1;
	}
	return 0;
}



void textDecoder(char *string) {

	char *token = strtok(string, " ");
        while( token != NULL ) {
		int i = 0;
		printf("%c",compareArray(morsecode[1],token, 6));
/*		while (mosecode[i] != 0)
			i++;
		};*/
                token = strtok(NULL, " ");
        }
        
}

/* void textDecoder(char *string) {

		printf("*%s\n", token);
		printf("*%s\n", morsecode[1]);
		printf("*%d\n", token == morsecode[1]);

	
	char* temp;
	char *token = strtok(string, " ");
		int i = 0;

        while( token != NULL ) {
		temp = token;
		printf("%lu ",strlen(morsecode[i]));
		i++;
		int j = 0;
		while (morsecode[j] != 0){
			if (temp == morsecode[j]){
				printf("%c",characters[j]);
			}
			j++;
		}
                token = strtok(NULL, " ");
        }
}*/

int main() {
        unsigned char data[] = "SOS";
        //textEncoder(data);

        char data2[] = ".- --- -.-";
        textDecoder(data2);
        return 0;
}
