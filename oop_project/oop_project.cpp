#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <conio.h>
using namespace std;

bool is_email_valid(string& email)  // e mail validation icin gerekli olan fonksiyon
{
	// define a regular expression
	const regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return regex_match(email, pattern);
}

string getpass(const char* prompt, bool show_asterisk = true) // sifre maskeleme icin gerekli olan fonksiyon
{
	const char BACKSPACE = 8;
	const char RETURN = 13;

	string password;
	unsigned char ch = 0;

	cout << prompt << endl;

	while ((ch = _getch()) != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else if (ch == 0 || ch == 224) // handle escape sequences
		{
			_getch(); // ignore non printable chars
			continue;
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	cout << endl;
	return password;

	//main'e yazilacak maskeleme islemi
	//string password = getpass("Please enter the password: ", true); // Show asterisks
	//cout << password << endl;
}

vector<string> splitstr(string str, string deli = " ") // split fonksiyonu
{
	vector<string> liste;
	int start = 0;
	int end = str.find(deli);
	while (end != -1) {
		liste.push_back(str.substr(start, end - start));
		start = end + deli.size();
		end = str.find(deli, start);
	}
	liste.push_back(str.substr(start, end - start));
	return liste;
}



// class'lar (tam degil, duzensiz ve taslak halinde) ++++++++++
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
	int kiyafet_adi;
	string boyut;
	string renk;
public:
	Kiyafet();
};

class Siparis : public Kiyafet
{
	int siparis_no;
	double siparis_fiyat;
	Zaman siparis_baslangic;
	Zaman siparis_ulasim_zaman;
};

class Kisi
{
protected:
	string ad_soyad;
	string telno;
public:
	Kisi(string ad_soyad, string telno) 
	{
		set_ad_soyad(ad_soyad);
		set_telno(telno);
	}
	void set_ad_soyad(string ad_soyad)
	{
		this->ad_soyad = ad_soyad;
	}
	string get_ad_soyad();
	void set_telno(string telno)
	{
		this->telno = telno;
	}
	string get_telno();
};


class Kullanici : public Kisi
{
private:
	string kullanici_adi;
	string eposta;
	string adres_ilce;
	string sifre;
	string indirim_kodu;
	string dtarihi;
public:
	Kullanici(string ad_soyad, string telno, string kullanici_adi, string eposta, string dtarihi, string sifre, string adres_ilce) : Kisi(ad_soyad, telno)
	{
		set_kullanici_adi(kullanici_adi);
		set_eposta(eposta);
		set_dtarihi(dtarihi);
		set_sifre(sifre);
		set_adres_ilce(adres_ilce);
	}
	void set_kullanici_adi(string kullanici_adi)
	{
		this->kullanici_adi = kullanici_adi;
	}
	void set_eposta(string eposta)
	{
		this->eposta = eposta;
	}
	void set_dtarihi(string dtarihi)
	{
		this->dtarihi = dtarihi;
	}
	void set_sifre(string sifre)
	{
		this->sifre = sifre;
	}
	void set_adres_ilce(string adres_ilce)
	{
		this->adres_ilce = adres_ilce;
	}
	void sifre_degistir(string sifre)
	{
		set_sifre(sifre);
	}
};

class Yonetici : public Kisi
{
private:
	string sifre;
};

class Kurye : Kisi
{
	Zaman dagitim_bitisler;
	int siparis_numaralari;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



/////////////////////////////////////////////// uye kaydi kismi

void ad_soyad() 
{
	cout << "lutfen ad ve soyadinizi giriniz." << endl;
	string ad_soyad;
	getline(cin, ad_soyad);

	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << ad_soyad;
		kullanicilar << "|";
		kullanicilar.close();
	}
}

void tel_no()
{
	string tel_no = "";
	while (tel_no.length() != 11)
	{
		cout << "lutfen 11 haneli telefon numaranizi giriniz." << endl;
		getline(cin, tel_no);
	}
	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << tel_no;
		kullanicilar << "|"; 
		kullanicilar.close();
	}
}

void kullanici_adi()
{
	cout << "lutfen kullanici adinizi giriniz." << endl;
	string kullanici_adi;
	getline(cin, kullanici_adi);

	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << kullanici_adi;
		kullanicilar << "|";
		kullanicilar.close();
	}
}

