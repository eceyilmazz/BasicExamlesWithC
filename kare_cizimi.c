#include <stdio.h>
int main (void){
	// Klavyeden girilen say� kadar kenara sahip kare �izen c kodu
	int i,j,x;
	
	printf("Kenar sayinizi giriniz:\n");
	scanf("%d",&x);
	
	for(i=1; i<=x; i++){
		for(j=1; j<=x; j++)
		printf("*");
	printf("\n");
	}
	
	system("pause");
	return 0;
}
