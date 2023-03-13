#include <stdio.h>
int main (void){

int i,j,a[5],x=0;
printf("1-10 Arasinda 5 Deger Giriniz :\n");
for(i=0; i<5; i++){
	scanf("%d",&a[i]);
}

printf("Element      Value      Gosterim\n");
for(j=0; j<5; j++){
	printf("%4d%11d   ",j,a[j]);
	while(x<a[j]){
		printf("*");
		x++;
	}
	x=0;
	
	printf("\n");
}
system("pause");
return 0;
}