void e_posta()
{
	string e_posta = "";
	while (is_email_valid(e_posta) == false)
	{
		cout << "lutfen duzgun formatta e-posta adresinizi giriniz." << endl;
		getline(cin, e_posta);
	}
	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << e_posta;
		kullanicilar << "|";
		kullanicilar.close();
	}

}

void dtarihi()
{
	int gun;
	int ay;
	int yil;

	cout << "dogdugunuz gunu giriniz" << endl;
	while (true)
	{
		cin >> gun;
		if (gun > 31)
		{
			"lutfen gecerli bir gun girin";
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "dogdugunuz ayi giriniz" << endl;
	while (true)
	{
		cin >> ay;
		if (ay > 12)
		{
			"lutfen gecerli bir ay girin";
			continue;
		}
		else 
		{
			break;
		}
	}
	cout << "dogdugunuz yili girin" << endl;
	while (true)
	{
		cin >> yil;
		if (yil < 1900)
		{
			"lutfen gecerli bir yil girin";
			continue;
		}
		else 
		{
			break;
		}
	}
	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << gun;
		kullanicilar << "/";
		kullanicilar << ay;
		kullanicilar << "/";
		kullanicilar << yil;
		kullanicilar << "|";
		kullanicilar.close();
	}
}

void sifre()
{
	int lower = 0;
	int upper = 0;
	int number = 0;
	string password;
	while (true)
	{	
		password = getpass("lutfen olusturmak istediginiz sifreyi giriniz", true);
		for (int i = 0; i < password.length(); i++)
		{
			if (isupper(password[i]))
			{
				upper = 1;
			}
			else if (password[i] == '0' || password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6' || password[i] == '7' || password[i] == '8' || password[i] == '9')
			{
				number = 1;
			}
			else if (islower(password[i]))
			{
				lower = 1;
			}
		}
		if (upper == 1 && lower == 1 && number == 1) { break; }
		else 
		{
			cout << "sifre icerisinde en az bir kucuk harf, bir buyuk harf ve rakam bulunmalidir";
			continue;
		}
	}
	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	if (kullanicilar.is_open())
	{
		kullanicilar << password;
		kullanicilar << "|";
		kullanicilar.close();
	}


}

void adres_ilce()
{
	fstream kullanicilar;
	kullanicilar.open("kullanicilar.txt", ios::app);
	int x;
	cout << "lutfen bulundugunuz ilcenin numarasini tuslayiniz." << endl;
	cout << "1-Ortahisar" << endl;
	cout << "2-Akcaabat" << endl;
	cout << "3-Vakfikebir" << endl;
	cout << "4-Besikduzu" << endl;
	cout << "5-Yomra" << endl;
	cout << "6-Arsin" << endl;
	cout << "7-Arakli" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Ortahisar";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 2:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Akcaabat";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 3:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Vakfikebir";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 4:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Besikduzu";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 5:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Yomra";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 6:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Arsin";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	case 7:
		if (kullanicilar.is_open())
		{
			kullanicilar << "Arakli";
			kullanicilar << "\n";
			kullanicilar.close();
		}
	}
}

void uye_kaydi()
{
	ad_soyad();
	tel_no();
	kullanici_adi();
	e_posta();
	dtarihi();
	sifre();
	adres_ilce();
}
/////////////////////////////////////////////// uye kaydi kismi bitti

//...................... kullanici ve yonetici giris ..........................
vector<vector<string>> kullanici_list;
void kullanici_txt() // kullanici txt parser.
{
	fstream myFile;
	myFile.open("kullanicilar.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			kullanici_list.push_back(splitstr(line, "|"));
		}
		myFile.close();
	}
}

//create Kullanici vector
vector<Kullanici> kullanicilar;

