#include <stdio.h>
int hesapla(int a,int b);
int main (void){
	// Recursive fonksiyon ile üslü sayı hesabı yapan c kodu
	int x,y;
	printf("Sayinin tabanini giriniz: \n");
	scanf("%d",&x);
	printf("Sayinin ussunu giriniz:\n");
	scanf("%d",&y);
	
	printf("Sonuc %d dir.\n",hesapla(x,y));
	
	system("pause");
	return 0;
}
int hesapla(int a,int b){
	// b==1 li kısım olmayabilir ? (emin değilim)
	if(b==1)
	return a;
	else if(b>0)
	return (a*hesapla(a,b-1));
	else if(b==0)
	return 1;
}
