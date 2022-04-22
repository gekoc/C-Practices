#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include<conio.h>

int main() {

	do{
	switch (kullaniciSecimi())
	{
	case 1:
		basamaksayici();
		break;
	case 2:
		fiyatHesaplayici();
		break;
	case 3:
		ucgenCizilirMi();
		break;
	case 4:
		faktoriyelHesaplayici();
		break;
	case 5:
		asalSayiMi();
		break;

	default:
		break; 
	}
	_getch();
	system("@cls||clear");
	}while (1);




	return 0;
}

int kullaniciSecimi() {

	int kullaniciSecimi = 0;
	printf("Lutfen yapmak istediginiz islemi secin:\n");
	printf("1. Basamak Sayici\n");
	printf("2. Fiyat Hesaplayici\n");
	printf("3. Ucgen Cizilir mi?\n");
	printf("4. Faktoriyel Hesaplayici\n");
	printf("5. Asal sayi mi?\n");


	scanf_s("%d", &kullaniciSecimi);

	return kullaniciSecimi;
}

int asalSayiMi() {

	int sayi, asalCounter=0;
	printf("Bir sayi gir");
	scanf("%d", &sayi);

	for (int i = 2; i < sayi; i++) {
		if (sayi % i == 0) {
			asalCounter++;
			break;
		}
	}

	if (asalCounter == 0) {
		printf("%d sayisi asaldir.\n", sayi);
	}
	else printf("%d sayisi asal degildir.\n", sayi);
}

int faktoriyelHesaplayici() {
	int sayi, sonuc= 1;
	printf("Faktoriyeli hesaplanacak sayiyi giriniz:\n");
	scanf("%d", &sayi);

	for (int i = 1; i <= sayi; i++) {

		sonuc *= i;
	}

	printf("%d faktoriyel = %d\n", sayi, sonuc);

	return 0;
}




int fiyatHesaplayici() {
	srand(time(NULL));
	int fiyat = rand() % 1000;
	int taksitYaniti, indirimKarti;

	printf("Alacaginiz urunun fiyati %d TL.\n", fiyat);
	printf("Sadece %%10 faiz ile 6 Taksit olsun mu?\n");
	printf("1. Olsun\n");
	printf("2. Kalsin\n");
	scanf_s("%d", &taksitYaniti);

	if (taksitYaniti == 1) {
		fiyat += fiyat / 10;
		printf("Taksitli fiyat %d TL.\n", fiyat);
	}
	else printf("Taksit secmediniz. Tek Cekim Fiyat %d TL\n", fiyat);

	printf("Indirim kartiniz var mi?\n");
	printf("1. Var, al\n");
	printf("2. O ne?\n");
	scanf_s("%d", &indirimKarti);

	if (indirimKarti == 1) {
		fiyat -= fiyat / 10;
		printf("Indirimli fiyat %d TL.\n", fiyat);
	}
	else printf("odemeniz gereken tutar %d TL.\n", fiyat);

	
	return 0;

}

int basamaksayici() {
	
	int sayi, geciciSayi, basamak = 0;
	printf("Lutfen bir sayi giriniz");
	scanf_s("%d", &sayi);

	geciciSayi = sayi;

	while (geciciSayi != 0) {
		geciciSayi /= 10;
		basamak++;
	}

	printf("%d sayisi %d basamaklidir.\n", sayi, basamak);


	return 0;

}

int ucgenCizilirMi() {
	int x, y, z;
	int deger = 0;
	printf("Lutfen bir ucgen icin 3 adet kenar degeri giriniz:");
	scanf_s("%d%d%d", &x, &y, &z);

	if (x >= y + z || x <= abs(y - z)) {

		deger++;
	}
	else if (y >= x + z || y <= abs(x - z)) {
		deger++;
	}
	else if (z >= y + x || z <= abs(y - x)) {
		deger++;
	}

	if (deger != 0) {
		printf("Bu kenarlarla ucgen cizilemez.");
	}
	else printf("Bu kenarlarla ucgen cizilir.");

	//ic ice if de kullanılabilirdi. 
	
}

