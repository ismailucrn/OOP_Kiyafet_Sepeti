#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main()
{
	while (true)
	{
		int x;
		cout << "Lutfen Gitmek Istediginiz Secenegi Tuslayiniz\n" << endl;
		cout << "1 - Sisteme Giris" << endl;
		cout << "2 - Uye Kaydi" << endl;
		cout << "3 - Cikis" << endl;
		cin >> x;

		switch (x)
		{
		case 1: //sisteme giris
			int x;
			cout << "1 - Yonetici Girisi" << endl;
			cout << "2 - Musteri Girisi" << endl;
			cout << "3 - Ust Menuye Geri Don" << endl;
			cin >> x;
			switch (x)
			{
			case 1: //yonetici girisi //kullanicilar.txt'den okunacak
				int x;
				cout << "1 - Kiyafet Urun Girisi" << endl;
				cout << "2 - Sisteme Kurye Ekleme" << endl;
				cout << "3 - Sikayet ve Oneri Okuma" << endl;
				cout << "4 - Indirim Kodu Tanimlama" << endl;
				cout << "5 - Siparislerin Faturalarini Goruntuleme" << endl;
				cout << "6 - Ust Menuye Geri Don" << endl;
				cin >> x;
				switch (x)
				{
				case 1:
					//kiyafet kategorilerinin yer aldigi dosyalara urun girisi yaptirilmasi
					break;
				case 2:
					//sisteme kurye eklenmesi
					break;
				case 3:
					//sikayet ve onerilerin okunmasi

					break;
				case 4:
					//kullaniciya inidirim kodu tanimlanmasi
					break;
				case 5:
					//yapilan siparislerin faturalarinin goruntulenmesi
					break;
				case 6:
					//Ust Menuye Geri Donus
					break;
				default:
					break;
				}
				break;
			case 2: //musteri girisi //kullanicilar.txt'den okunacak
				int x;
				cout << "1 - Kiyafetler" << endl;
				cout << "2 - Siparis Takip" << endl;
				cout << "3 - Sikayet ve Oneri" << endl;
				cout << "4 - Sifre Degistir" << endl;
				cout << "5 - Ust Menuye Geri Don" << endl;
				cin >> x;
				switch (x)
				{
				case 1:
					//elbise,tisort,pantolon,gomlek,etek,ayakkabi } 6 kategori
					//bu kategorideki urun ve urun bilgileri gosterilecek
					//kullanici istedigi secimleri yapabilecek
					//birden cok kiyafet secebilir
					//sectikten sonra kiyafet ozellestir menusu acilacak ve buradaki renk ve beden bilgisine gore secimi tamamlayacaktir
					//tum secimler tamamlaninca fatura olusturulacak // Fatura: Musteri adi, urun siparis zamanim siparis bilgileri, fiyat bilgisi.
					break;
				case 2:
					//siparis bilgileri ve siparisin ulasim suresi gosterilecek
					//ulasim suresi: yoneticinin belirledigi kurye sayisi ve gonderilecek adrese gore ayarlanacaktir
					break;
				case 3:
					//Musterilerin feedback'i oneri.txt dosyasina yazilacak
					//feedbackler yonetici tarafindan goruntulenebilecek
					break;
				case 4:
					//musteri kendi sifresini degistirebilecek
					break;
				case 5:
					//Ust Menuye Geri Donus
					break;
				default:
					break;
				}
				break;
			case 3:
				//Ust Menuye Geri Donus
				break;
			default:
				break;
			}
			break;
		case 2: //uye kaydi
			//musterilerin gerekli bilgileri alinarak kullanicilar.txt'ye yazilacak
			//girilen e-posta'nin gecerliligi test edilecek
			//girilien gun, ay, yil'in uygun formatta yazildigi kontrol edilecek
			//sifre belirlenirken sifre yerine ekranda * gosterilecek
			//musteriye "guclu sifre" girdirmek zorunlu kildirilacak
			break;
		case 3:
			//programdan cikis
			break;
		default:
			break;
		}
	}
}
