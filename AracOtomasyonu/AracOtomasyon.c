#include <stdio.h>          // Ece Yýlmaz 19090700033  
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct // denemeler yapýlýyor(arac ekleme yapýldý,toplam ciro gösterildi,arac görselleri bastýrýldý,araclarýn detayli bilgileri gösterildi,musteri-admin girisi)
{               // yönetici giriþi yapýldý isci listesi oluþturuldu, iþçi eklenmesi yapýldý,fis nolarýna göre çekilis yapýldý
    char marka[20];
    char model[20];
    int yil;
    int saatlik_ucret;
    int satis_ucreti;
    int km;
    char kasa[20];
    char yakit[20];
    char plaka[20];
} otomobil;
otomobil arac[100];
otomobil musteri;
typedef struct{
	char ad[10];
	char soyad[15];
	int yas;
	int maas;
	char pozisyon[20];
	int girisyili;
}calisanlar; 
calisanlar isci[10]; // --> Sýrket kapasitesi 10 kisi (suan calisan 3 kiþi var)

char sifre[20]="zeynepturgut";
int c,b,secim,tus,saat,fiyat=0,top,kisi,random,f[10];
char ch[45],e;

void cekilis(void);
int calisan_listesi(void);
void calisan_ekle(int a);
void ciro(int a);
void ekle(otomobil arac[],int a);
int araclar(otomobil arac[]);
void gorsel(char ch[],int a);
void satin_al(otomobil musteri);
void kiralama(otomobil musteri);
void kredifissatis (otomobil arac[],int secim);
void kredifiskira (otomobil arac[],int secim,int);
void fis_kira(otomobil arac[],int secim,int fiyat);
void fis_satin(otomobil arac[],int secim);
int arac_listesi2(otomobil arac[],otomobil a,int top);
int arac_listesi(otomobil arac[], otomobil a,int c,int b,int top);

