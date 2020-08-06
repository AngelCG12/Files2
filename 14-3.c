#include <stdio.h>
#include <stdlib.h>

const char numberlist[] = "numbers.txt";
const char divisible[] = "divisibleby3.txt";
const char nondivisible[] = "nondivisbleby3.txt";

int main()
{
FILE *listfile;		
FILE *divisible_ptr;
FILE *nondivisible_ptr;

char num;

listfile = fopen(numberlist, "r");	
	
	if(listfile == NULL)
	{
	printf("Not number list document\n");
	return(8);
	}

divisible_ptr = fopen(divisible, "w+"); 
	
	if(divisible_ptr == NULL)
	{
	printf("No document for writing numbers divisibles by 3\n");
	return(8);
	}
nondivisible_ptr = fopen(nondivisible, "w+"); 

	if(nondivisible_ptr == NULL)
	{
	printf("No document for writing non divisble by 3\n"); 
	return(8);
	}
	while(1) 
	{
	num = fgetc(listfile);

	if(num == EOF)
		{
		break;
		}

	if(num % 3  == 0)
		{
		fputc((int)num, divisible_ptr);
		}	
	else 
		{
		fputc((int)num, nondivisible_ptr);
		}
	
	}

fclose(listfile);
fclose(divisible_ptr);
fclose(nondivisible_ptr);

return 0;
}



 
