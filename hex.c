#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *hex(int decimal_Number) 
{ 
    int i = 0, temp = 0; 
    char *hexa_Number = (char*)malloc(9*sizeof(char)); 
    if (!hexa_Number)
	    return NULL;
    while (decimal_Number != 0) { 
        temp = decimal_Number % 16; 
        if (temp < 10) 
            temp = temp + 48; 
        else
            temp = temp + 55; 
        hexa_Number[i++] = temp; 
        decimal_Number = decimal_Number / 16; 
    }
   hexa_Number[i] = '\0'; 
  
    return (hexa_Number);
}

int main ()
{
	printf("hex = %s\n", hex(15));
}