int main(void)
{
	int x,marka,i,ekleme,boyut;
	char sifre1[20],ek,admin;
	int detay; // --> detayli bilgi icin 1 tusuna basilacak olan degisken
	
	printf("Sisteme admin olarak giris yapiyarsaniz A/a ya | Musteri iseniz M/m ye\nYonetici iseniz Y/y ye basiniz\n");
	scanf("%c",&admin);
	
	// ADMIN KISMI
	if(admin=='A' || admin=='a'){
	
	printf("\tAdmin Girisinde Bulunmaktasiniz.Lutfen sifrenizi giriniz\n");
	scanf("%s",sifre1);
	
	if(strcmp(sifre1,sifre)==0){
		system("cls");
		
	printf("Mevcud Araclar\n");
	top=araclar(arac);
	system("cls");
	
	printf("Sistemde toplam %d arac var\n",top);
	
	
	while(1){ 
	printf("Sisteme Arac Eklemek Icin 1'e Basiniz\nIslem Yapmayacaksaniz 0'a Basinizi\n");
	scanf("%d",&ek);

	if(ek==1)
	ekle(arac,top);
	else{
		printf("Hicbir tercih yapmadiniz\n");
		break;
	}
}
	}	
	else{
		printf("Hatali sifre girdiniz!!!\n");
		return 0;
	}
	
	
	
   }
   // MUSTERI KISMI
	else if(admin=='M' || admin=='m'){

    printf("Iyi gunler ZE-CE'ye hosgeldiniz <3\n"); 
     printf("\t\tMevcut Olan Araclar\n");
	gorsel(ch,45);
		
	printf("\n\n\t Detayli Bilgi Icin 1'e Basiniz.\n");
	scanf("%d",&detay);
	system("cls");
	
	araclar(arac);
   
    while(1){
    printf("Arac alim yapmak istiyorsaniz bire basiniz (1)\nArac kiralama yapmak istiyorsaniz ikiye basiniz (2)\n");
    printf("Cekilis Icin (3)\nIslemi sonlandirmak icin uce basiniz (4)\n");
    scanf("%d", &x);
    //cevap 1 ise alým sürecindeki komutlarý takip ederiz eðer cevap iki ise kiralama sürecin deki komutlarý takip ederiz
    if (x == 1)
    satin_al(musteri);
    else if (x == 2)
    kiralama(musteri);
    else if(x==3) //---> CEkiliþ kýsmý
    cekilis();
    else
    {
        printf("Iyi Gunler Tekrar Bekleriz...\n");
        break;
    }
    system("cls");
   } 
   }
   
   // YONETICI KISMI
   else if (admin=='Y' || admin=='y') {
   	int tercih;
	
	kisi=calisan_listesi();
	
	while(1){
	printf("Calisan Eklemek Istiyor Musunuz? E(1)/H(2)\n");
	scanf("%d",&tercih);
	
	if(tercih==1){
		calisan_ekle(kisi);
	}
	else{
		printf("Sistemden Cikis Yapiliyor\n");
		return 0;
	}
    }
   
   }
   
   // ADMIN,YONETICI YA DA MUSTERI DEGILSE
   else{
   	printf("Gecerli Islem Yapilamadi");
    return 0;
   }
   
    system("pause");
    return 0;
}
int calisan_listesi(){
	int h=0;
	FILE *calisan;
	calisan=fopen("isciler.txt","r");
    while(!feof(calisan)){
		printf("\t---%d.Isci Bilgileri---\n",(h+1));
		
		fscanf(calisan,"%s",isci[h].ad);
		printf("Ad : %s\n",isci[h].ad);
		fscanf(calisan,"%s",isci[h].soyad);
		printf("Soyad : %s\n",isci[h].soyad);
		fscanf(calisan,"%d",&isci[h].yas);
		printf("Yas : %d\n",isci[h].yas);
		fscanf(calisan,"%d",&isci[h].maas);
		printf("Maas : %d\n",isci[h].maas);
		fscanf(calisan,"%s",isci[h].pozisyon);
		printf("Pozisyon : %s\n",isci[h].pozisyon);
		fscanf(calisan,"%d",&isci[h].girisyili);
		printf("Ise Giris Yili : %d\n",isci[h].girisyili);
		h++;
		
	}
	fclose(calisan);
	return h;
}
void calisan_ekle(int kisi){
	int c,i;
	printf("Kac isci eklenecek?\n");
	scanf("%d",&c);
	
	FILE *calisan2;
	calisan2=fopen("isciler.txt","a");
	for(i=kisi; i<(kisi+c); i++){
		printf("Ad:");
		scanf("%s",isci[i].ad);
		fprintf(calisan2,"\n%s",isci[i].ad);
		printf("Soyad:");
		scanf("%s",isci[i].soyad);
		fprintf(calisan2,"\n%s",isci[i].soyad);
		printf("Yas:");
		scanf("%d",&isci[i].yas);
		fprintf(calisan2,"\n%d",isci[i].yas);
		printf("Maas:");
		scanf("%d",&isci[i].maas);
		fprintf(calisan2,"\n%d",isci[i].maas);
		printf("Pozisyon:");
		scanf("%s",isci[i].pozisyon);
		fprintf(calisan2,"\n%s",isci[i].pozisyon);
		printf("Giris Yili:");
		scanf("%d",&isci[i].girisyili);
		fprintf(calisan2,"\n%d",isci[i].girisyili);
	}
	
}
void gorsel(char ch[],int b){
	int i;
	FILE *dosya1;
	dosya1=fopen("arabadeneme.txt","r");
	for(i=1; i<=21; i++){ // TEK 1 ARABA 7 SATIR 3 TANE VAR 3*7=21
	fgets(ch,b,dosya1);
	printf("%s",ch);
    }
	fclose(dosya1);	
}
int araclar(otomobil arac[]){
	top=0;
	FILE *dosya;
	dosya=fopen("araclar.txt","r");
	
	while(!feof(dosya)){//--> Eðer EOF iþareti yoksa sýfýr deðerini döndürür
		printf("\t\t%d. Arac Bilgileri\n",(top+1));
	    fscanf(dosya,"%s\n",arac[top].marka);
	    printf("Marka : %s\n",arac[top].marka);
	    fscanf(dosya,"%s\n",arac[top].model);
	    printf("Model : %s\n",arac[top].model); 
	    fscanf(dosya,"%d",&arac[top].yil);
	    printf("Uretim Yili : %d\n",arac[top].yil);
	    fscanf(dosya,"%d",&arac[top].saatlik_ucret);
	    printf("Saatlik Ucreti : %d\n",arac[top].saatlik_ucret);
	    fscanf(dosya,"%d",&arac[top].satis_ucreti);
	    printf("Satis Ucreti : %d\n",arac[top].satis_ucreti);
	    fscanf(dosya,"%d",&arac[top].km);
	    printf("Km : %d\n",arac[top].km);
	    fscanf(dosya,"%s",arac[top].kasa);
	    printf("Kasa Tipi : %s\n",arac[top].kasa);
	    fscanf(dosya,"%s",arac[top].yakit);
	    printf("Yakit Turu : %s\n",arac[top].yakit);
	    fscanf(dosya,"%s",arac[top].plaka);
	    printf("Plaka : %s\n",arac[top].plaka);
	    printf("________________\n"); 
	    top++;
	}
	fclose(dosya);
	return top;
	
}
void cekilis(){
	int j=0;
	printf("Cekilis yapiliyor...\n");
    	
   	srand(time(NULL));
    random=rand()%5;
    	
    FILE *fis;
    fis=fopen("fisnolar.txt","r");
    while(!feof(fis)){
    	fscanf(fis,"%d",&f[j]);
    	if(j == random){
    		printf("Tebrikler Cekilisten 1 Haftalýk Ucretsiz Arac Kiralama Hakki Kazandiniz!!\n");
    		break;
		}
			
		j++;
	}
   	fclose(fis);
    system("pause");
}
void ekle (otomobil arac[],int a){//--> buradaki a sistemdeki toplam aracý temsil ediyor
	int ekle,i;
	printf("Eklenecek arac sayisi:");
	scanf("%d",&ekle);
	
	FILE *dosya;
	dosya=fopen("araclar.txt","a");
	for(i=a; i<(ekle+a); i++){
		printf("Marka:");
		scanf("%s",arac[i].marka);
		printf("Model:");
		scanf("%s",arac[i].model);
		printf("Uretim Yili:");
		scanf("%d",&(arac[i].yil));
		printf("Saatlik Ucret:");
		scanf("%d",&(arac[i].saatlik_ucret));
		printf("Satis Ucreti:");
		scanf("%d",&(arac[i].satis_ucreti));
		printf("Km:");
		scanf("%d",&(arac[i].km));
		printf("Kasa Tipi:");
		scanf("%s",arac[i].kasa);
		printf("Yakit Turu:");
		scanf("%s",arac[i].yakit);
		printf("Plaka:");
		scanf("%s",arac[i].plaka);
		
		fprintf(dosya,"\n%s",arac[i].marka);
	    fprintf(dosya,"\n%s",arac[i].model);
	    fprintf(dosya,"\n%d",arac[i].yil);
	    fprintf(dosya,"\n%d",arac[i].saatlik_ucret);
	    fprintf(dosya,"\n%d",arac[i].satis_ucreti);
	    fprintf(dosya,"\n%d",arac[i].km);
	    fprintf(dosya,"\n%s",arac[i].kasa);
	    fprintf(dosya,"\n%s",arac[i].yakit);
	    fprintf(dosya,"\n%s",arac[i].plaka);
	
		
	}
	fclose(dosya);

}
void ciro (int fiyat){
	int i,toplam=0;
	
	FILE *dosya3;
	dosya3=fopen("ciro.txt","a");
	fprintf(dosya3,"\n%d",fiyat);
	fclose(dosya3);
	
	FILE *dosyaciro;
	dosyaciro=fopen("ciro.txt","r");
	int sayi[100];
	i=1;
	while(!feof(dosyaciro)){
		fscanf(dosyaciro,"%d",&sayi[i]);
		toplam+=sayi[i];
		i++;
	}
	
	printf("\t---Toplam Ciro %d Tl---\n",toplam);
	
	
}
void satin_al(otomobil musteri){
	{
        printf("    Arac satin alma sitesi CE-ZE bolumunde bulunmaktasiniz\n\n\n");
        printf("Lutfen satin almak istediginiz arac markasini giriniz\n");
        scanf("%s", musteri.marka);
        printf("Istediginiz modeli giriniz\n");
        scanf("%s", musteri.model);
        printf("Kac model yilli olmasini istiyorsaniz giriniz\n");
        scanf("%d", &(musteri.yil));
        printf("Bulunan araclar:\n");
        secim = arac_listesi2(arac, musteri,top);
        if(secim!=-1){
	
        printf("Satin almak istediginiz aracin ucreti %d tl\n", arac[secim].satis_ucreti);
        printf("Islemi onaylamak icin 1'e basiniz\n");
        scanf("%d", &tus);
        if (tus == 1)
        {
           printf("Odemeyi nakit olarak yapmak icin (1)'e\nKredikarti ile odeme yapmak icin (2)'yi tuslayiniz");
           scanf("%d",&tus);
           if(tus==1)
           fis_satin(arac,secim);
		   else if(tus==2)
           kredifissatis(arac,secim);
        }
    	}
    	
    }
}
int arac_listesi2(otomobil arac[],otomobil musteri,int top)
{
    int secim, i;
    for (i = 0; i < top; i++)
    {
        if ((strcmp(arac[i].marka , musteri.marka)==0)&&(strcmp(arac[i].model , musteri.model)==0)){
		
        if(arac[i].yil == musteri.yil)
		{
        printf("%d. Arac aradiginiz kriterlere uygundur.\n", i + 1);
        printf("Marka:%s Model:%s Yil:%d ", arac[i].marka, (arac[i].model), (arac[i].yil));
        printf("Satis Ucreti:%d\nKm:%d Kasa Tipi:%s Yakit Turu:%s Plaka%s\n", (arac[i].satis_ucreti), (arac[i].km), (arac[i].kasa), (arac[i].yakit), (arac[i].plaka));
	    }
		}
    }
    printf("Kac nolu araci satin almak istiyorsunuz? arac bulunmadiysa sifiri tuslayiniz\n");
    scanf("%d", &secim);
    system("cls");
    return secim - 1;
}
void fis_satin(otomobil arac[],int secim)
{
	system("cls");
	srand(time(NULL));
	int fisno;
	fisno=rand()%100000;
	printf("Fisno:%d\n",fisno);
	printf("Arac markasi:%s\n",arac[secim].marka);
	printf("Arac modeli:%s\n",arac[secim].model);
	printf("Arac yili:%d\n",arac[secim].yil);
	printf("Arac km :%d\n",arac[secim].km);
	printf("Arac kasa:%s\n",arac[secim].kasa);
	printf("Arac yakit turu:%s\n",arac[secim].yakit);
	printf("Arac plaka:%s\n",arac[secim].plaka);
	printf("Satis tutari:%d\n",arac[secim].satis_ucreti);
	printf("\tIsleminiz tamamlanmistir iyi gunler dileriz\n");
	
	ciro(arac[secim].satis_ucreti);
	
	system("pause");
	
	FILE *fis;
	fis=fopen("fisnolar.txt","a");
	fprintf(fis,"\n%d",fisno);
	fclose(fis);	
}
void kredifissatis (otomobil arac[],int secim)
{
	system("cls");
	srand(time(NULL));
	int fisno;
	unsigned long long int no;
	int ay,yil,no2;
	fisno=rand()%100000;
	printf("Fisno:%d\n",fisno);
	printf("Arac markasi:%s\n",arac[secim].marka);
	printf("Arac modeli:%s\n",arac[secim].model);
	printf("Arac yili:%d\n",arac[secim].yil);
	printf("Arac km :%d\n",arac[secim].km);
	printf("Arac kasa:%s\n",arac[secim].kasa);
	printf("Arac yakit turu:%s\n",arac[secim].yakit);
	printf("Arac plaka:%s\n",arac[secim].plaka);
	printf("Lutfen kart no giriniz");
	scanf("%llu",&no);
	printf("kartin son kullanma tarihini (ay/yil) seklinde giriniz");
	scanf("%d/%d",&ay,&yil);
	printf("Kartin guvenlik kodunu giriniz");
	scanf("%d",&no2);
	printf("Satis tutari:%d\n",arac[secim].satis_ucreti);
	printf("\tIsleminiz tamamlanmistir iyi gunler dileriz.\n");
	
	ciro(arac[secim].satis_ucreti);
	
	system("pause");
	
	FILE *fis;
	fis=fopen("fisnolar.txt","a");
	fprintf(fis,"\n%d",fisno);
	fclose(fis);
}
void kiralama(otomobil musteri)
{   
        printf("    Arac kiralama sitesi ZE-CE bolumunde bulunmaktasiniz\n\n\n");
        printf("Lutfen kiralamak istediginiz arac markasini giriniz\n");
        scanf("%s", musteri.marka);
        printf("Istediginiz modeli giriniz\n");
        scanf("%s", musteri.model);
        printf("Kac model yilli olmasini istiyorsaniz giriniz\n");
        scanf("%d", &(musteri.yil));
        printf("kiralamak istediginiz aracin km arligini giriniz\n");
        scanf("%d",&c);
        scanf("%d",&b);
        printf("Bulunan araclar:\n");
        secim = arac_listesi(arac, musteri,c,b,top);
        if (secim!=-1)
    {
	
        printf("Kiralamak istediginiz aracin saatlik ucreti %dtl\n", arac[secim].saatlik_ucret);
        printf("Islemi onaylamak icin 1'e basiniz\n");
        scanf("%d", &tus);
        if (tus == 1)
        {
            printf("Kac saat kiralamak istediginizi girin\n");
            scanf("%d", &saat);
            fiyat = saat * (arac[secim].saatlik_ucret);
            printf("Toplam tutariniz %d tl\n", fiyat);
        }
        if (tus == 1)
        {
           printf("Odemeyi nakit olarak yapmak icin (1)'e\nKredikarti ile odeme yapmak icin (2)'yi tuslayiniz");
           scanf("%d",&tus);
           if(tus==1)
           fis_kira(arac,secim,fiyat);
           else if(tus==2)
           kredifiskira(arac,secim,fiyat);
        }
    
	}
}
int arac_listesi(otomobil arac[], otomobil musteri,int c,int b,int top)
{
    int secim, i;
    for (i = 0; i <top; i++)
    {
        if ((strcmp(arac[i].marka , musteri.marka)==0)&&(strcmp(arac[i].model , musteri.model)==0)){
		
        if(arac[i].yil == musteri.yil) {
        if((c<=arac[i].km && arac[i].km<=b)||(b<=arac[i].km && arac[i].km<=c))
		{
        printf("%d. Arac aradiginiz kriterlere uygundur.\n", i + 1);
        printf("Marka:%s Model:%s Yil:%d Saatlik Ucreti:%d ", arac[i].marka, (arac[i].model), (arac[i].yil), (arac[i].saatlik_ucret));
        printf("Satis Ucreti:%d\nKm:%d Kasa Tipi:%s Yakit Turu:%s Plaka%s\n", (arac[i].satis_ucreti), (arac[i].km), (arac[i].kasa), (arac[i].yakit), (arac[i].plaka));
	    }
	    }
		}
    }
    printf("Kac nolu araci kiralamak istiyorsunuz? uygun arac bulunamadiysa sifira basiniz\n");
    scanf("%d", &secim);
    system("cls");
    return secim - 1;
}
void fis_kira(otomobil arac[],int secim,int fiyat)
{
	system("cls");
	srand(time(NULL));
	int fisno;
	fisno=rand()%100000;
	printf("Fisno:%d\n",fisno);
	printf("Arac markasi:%s\n",arac[secim].marka);
	printf("Arac modeli:%s\n",arac[secim].model);
	printf("Arac yili:%d\n",arac[secim].yil);
	printf("Arac km :%d\n",arac[secim].km);
	printf("Arac kasa:%s\n",arac[secim].kasa);
	printf("Arac yakit turu:%s\n",arac[secim].yakit);
	printf("Arac plaka:%s\n",arac[secim].plaka);
	printf("Satis tutari:%d\n",arac[secim].satis_ucreti);
	printf("Toplam tutar:%d\n",fiyat);
	printf("\tIsleminiz tamamlanmistir iyi gunler dileriz\n");
	
	ciro(fiyat);
	
	system("pause");
	
	FILE *fis;
	fis=fopen("fisnolar.txt","a");
	fprintf(fis,"\n%d",fisno);
	fclose(fis);
		
}
void kredifiskira (otomobil arac[],int secim,int fiyat)
{
	system("cls");
	srand(time(NULL));
	int fisno;
	unsigned long long int no;
	int ay,yil,no2;
	fisno=rand()%100000;
	printf("Fisno:%d\n",fisno);
	printf("Arac markasi:%s\n",arac[secim].marka);
	printf("Arac modeli:%s\n",arac[secim].model);
	printf("Arac yili:%d\n",arac[secim].yil);
	printf("Arac km :%d\n",arac[secim].km);
	printf("Arac kasa:%s\n",arac[secim].kasa);
	printf("Arac yakit turu:%s\n",arac[secim].yakit);
	printf("Arac plaka:%s\n",arac[secim].plaka);
	printf("Lutfen kart no giriniz");
	scanf("%llu",&no);
	printf("Kartin son kullanma tarihini (ay/yil) seklinde giriniz");
	scanf("%d/%d",&ay,&yil);
	printf("Kartin guvenlik kodunu giriniz");
	scanf("%d",&no2);
	printf("Toplam kiralama tutari:%d\n",fiyat);
	printf("\tIsleminiz tamamlanmistir iyi gunler dileriz\n");
	
	ciro(fiyat);
	
	system("pause");
	
	FILE *fis;
	fis=fopen("fisnolar.txt","a");
	fprintf(fis,"\n%d",fisno);
	fclose(fis);

}
