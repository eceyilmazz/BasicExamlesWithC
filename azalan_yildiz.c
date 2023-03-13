#include <stdio.h>
int main (void){
	// Azalan yýldýz 
	int i,j,x;
	
	printf("Kenar sayisi giriniz:\n");
	scanf("%d",&x);
	
	for(i=x; i>=1; i--){
		for(j=1; j<=i; j++)
		printf("*");
		
	printf("\n");
	}

	system("pause");
	return 0;
}