void musteri_girisi()
{
	int satir = 0;
	int k_flag=0; //kullanici adi flag
	int p_flag=0; //password flag
	while (true)
	{
		cout << "lutfen kullanici adinizi giriniz" << endl;
		string kullanici_adi;
		getline(cin, kullanici_adi);
		string password = getpass("lutfen sifrenizi giriniz", true);
		for (int i = 0; i < kullanici_list.size();i++)
		{
			if (kullanici_adi == kullanici_list[i][2])
			{
				k_flag = 1;
			}
		}
		for (int i = 0; i < kullanici_list.size(); i++)
		{
			if (password == kullanici_list[i][5])
			{
				p_flag = 1;

				break;
			}
			satir++;
		}
		if (p_flag != 1 or k_flag != 1)
		{
			cout << "kullanici adi veya sifre hatali girilmistir lutfen tekrar deneyiniz" << endl << endl;
			continue;
		}
		else 
		{
			break;
		}
	}
	Kullanici Musteri1(kullanici_list[satir][0], kullanici_list[satir][1], kullanici_list[satir][2], kullanici_list[satir][3], kullanici_list[satir][4], kullanici_list[satir][5], kullanici_list[satir][6]);
	kullanicilar.push_back(Musteri1);
		int x;
		cout << "Lutfen erismek istediginiz menunun numarasini tuslayiniz" << endl << endl;
		cout << "1 - Kiyafet satin al" << endl;
		cout << "2 - Siparis takip" << endl;
		cout << "3 - Sikayet/Oneri yaz" << endl;
		cout << "4 - Sifre degistir" << endl;
		cout << "5 - Geri menu" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			//kategoriler
			break;
		case 2:
			//kategoriler
			break;
		case 3:
			void oneri_yaz();
			break;
		{case 4:
			int lower = 0;
			int upper = 0;
			int number = 0;
			string password;
			while (true)
			{
				password = getpass("lutfen olusturmak istediginiz sifreyi giriniz", true);
				for (int i = 0; i < password.length(); i++)
				{
					if (isupper(password[i]))
					{
						upper = 1;
					}
					else if (password[i] == '0' || password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6' || password[i] == '7' || password[i] == '8' || password[i] == '9')
					{
						number = 1;
					}
					else if (islower(password[i]))
					{
						lower = 1;
					}
				}
				if (upper == 1 && lower == 1 && number == 1) { break; }
				else
				{
					cout << "sifre icerisinde en az bir kucuk harf, bir buyuk harf ve rakam bulunmalidir";
					continue;
				}
			}
			Musteri1.sifre_degistir(password);
			break; }
		case 5:
			//kategoriler
			break;
		}
}


vector<vector<string>> yonetici_list;
void yonetici_txt() // yonetici txt parser.
{
	fstream myFile;
	myFile.open("yoneticiler.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			yonetici_list.push_back(splitstr(line, "|"));
		}
		myFile.close();
	}
}

void yonetici_girisi()
{
	int p_flag = 0;
	while (true)
	{
		string password = getpass("lutfen yonetici sifrenizi giriniz", true);
		for (int i = 0; i < yonetici_list.size(); i++)
		{
			if (password == yonetici_list[i][2])
			{
				p_flag = 1;
			}
		}
		if (p_flag != 1)
		{
			cout << "hatali sifre girdiniz lutfen tekrar giriniz." << endl << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	int x;
	cout << "Girmek istediginiz kategoriyi belirtiniz" << endl << endl;
	cout << "1 - Kiyafet ekleme" << endl;
	cout << "2 - Sisteme kurye eklenmesi" << endl;
	cout << "3 - Sikayet ve oneri okunmasi" << endl;
	cout << "4 - Kullaniciya indirim kodu tanimlanmasi" << endl;
	cout << "5 - Yapilan siparislerin faturalarinin goruntulenmesi" << endl;
	cout << "6 - Geri menu" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		//kategoriler
		break;
	case 2:
		//kategoriler
		break;
	case 3:
		void oneri_oku();
		break;
	case 4:
		//kategoriler
		break;
	case 5:
		//kategoriler
		break;
	case 6:
		//kategoriler
		break;
	}

	//create switch case
	
	
}



void oneri_oku()
{
	fstream myFile;
	myFile.open("oneriler.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			cout << line << endl;
		}
		myFile.close();
	}
}
void oneri_yaz()
{
	cout << "lutfen sikayet veya onerinizi yaziniz." << endl;
	string kullanici_adi;
	getline(cin, kullanici_adi);

	fstream myFile;
	myFile.open("oneriler.txt", ios::app);
	if (myFile.is_open())
	{
		myFile << kullanici_adi;
	}
}




int main()
{
	//kullanici_txt();
	//musteri_girisi();
	uye_kaydi();
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
	//		case 1: //yonetici girisi //yonetici.txt'den okunacak
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
	//		uye_kaydi();
	//		break;
	//	case 3:
	//		//programdan cikis
	//		break;
	//	default:
	//		break;
	//	}
	//}
}
