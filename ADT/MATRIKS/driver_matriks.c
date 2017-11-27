/* Driver untuk ADT matriks */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

int main()
{
	MATRIKS M;
	float rata2;
	
	BacaMATRIKS(&M, 3, 4);
	
	rata2 = RataBrs(M, 1);
	printf("%f\n", rata2);
	
	rata2 = RataKol(M, 1);
	printf("%f\n", rata2);
	
}
