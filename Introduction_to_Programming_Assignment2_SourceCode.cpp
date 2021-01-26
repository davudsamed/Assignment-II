/****************************************************************************
**					       SAKARYA ÜNÝVERSÝTESÝ
**			        BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				         PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 2
**				ÖÐRENCÝ ADI......: Davud Samed Tombul
**				ÖÐRENCÝ NUMARASI.: B171210007
**				DERS GRUBU.......: 1D
****************************************************************************/



#include<iostream>//Cout gibi temel komutlarý kullanmamýz için gerekli kütüphane.
#include<locale.h>//Türkçe harfleri ekrana yazdýrabilmek için kulladýðýmýz kütüphane.
#include<iomanip>//Setw() manipülatörünü kullanabilmemiz için gerekli kütüphane.
#include<time.h>//srand(time(NULL)) komutunu kullanabilmek için gerekli kütüphane.

//Her temel komuttan önce std:: yazmakla vakit kaybetmemek amaçlý kullanýyoruz. 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	//Rand() komutu ile atadýðýmýz deðerlerin programýn bir sonraki çalýþmasýnda sýfýrlanýp yeniden atanmasýný saðlar.
	srand(time(NULL));

	int sayi, sayac = 0;
	char Harf[5][10];

	//Ýç içe döngüler ile oluþturduðumuz matrisin elemanlarý atanýyor.
	for (int satir = 0; satir < 5; satir++)
	{
		for (int sütun = 0; sütun < 10; sütun++)
		{
			sayac = 0;
			//Sütunlarýn çift rakamdan oluþtuðu yerlere büyük harfler atanýyor.
			if (sütun % 2 == 0)
				sayi = 65 + rand() % 26;
			//Sütunlarýn tek rakamdan oluþtuðu yerlere büyük harfler atanýyor.
			else if (sütun % 2 != 0)
				sayi = 97 + rand() % 26;

			Harf[satir][sütun] = char(sayi);

			//Matris'e atanan 2. deðerden itibaren atanacak deðerin tekrarýnýn olup olmadýðý kontol ediliyor.
			if (satir + sütun != 0)
			{
				for (int k = 0; k <= satir; k++)
				{
					for (int t = 0; t < 10; t++)
					{//Matris'e atanacak deðerden daha önce üretildiyse sayac 1 arttýrýlýyor.
						if (sayi == Harf[k][t])
							sayac++;
					}
				}//Atanan son deðerin tekrarý kontrol edildi. Kontol kendisine geldiðinde sayac 1 arttý. O sayýdan 1 tane daha var ise sayac 2 oldu.
				//Sayac'ýn 2 olmasý son deðerin önceden üretildiðini belitir. Ve son deðeri tekrar üretmek için sütun sayýsý 1 azaltýlýr.
				if (sayac == 2)
					sütun--;
			}
		   
		}
	}

	cout << setw(35) << " ---Rastgele Harfler--- " << endl;
	//Matris'e karýþýk þekilde atanan elemanlar aralarýna ayný miktarda boþluk býrakýlarak ekrana yazdýrýlýr.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << Harf[i][j];
		}
		cout << endl;
	}
	
	//Matris'e karýþýk atadýðýmýz elemanlarý ascii kodlarýný kýyaslayarak sýralýyoruz. Sýralama yaparken BUBBLE SORT metodunu kulandým.
	for (int t = 0; t < 5; t++)
	{
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
				{
					if (Harf[t][j] < Harf[k][i])
					{//Sýralama esnasýnda sayi adlý deðiþkeni elemanlarýn yerlerini deðiþtirirken kullandýk.
						sayi = Harf[t][j];
						Harf[t][j] = Harf[k][i];
						Harf[k][i] = sayi;
					}
				}
			}
		}
	}

	cout << endl;

	cout << setw(35) << "--- Sýralý Harfler ---" << endl;
	
	//Bubble sort metodunu kullanarak sýraladýðýmýz harfleri ekrana yazdýrýyoruz.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << Harf[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
