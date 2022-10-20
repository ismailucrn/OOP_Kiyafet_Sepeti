#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <conio.h>
using namespace std;

bool is_email_valid(string& email) //email matching
{
	// define a regular expression
	const regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return regex_match(email, pattern);
}

void password()
{

}

class Zaman
{
private:
	int saat;
	int dakika;
public:
};

class Kiyafet
{
private:
	string kategori;
	double fiyat;
	string kiyafet_adi;
	string boyut;
	string renk;
public:
	Kiyafet();
};

class Kisi
{
protected:
	string ad_soyad;
	int telno;
public:
	void set_ad_soyad();
	string get_ad_soyad();
	void set_telno();
	int get_telno();
};
/////////////////////////////////////////////////////////////////////////////
class Kullanici : public Kisi
{
private:
	string kullanici_adi;
	string eposta;
	string adres_ilce;
	string sifre;
	string indirim_kodu;
	string dtarihi;
	vector <string> to_txt;
public:
	void set_kullanici_adi(string kullanici_adi)
	{
		this->kullanici_adi = kullanici_adi;
		to_txt.push_back(this->kullanici_adi);
	}
	string get_kullanici_adi()
	{
		return this->kullanici_adi;
	}
	void set_eposta(string eposta)
	{
		this->eposta = eposta;
		//to_txt'ye pushlanmasi gerek
	}
	string get_eposta()
	{
		return this->eposta;
	}
	void set_adres_ilce(string ilce)
	{
		this->adres_ilce = ilce;
		//to_txt'ye pushlanmasi gerek
		//trabzon ilce adresleri arasinda olmasi gerek
	}
	string get_adres_ilce()
	{
		return this->adres_ilce;
	}
	void set_sifre(string sifre)
	{
		this->sifre = sifre;
		to_txt.push_back(this->sifre);
	}
	string get_sifre()
	{
		return this->sifre;
	}
	void set_dtarihi(string gun, string ay,string yil)
	{
		this->dtarihi = gun + "/" + ay + "/" + yil;
		to_txt.push_back(this->dtarihi);
	}
	string get_dtarihi()
	{
		return this->dtarihi;
	}
};

//////////////////////////////////////////////////////////////////////////////////
class Yonetici : public Kisi
{
private:
	string sifre;
};

class Kurye : Kisi
{

};

void uye_kaydi()
{

}











int main()
{
	//while (true)
	//{
	//	int x;
	//	cout << "Lutfen Gitmek Istediginiz Secenegi Tuslayiniz\n" << endl;
	//	cout << "1 - Sisteme Giris" << endl;
	//	cout << "2 - Uye Kaydi" << endl;
	//	cout << "3 - Cikis" << endl;
	//	cin >> x;

	//	switch (x)
	//	{
	//	case 1: //sisteme giris
	//		int x;
	//		cout << "1 - Yonetici Girisi" << endl;
	//		cout << "2 - Musteri Girisi" << endl;
	//		cout << "3 - Ust Menuye Geri Don" << endl;
	//		cin >> x;
	//		switch (x)
	//		{
	//		case 1: //yonetici girisi //kullanicilar.txt'den okunacak
	//			int x;
	//			cout << "1 - Kiyafet Urun Girisi" << endl;
	//			cout << "2 - Sisteme Kurye Ekleme" << endl;
	//			cout << "3 - Sikayet ve Oneri Okuma" << endl;
	//			cout << "4 - Indirim Kodu Tanimlama" << endl;
	//			cout << "5 - Siparislerin Faturalarini Goruntuleme" << endl;
	//			cout << "6 - Ust Menuye Geri Don" << endl;
	//			cin >> x;
	//			switch (x)
	//			{
	//			case 1:
	//				//kiyafet kategorilerinin yer aldigi dosyalara urun girisi yaptirilmasi
	//				break;
	//			case 2:
	//				//sisteme kurye eklenmesi
	//				break;
	//			case 3:
	//				//sikayet ve onerilerin okunmasi

	//				break;
	//			case 4:
	//				//kullaniciya inidirim kodu tanimlanmasi
	//				break;
	//			case 5:
	//				//yapilan siparislerin faturalarinin goruntulenmesi
	//				break;
	//			case 6:
	//				//Ust Menuye Geri Donus
	//				break;
	//			default:
	//				break;
	//			}
	//			break;
	//		case 2: //musteri girisi //kullanicilar.txt'den okunacak
	//			int y;
	//			cout << "1 - Kiyafetler" << endl;
	//			cout << "2 - Siparis Takip" << endl;
	//			cout << "3 - Sikayet ve Oneri" << endl;
	//			cout << "4 - Sifre Degistir" << endl;
	//			cout << "5 - Ust Menuye Geri Don" << endl;
	//			cin >> y;
	//			switch (y)
	//			{
	//			case 1:
	//				//elbise,tisort,pantolon,gomlek,etek,ayakkabi } 6 kategori
	//				//bu kategorideki urun ve urun bilgileri gosterilecek
	//				//kullanici istedigi secimleri yapabilecek
	//				//birden cok kiyafet secebilir
	//				//sectikten sonra kiyafet ozellestir menusu acilacak ve buradaki renk ve beden bilgisine gore secimi tamamlayacaktir
	//				//tum secimler tamamlaninca fatura olusturulacak // Fatura: Musteri adi, urun siparis zamanim siparis bilgileri, fiyat bilgisi.
	//				break;
	//			case 2:
	//				//siparis bilgileri ve siparisin ulasim suresi gosterilecek
	//				//ulasim suresi: yoneticinin belirledigi kurye sayisi ve gonderilecek adrese gore ayarlanacaktir
	//				break;
	//			case 3:
	//				//Musterilerin feedback'i oneri.txt dosyasina yazilacak
	//				//feedbackler yonetici tarafindan goruntulenebilecek
	//				break;
	//			case 4:
	//				//musteri kendi sifresini degistirebilecek
	//				break;
	//			case 5:
	//				//Ust Menuye Geri Donus
	//				break;
	//			default:
	//				break;
	//			}
	//			break;
	//		case 3:
	//			//Ust Menuye Geri Donus
	//			break;
	//		default:
	//			break;
	//		}
	//		break;
	//	case 2: //uye kaydi
	//		//musterilerin gerekli bilgileri alinarak kullanicilar.txt'ye yazilacak
	//		//girilen e-posta'nin gecerliligi test edilecek
	//		//girilien gun, ay, yil'in uygun formatta yazildigi kontrol edilecek
	//		//sifre belirlenirken sifre yerine ekranda * gosterilecek
	//		//musteriye "guclu sifre" girdirmek zorunlu kildirilacak
	//		break;
	//	case 3:
	//		//programdan cikis
	//		break;
	//	default:
	//		break;
	//	}
	//}
char pw[8], ch;
int i;
cout << "Lutfen 8 karakter uzunluktaki sifrenizi giriniz" << endl;
for (i = 0; i < 8; i++)
{
	ch = _getch();
	pw[i] = ch;
	ch = '*';
	cout << "" << ch;
}
cout << endl << "parolaniz: " << pw;
}
