#include <stdio.h>
int hesapla(int a,int b);
int main (void){
	// Recursive fonksiyon ile �sl� say� hesab� yapan c kodu
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
	// b==1 li k�s�m olmayabilir ? (emin de�ilim)
	if(b==1)
	return a;
	else if(b>0)
	return (a*hesapla(a,b-1));
	else if(b==0)
	return 1;
}