void notlar() {
	/*
int sayi = 1234;

printf("Sayi 10luk taban: %d\n", sayi);
printf("Sayi 16lik taban: %X\n", sayi);//4D2 = 16^0 X 2 + 16^1 X 13 + 16^2 X 4 = 1234
printf("Sayi 8lik taban: %o\n", sayi); //2322 = 8^0 X 2 + 8^1 X 2 + 8^2 X 3 + 8^3 X 2 =  1234

float sayiF = 1.123456;

printf("SayiF normal hali:%f\n", sayiF);
printf("SayiF bilimsel hali:%e\n", sayiF);
printf("SayiF bilimsel hali:%E\n", sayiF);
printf("SayiF bilimsel hali:%g\n", sayiF);
printf("SayiF bilimsel hali:%G\n", sayiF);

printf("Merhaba Dunya!\n"); // \n bir alt satira gecmek icin
printf("Merhaba \t Dunya!\n");// \t bir tab kadar boşluk birakir
printf("Merhaba \bDunya!\n");// \b bir backspace koyar
printf("Merhaba\bDunya!\n");
printf("Merhaba \\ Dunya!\n"); //tek "\" yapmak için iki adet \ koymak gerek.
printf("\"Merhaba Dunya!\"\n"); // "" tırnak içinde yazmak için tırnağı "\ ve \" ile belirtmek gerek.
printf("Merhaba 5%%7 Dunya!\n");// % işareti yazdırmak için %% şeklinde girilmeli.



char karakter = 'a';
char karakterDizisi[] = "1234.1234";

printf("%c karakterinin hafizada kapladigi alan: %d byte. \n", karakter, sizeof(karakter));
printf("%c karakterinin decimal karsiligi: %d, hexadecimal karsiligi: %X \n", karakter, karakter, karakter);

printf("\n");
printf("\n");

// sonuç 0 ise yanlış, 0 harici değerler doğru. ialpha fonksiyonu karakterin alfabetik bir karakter olup olmadığını sorgular.
printf("karakter icin isalpha sonucu: %d\n", isalpha(karakter));
printf("sayi icin isalpha degeri: %d\n", isalpha('5'));
printf("\n");
printf("sayi icin isdigit sonucu: %d\n", isdigit('5'));
printf("karakter icin isdigit sonucu: %d\n", isdigit(karakter));
printf("\n");
printf("karakter icin isalnum sonucu: %d\n", isalnum(karakter));
printf("sayi icin isalnum sonucu: %d\n", isalnum('5'));
printf("isaret icin isalnum sonucu: %d\n", isalnum('!'));
printf("\n");
printf("H icin islower sonucu: %d\n", islower('H'));
printf("b icin islower sonucu: %d\n", islower('b'));
printf("\n");
printf("H icin isupper sonucu: %d\n", isupper('H'));
printf("b icin isupper sonucu: %d\n", isupper('b'));
printf("\n");
printf("b icin toupper sonucu: %c\n", toupper('b'));
printf("H icin tolower sonucu: %c\n", tolower('H'));

int tamSayi;
float ondalikliSayi;

tamSayi = atoi(karakterDizisi); //string ifadeyi tam sayıya çevirir.
ondalikliSayi = atof(karakterDizisi); // string ifadeyi floata çevirir.

printf("Sayi: %d\n", tamSayi);
printf("Sayi: %.4f \n", ondalikliSayi);




int sayi1 = 15, sayi2 = 25;

printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 > sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 < sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 == sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 != sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 >= sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, sayi1 <= sayi2);
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, (sayi1 != sayi2) && (sayi1 <sayi2));
printf("Birinci sayi %d, ikinci sayi %d, sorgu sonucu (1 veya 0):%d \n", sayi1, sayi2, (sayi1 != sayi2) || (sayi1 > sayi2));


// bit düzeyindeki mantıksal operatörler:

int bitDuzeyi1 = 64; // 0100 0000
int bitDuzeyi2 = 32; // 0010 0000
printf("\n");
printf("\n");


printf("Bit duzeyinde ve operatoru sonuc: %d\n", bitDuzeyi1 & bitDuzeyi2);
printf("Bit duzeyinde veya operatoru sonuc: %d\n", bitDuzeyi1 | bitDuzeyi2);



64 = 0100 0000 --> bit düzeyinde karşılaştırma her bir basamağın birbiriyle karşılaştırılmasıyla olur
32 = 0010 0000 --> "ve" operatörü için aynı basamaktaki değerlerin ikisinin de 1 olması gerekmektedir.
sonuc  = 0000 0000 --> eşleşme yok

	64 = 0100 0000 --> veya operasotu için tek bir basamağın 1 olması sonuc basamağının 1 olması için yeterlidir.
	32 = 0010 0000 -->
sonuc  = 0110 0000 --> bu durumda sonuc 2^6 + 2^5 = 96 olur.



	bitDuzeyi1 = 10;  // 0000 1010 --> ve için sonuc binary sistemde 1000 yani ondalık sistemde 8 çıkar.
	bitDuzeyi2 = 13;  // 0000 1101 --> veya için sonuc binary sistemde 1111 yani ondalık sistemde 15 çıkar.

	printf("Bit duzeyinde ve operatoru 10 ve 13 icin sonuc: %d\n", bitDuzeyi1& bitDuzeyi2);
	printf("Bit duzeyinde veya operatoru 10 ve 13 icin sonuc: %d\n", bitDuzeyi1 | bitDuzeyi2);

	*/

	/*int paraMiktari;

	printf("Lutfen bir para miktari giriniz.\n");
	scanf_s("%d", &paraMiktari);

	printf("%d adet 200 TL bulunmaktadir.\n", paraMiktari / 200);
	paraMiktari %= 200;
	printf("%d adet 100 TL bulunmaktadir.\n", paraMiktari / 100);
	paraMiktari %= 100;
	printf("%d adet 50 TL bulunmaktadir.\n", paraMiktari / 50);
	paraMiktari %= 50;
	printf("%d adet 20 TL bulunmaktadir.\n", paraMiktari / 20);
	paraMiktari %= 20;
	printf("%d adet 10 TL bulunmaktadir.\n", paraMiktari / 10);
	paraMiktari %= 10;
	printf("%d adet 1 TL bulunmaktadir.\n", paraMiktari);*/


	/*printf("Tersi alinacak 3 basamakli sayiyi girin\n");

	int sayi, geciciSayi;
	scanf_s("%d", &sayi);

	geciciSayi = sayi;

	printf("%d", geciciSayi % 10);
	geciciSayi /= 10;
	printf("%d", geciciSayi % 10);
	geciciSayi /= 10;
	printf("%d", geciciSayi % 10);
	geciciSayi /= 10;*/

	/*
	Odev:

	1: Kullanıcıdan a, b, c sayıları alıp delta hesaplaması yaparak deltanın 0'dan küçük veya büyük olma durumunu bulun.

	2: kullanıcıdan vize ve final notlarını alarak yüzde değerlerine göre ortalamasını alınız (%20 - %80)
	dersi geçiyorsa 1, geçemiyorsa 0 yazınız. geçme notu 51.

	3:kullanıcıdan yarıçap alıp dairenin çevresini ve alanını hesaplayın.

	*/

	//int a,b, c, delta, bKare;
	//


	//printf("delta hesabi icin a sayisini girin:\n");
	//scanf_s("%d", &a);
	//printf("delta hesabi icin b sayisini girin:\n");
	//scanf_s("%d", &b);
	//printf("delta hesabi icin c sayisini girin:\n");
	//scanf_s("%d", &c);

	//bKare = pow((double)b, 2);

	//delta = bKare - (4 * a * c);

	//printf("delta = %d. deltanin sifirdan buyuk olma durumu: %d\n", delta, delta > 0);

	//printf("\n");
	//printf("\n");
	//printf("\n");


	//int vize, final, senePuani;

	//printf("vize notunuzu girin:\n");
	//scanf_s("%d", &vize);
	//printf("final notunuzu girin:\n");
	//scanf_s("%d", &final);

	//senePuani = vize * 0.2 + final * 0.8;

	//printf("Yil sonu puani: %d. Sinif gecme durumu: %d\n", senePuani, senePuani >= 51);


	//int yaricap, cevre, alan;

	//printf("yaricap girin\n");
	//scanf_s("%d", &yaricap);
	//

	//cevre = 2 * M_PI * yaricap;
	//alan = M_PI * pow((double)yaricap, 2);

	//printf("Yaricapi %d olan dairenin cevresi %d, alani %d\n", yaricap, cevre, alan);


/*
 KOŞUL DURUMLARI

 koşul durumunda 0 haricindeki her sayısal değer "doğru" anlamındadır.
*/


/*
int sayi, sayi2, sayi3;

srand(time(NULL));// bu methodu çalıştırmazsak rand her seferinde aynı değeri üretir. Bu method randomun generate edilmesini sağlıyor.
sayi = rand() % 100; //0 ile 100 arasında herhangi bir sayı üretir.
sayi2 = rand() % 100;
sayi3 = rand() % 5 + 11; //Verilen iki değer arasında random üretmek için r = (rand() % (max + 1 - min)) + min kullanılır.

printf("Birinci sayi %d, ikinci sayi %d\n", sayi, sayi2);

printf("Ucuncu sayi ise 11-15 araliginda olmali. Ucuncu sayi: %d\n", sayi3);

if (sayi < sayi2) {
	printf("%d degeri %d degerinden kucuktur.\n", sayi, sayi2);
}
else if (sayi == sayi2) {
	printf("%d degeri %d degerine esittir.\n", sayi, sayi2);

}
else {

	printf("%d degeri %d degerinden buyktur.\n", sayi, sayi2);
}

if (sayi % 2 == 0) {
	printf("%d sayisi cift sayidir.\n", sayi);
}
else {
	printf("%d sayisi tek bir sayidir. \n", sayi);

}

*/



/*
int sayi1, sayi2;
float sonuc;
char ch;

printf("Lutfen 2 adet sayi giriniz.\n");
scanf_s("%d%d", &sayi1, &sayi2);
printf("Lutfen yapmak istediginiz islemi giriniz (+ , - , * , / )\n");
scanf_s("%*c%c", &ch);

if (ch == '+') {
	sonuc = sayi1 + sayi2;
	printf("Yaptiginiz islem: %d + %d = %.2f\n", sayi1, sayi2, sonuc);
}
else if (ch == '-') {
	sonuc = sayi1 - sayi2;
	printf("Yaptiginiz islem: %d - %d = %.2f\n", sayi1, sayi2, sonuc);
}
else if (ch == '*') {
	sonuc = sayi1 * sayi2;
	printf("Yaptiginiz islem: %d * %d = %.2f\n", sayi1, sayi2, sonuc);
}
else if (ch == '/') {
	sonuc = sayi1 / sayi2;
	printf("Yaptiginiz islem: %d / %d = %.2f\n", sayi1, sayi2, sonuc);
}
else {
	printf("Yanlis karakter girdiniz.\n");
}


*/

}