#include <stdio.h>
int degereGoreKup(int a);
int main (void){
	// Foksiyona deger gönderip küp hesabý yapan c kodu
	int x,sonuc=0;
	printf("Kupunu bulmak istediginiz sayiyi giriniz:\n");
	scanf("%d",&x);
	
	sonuc=degereGoreKup(x);
	
	printf("Sayinin kupu %d dir.\n",sonuc);
	
	system("pause");
	return 0;
}
int degereGoreKup(int a){
	int kup=1;
	kup=a*a*a;
	return (kup);	
}
