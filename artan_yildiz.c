#include <stdio.h>
int main (void){
	// Artan yýldýz
	int i,j,x;
	
	printf("Sayi giriniz:\n");
	scanf("%d",&x);
	
	for(i=1; i<=x; i++){
		for(j=1; j<=i; j++)
		printf("*");
		
	printf("\n");
	}
	
	system("pause");
	return 0;
}
