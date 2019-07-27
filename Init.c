#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//Iniciar GCC mais facilmente.s
int main()
{
	system("gcc main.c functions.c functions.h");
	system("./a.out");
}