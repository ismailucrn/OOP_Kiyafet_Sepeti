#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <conio.h>
#include <random>
using namespace std;

class Kiyafet {
private:
	string kategori;
	int kiyafet_adi;
	double fiyat;
	string boyut;
	string renk;

public:
	Kiyafet(string kategori, int kiyafet_adi, double fiyat, string boyut, string renk) {
		set_kategori(kategori);
		set_kiyafet_adi(kiyafet_adi);
		set_fiyat(fiyat);
		set_boyut(boyut);
		set_renk(renk);
	}
	void set_kategori(string kategori)
	{
		this->kategori = kategori;
	}
	void set_kiyafet_adi(int kategori)
	{
		this->kiyafet_adi = kiyafet_adi;
	}
	void set_fiyat(double fiyat)
	{
		this->fiyat = fiyat;
	}
	void set_boyut(string boyut)
	{
		this->boyut = boyut;
	}
	void set_renk(string renk)
	{
		this->renk = renk;
	}
};

vector<string> kod_list;
void kod_liste_olustur() {
	fstream myFile;
	myFile.open("indirimkodu.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			kod_list.push_back(line);


		}
		for (int i = 0; i < kod_list.size(); i++)
		{

		}
		myFile.close();
	}
}



class Siparis {
private:
	int siparis_no;
	double siparis_fiyat;
	vector<vector<string>>urunler;
public:

	Siparis(vector<vector<string>>urunler) {

		set_urunler(urunler);
		set_siparis_fiyat();
		set_siparis_no();
		fatura_goster();
	};
	int get_siparis_no() {
		return siparis_no;
	}
	double get_siparis_fiyat() {
		return siparis_fiyat;
	}
	void set_siparis_fiyat()
	{
		double fiyat;
		string kod;
		for (int i = 0; i < urunler.size(); i++)
		{
			fiyat = stod(urunler[i][3]);

			siparis_fiyat = fiyat + siparis_fiyat;
		}

		cout << "indirim koduna sahipseniz giriniz" << endl;
		cin >> kod;
		for (int i = 0; i < kod_list.size(); i++)
		{
			if (kod == kod_list[i]) {
				cout << "indirim kodu dogru!" << endl;
				siparis_fiyat = siparis_fiyat - (siparis_fiyat * 0.2);
				break;
			}
			else {
				cout << "gecersiz kod!";
				break;

			}
		}

	}
	void set_urunler(vector<vector<string>>urunler)
	{
		this->urunler = urunler;
	}
	void set_siparis_no() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dist(100000, 999999);
		int rastgele_sayi = dist(gen);
		this->siparis_no = rastgele_sayi;
	}

	void fatura_goster() {
		cout << "almis oldugunuz urunler" << endl;
		for (int i = 0; i < urunler.size(); i++)
		{
			for (int c = 0; c < 6; c++) {
				cout << urunler[i][c] << " ";

			};
			cout << endl << endl;
		}
		cout << endl << "Faturaniz:" << siparis_fiyat;


	};
};



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



void kategori()
{
	cout << "kategori giriniz" << endl;
	string category;
	cin >> category;

	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << category;
		kiyafetler << "|";
		kiyafetler.close();
	}

}
void id()
{
	cout << "Urun Id giriniz" << endl;

	string id;

	cin >> id;

	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << id;
		kiyafetler << "|";
		kiyafetler.close();
	}
}
void kiyafet_adi()
{
	cout << "kiyafet adi giriniz" << endl;
	string kiyafet_adi;
	cin >> kiyafet_adi;

	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << kiyafet_adi;
		kiyafetler << "|";
		kiyafetler.close();
	}
}
void fiyat()
{
	cout << "fiyat giriniz" << endl;

	string fiyat;

	cin >> fiyat;
	double fiyat_double = stod(fiyat);
	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << fiyat_double;
		kiyafetler << "|";
		kiyafetler.close();
	}
}

void boyut()
{
	cout << "boyut giriniz" << endl;

	string boyut;
	cin >> boyut;

	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << boyut;
		kiyafetler << "|";
		kiyafetler.close();
	}
}

void renk()
{
	cout << "renk giriniz" << endl;

	string renk;
	cin >> renk;

	fstream kiyafetler;
	kiyafetler.open("kiyafetler.txt", ios::app);
	if (kiyafetler.is_open())
	{

		kiyafetler << renk << endl;

		kiyafetler.close();
	}
}



vector<vector<string>> kiyafet_yaz(vector<vector<string>> kiyafet_list)
{
	fstream myFile;
	myFile.open("kiyafetler.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			kiyafet_list.push_back(splitstr(line, "|"));


		}
		myFile.close();
	}
	return kiyafet_list;
}
void fatura_kayit(Siparis siparis, string musteri = "Mert") {



	fstream tumfaturalar;
	tumfaturalar.open("tumfaturalar.txt", ios::app);
	if (tumfaturalar.is_open())
	{

		tumfaturalar << siparis.get_siparis_no(); tumfaturalar << "|"; tumfaturalar << siparis.get_siparis_fiyat(); tumfaturalar << "|"; tumfaturalar << musteri; tumfaturalar << "|" << endl;
		tumfaturalar.close();
	}
}

vector<vector<string>>fatura_liste;
void faturalari_goruntule() {
	fstream myFile;
	myFile.open("tumfaturalar.txt", ios::in);
	if (myFile.is_open())
	{
		string line;
		while (getline(myFile, line))
		{
			fatura_liste.push_back(splitstr(line, "|"));


		}
		myFile.close();
	}
	cout << "Faturalar" << endl;
	for (int i = 0; i < fatura_liste.size(); i++)
	{
		for (int x = 0; x < 3; x++) {
			cout << fatura_liste[i][x] << " ";
		}
	}
}


void kiyafet_toplu() {
	kategori();
	id();
	kiyafet_adi();
	fiyat();
	boyut();
	renk();
}

void indirimkodu_yaz() {
	cout << "indirim kodu gir." << endl;
	string kod;
	cin >> kod;
	fstream kodlar;
	kodlar.open("indirimkodu.txt", ios::app);
	if (kodlar.is_open())
	{

		kodlar << kod;
		kodlar << endl;
		kodlar.close();
	}
}

void function(int dec, string category, vector<vector<string>> kiyafet_list)
{

	int secim;
	int flag = 0;
	string sec;
	vector<string> liste;
	vector<string> siparis;
	vector<vector<string>> siparis_list;



	for (int i = 0; i < kiyafet_list.size(); i++)
	{

		flag = 0;
		if (category == kiyafet_list[i][0]) {

			for (int n = 0; n < liste.size(); n++)
			{

				if (kiyafet_list[i][2] == liste[n]) {
					flag = 1;
					continue;
				}
			}

			if (flag == 0) {
				cout << "isim:" << kiyafet_list[i][2] << " " << "fiyat:" << kiyafet_list[i][3] << " " << endl;
			}

			liste.push_back(kiyafet_list[i][2]);

		}
	}




	while (true)
	{
		cout << "secmek istediginiz kiyafetin adini giriniz" << endl;
		cin >> secim;
		string secim_str = to_string(secim);

		cout << "sectiginiz urune ait uygun renk ve bedenler" << endl << endl;

		for (int i = 0; i < kiyafet_list.size(); i++) {

			if (secim_str == kiyafet_list[i][2] && category == kiyafet_list[i][0]) {


				cout << kiyafet_list[i][1] << ")" << " beden:" << kiyafet_list[i][4] << " renk:" << kiyafet_list[i][5] << endl;

			}


		}

		int satir = 0;
		while (true)
		{

			cout << "istediginiz urunun id'sini giriniz " << endl << "alisverisi tamamladiysaniz sifira basiniz" << endl;
			cin >> sec;
			if (sec == "0") {
				break;
			}
			for (int i = 0; i < kiyafet_list.size(); i++)
			{

				if (sec == kiyafet_list[i][1]) {

					siparis.push_back(kiyafet_list[i][0]); siparis.push_back(kiyafet_list[i][1]); siparis.push_back(kiyafet_list[i][2]); siparis.push_back(kiyafet_list[i][3]); siparis.push_back(kiyafet_list[i][4]); siparis.push_back(kiyafet_list[i][5]);

					siparis_list.push_back(siparis);
					siparis.clear();
					break;

				}

			}

		}
		Siparis obj(siparis_list);
		fatura_kayit(obj, "Mert");
		break;

	}


}

void kiyafet_satinal()
{
	int decision = 0;
	int ana_menu = 1;
	int kategor = 0;
	int go;
	string category;
	vector<vector<string>> kiyafet_list;
	kiyafet_list = kiyafet_yaz(kiyafet_list);
	while (true)
	{



		decision = 2;
		if (decision == 1) {
			ana_menu = 0;
			kiyafet_toplu();

		}
		else if (decision == 2) {
			cout << "1)elbise" << endl << "2)tshirt" << endl << "3)pantalon" << endl << "4)gomlek" << endl << "5)etek" << endl << "6)ayakkabi" << endl;
			cout << "kategori seciniz";
			cin >> go;
			if (go == 1) {
				category = "elbise";
				function(go, category, kiyafet_list);
			}
			else if (go == 2) {
				category = "tshirt";
				function(go, category, kiyafet_list);
			}
			else if (go == 3) {
				category = "pantolon";
				function(go, category, kiyafet_list);
			}
			else if (go == 4) {
				category = "gomlek";
				function(go, category, kiyafet_list);
			}
			else if (go == 5) {
				category = "etek";
				function(go, category, kiyafet_list);
			}
			else if (go == 6) {
				category = "ayakkabi";
				function(go, category, kiyafet_list);
			}
		}
		break;

	}



}


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




// class'lar (tam degil, duzensiz ve taslak halinde) ++++++++++
class Zaman
{
private:
	int saat;
	int dakika;
public:
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
	cin.ignore();
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
	int k_flag = 0; //kullanici adi flag
	int p_flag = 0; //password flag
	while (true)
	{
		cout << "lutfen kullanici adinizi giriniz" << endl;
		string kullanici_adi;
		cin.ignore();
		getline(cin, kullanici_adi);
		string password = getpass("lutfen sifrenizi giriniz", true);
		for (int i = 0; i < kullanici_list.size(); i++)
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
	cout << "Lutfen erismek istediginiz menunun numarasini tuslayiniz" << endl << endl;
	cout << "1 - Kiyafet satin al" << endl;
	cout << "2 - Siparis takip" << endl;
	cout << "3 - Sikayet/Oneri yaz" << endl;
	cout << "4 - Sifre degistir" << endl;
	cout << "5 - Geri menu" << endl;
	int musteri;
	cin >> musteri;
	switch (musteri)
	{
	case 1:
		kiyafet_satinal();
		break;
	case 2:
		//kategoriler
		break;
	case 3:
		oneri_yaz();
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
			cout << "Sifreniz degistirildi." << endl;
			Musteri1.sifre_degistir(password);
			break; }
	case 5:
		goto bitir1;
		break;
	}
bitir1:;
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
	cout << "Girmek istediginiz kategoriyi belirtiniz" << endl << endl;
	cout << "1 - Kiyafet ekleme" << endl;
	cout << "2 - Sisteme kurye eklenmesi" << endl;
	cout << "3 - Sikayet ve oneri okunmasi" << endl;
	cout << "4 - Kullaniciya indirim kodu tanimlanmasi" << endl;
	cout << "5 - Yapilan siparislerin faturalarinin goruntulenmesi" << endl;
	cout << "6 - Geri menu" << endl;
	int yonetici;
	cin >> yonetici;

	switch (yonetici)
	{
	case 1:
		kiyafet_toplu();
		break;
	case 2:
		//kategoriler
		break;
	case 3:
		oneri_oku();
		break;
	case 4:
		indirimkodu_yaz();
		break;
	case 5:
		faturalari_goruntule();
		break;
	case 6:
		goto bitir;
		break;
	}
bitir:;
}


int main()
{
	kullanici_txt();
	yonetici_txt();
	kod_liste_olustur();
ilk_menu:
	cout << "Lutfen gitmek istediginiz menuyu tuslayiniz " << endl << endl;;
	cout << "1. Sisteme Giris" << endl;
	cout << "2. Uye Kaydi" << endl;
	cout << "3. Cikis" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
	ikinci_menu:
		cout << "Lutfen gitmek istediginiz menuyu tuslayiniz " << endl << endl;;
		cout << "1. Yonetici Girisi" << endl;
		cout << "2. Musteri Girisi" << endl;
		cout << "3. Onceki Menu" << endl;
		int giris;
		cin >> giris;
		while (true)
		{
			switch (giris)
			{
			case 1:
				yonetici_girisi();
				goto ikinci_menu;
				break;
			case 2:
				musteri_girisi();
				goto ikinci_menu;
				break;
			case 3:
				goto ilk_menu;
			}
		}
		break;
	case 2:
		uye_kaydi();
		break;
	case 3:
		return 0;
	}

}



//#include <iostream>
//#include <stdlib.h>
//#include <cstdlib>
//#include <fstream>
//#include <iomanip>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//#pragma once
//#include <bits/stdc++.h>
//using namespace std;
//
//class zaman {
//private:
//	int saat = 0;
//	int dakika = 0;
//public:
//	Zaman();
//	void setDakika(int b) {
//		dakika = b;
//	}
//	int getDakika() {
//		return dakika;
//	}
//	void setSaat(int a) {
//		saat = a;
//	}
//	int getSaat() {
//		return saat;
//	}
//	void normallestir() {
//		saat = saat + dakika / 60;
//		dakika = (dakika % 60);
//	}
//	void zamaniGoster() {
//		cout << "Saat: " << saat << "." << dakika << endl;
//	}
//};
//
//zaman operator+(zaman a, zaman b) {
//
//	zaman toplam;
//	toplam.setSaat(a.getSaat() + b.getSaat());
//	toplam.setDakika(a.getDakika() + b.getDakika());
//	toplam.normallestir();
//	return toplam;
//
//}
//
//ostream& operator<<(ostream& out, zaman a) {
//
//	out << a.getSaat() << "." << a.getDakika() << endl;
//	return out;
//}
//
//class siparis {
//private:
//	int sipNo;
//	zaman baslangic_zaman;
//	zaman ulasim_zaman;
//public:
//	void setSipNo(int a) {
//		sipNo = a;
//	}
//	int getsipNo() {
//		return sipNo;
//	}
//
//	void setBasLaZaman(zaman a) {
//		baslangic_zaman = a;
//	}
//	zaman getBaslaZaman() {
//		return baslangic_zaman;
//	}
//
//	void setUlasZaman(zaman a) {
//		ulasim_zaman = a;
//	}
//	zaman getUlasZaman() {
//		return ulasim_zaman;
//	}
//};
//
//class kurye {
//private:
//	zaman dagitim_bitisler;
//	int siparis_numaralari;
//	int kurye_no;
//public:
//	void setDagitimBitisler(zaman a) {
//		dagitim_bitisler = a;
//	}
//	void setSiparisNumaralari(int a) {
//		siparis_numaralari = a;
//	}
//	void setKuryeNo(int a = 1) {
//		kurye_no = a;
//	}
//	int getKuryeNo() {
//		return kurye_no;
//	}
//	zaman getDagitim_bitisler() {
//		return dagitim_bitisler;
//	}
//	int getSiparisNumaralari() {
//		return siparis_numaralari;
//	}
//};
//
//int uzaklik;
//int adresBelirleme() {
//	cout << "\n Siparis verilen adresi seciniz: " << endl;
//
//	cout << "1 - Akcaabat" << endl;
//	cout << "2 - Arakli" << endl;
//	cout << "3 - Arsin" << endl;
//	cout << "4 - Besikduzu" << endl;
//	cout << "5 - Ortahisar" << endl;
//	cout << "6 - Vakfikebir" << endl;
//	cout << "7 - Yomra" << endl;
//
//	int adres;
//	cin >> adres;
//
//	switch (adres) {
//		system("CLS");
//	case 1:
//		if (adres == 1) { cout << "\nSiparis Akcaabat'a verildi" << endl; }
//		adres = 50;
//		break;
//	case 2:
//		if (adres == 2) { cout << "\nSiparis Arakli'ya verildi" << endl; }
//		adres = 100;
//		break;
//	case 3:
//		if (adres == 3) { cout << "\nSiparis Arsin'e verildi" << endl; }
//		adres = 70;
//		break;
//	case 4:
//		if (adres == 4) { cout << "\nSiparis Besikduzu'ne verildi" << endl; }
//		adres = 110;
//		break;
//	case 5:
//		if (adres == 5) { cout << "\nSiparis Ortahisar'a verildi" << endl; }
//		adres = 35;
//		break;
//	case 6:
//		if (adres == 6) { cout << "\nSiparis Vakfikebir'e verildi" << endl; }
//		adres = 90;
//		break;
//	case 7:
//		if (adres == 7) { cout << "\nSiparis Yomra'ya verildi" << endl; }
//		adres = 55;
//		break;
//
//	default:
//		cout << "Lutfen gecerli bir adres secin" << endl;
//		adresBelirleme();
//		break;
//	}
//	return uzaklik = adres;
//}
//
//int kuryeSayisi = 3;
//zaman sipSuresi;
//
//zaman sipSuresiHesapla() {
//
//	zaman sipSuresi;
//
//	int n = (kuryeSayisi * 2) + uzaklik;
//	if (n < 60) {
//		sipSuresi.setSaat(0);
//		sipSuresi.setDakika(n);
//	}
//	else {
//		sipSuresi.setDakika(n);
//		sipSuresi.normallestir();
//	}
//	return sipSuresi;
//}
//
//
//void urunler() {
//	cout << "1 - tisort" << endl;
//	cout << "2 - pantolon" << endl;
//	cout << "3 - ayakkabi" << endl;
//
//	int a = 0;
//
//	cin >> a;
//
//	int sayi = a;
//
//	if (sayi > 3 || sayi <= 0) {
//
//		cout << "lutfen tekrar deneyiniz:" << endl;
//		urunler();
//
//	}
//	else {
//
//		int a = sayi;
//
//		int yanit;
//		cout << "Secmek istediginiz baska bir urun var mi? 1- Evet,2 - Hayir " << endl;
//		cin >> yanit;
//
//		if (yanit == 2) {
//
//			cout << "\n Siparis edilen urun numaralari: " << endl;
//
//		}
//		else {
//			urunler();
//		}
//
//		string b;
//
//		if (a == 1) { b = "tisort"; }
//		if (a == 2) { b = "pantolon"; }
//		if (a == 3) { b = "ayakkabi"; }
//		cout << a << " - " << b << endl;
//	}
//}
//
//int r = 1;
//double doubleGirilenSaat = 0.00;
//
//siparis SiparisAl() {
//
//	siparis sip;
//	sip.setSipNo(r);
//
//	cout << "\n Siparis etmek istediginiz urunleri seciniz: " << endl;
//	urunler();
//
//	adresBelirleme();
//
//	cout << "Lutfen siparisi verdiginiz saati giriniz.Orn:12.34" << endl;
//	cin >> doubleGirilenSaat;
//
//	int s = doubleGirilenSaat; // saat
//	int d = 0;
//	d = (doubleGirilenSaat - s) * 100;// dakika
//
//	zaman GirilenSaat;
//	GirilenSaat.setSaat(s);
//	GirilenSaat.setDakika(d);
//
//
//	sip.setBasLaZaman(GirilenSaat);
//	cout << "\nSiparis baslangic saati: " << sip.getBaslaZaman() << endl;
//
//
//	if (sipSuresiHesapla().getSaat() == 0) {
//		cout << "Tahmini teslim suresi: " << sipSuresiHesapla().getDakika() << " dakika" << endl;
//	}
//	else {
//		cout << "Tahmini teslim suresi: " << sipSuresiHesapla().getSaat() << " saat " << sipSuresiHesapla().getDakika() << " dakika " << endl;
//	}
//
//	zaman TeslimSaati;
//	TeslimSaati = sip.getBaslaZaman() + sipSuresiHesapla();
//	sip.setUlasZaman(TeslimSaati);
//	cout << "\nSiparis teslim saati: " << sip.getUlasZaman() << endl;
//
//
//	r++;
//	return sip;
//}
//
//
//void dosyayaYaz(kurye k) {
//
//
//	if (k.getKuryeNo() <= 3) {
//		ofstream yazma("SiparisListesi.txt", ios::app);
//		if (!yazma) {
//			cout << "SiparisListesi.txt dosyasi olusturulamadi" << endl;
//			exit(1);
//		}
//
//		double w = k.getDagitim_bitisler().getSaat();
//		double v = k.getDagitim_bitisler().getDakika();
//		double dTeslimZaman = w + (v / 100);
//
//
//		yazma << "siparis no: " << k.getSiparisNumaralari() << "   ,  " << " kurye no: " << k.getKuryeNo() << "  ,   " << " teslim zamani: " << dTeslimZaman << endl;
//		yazma.close();
//		cout << "SiparisListesi dosyayina kayit yapildi" << endl;
//
//	}
//	else {
//		cout << "Butun kuryeler gorevde!!" << endl;
//
//	}/*
//
//		string siparisNo,kuryeNo,teslimzamani;
//		vector<int>sip;
//		vector<int>kur;
//		vector<double>zam;
//
//		int i;
//		ifstream okuma("SiparisListesi.txt");
//		if(okuma.is_open()){
//
//			string line;
//			getline(okuma,line);
//
//			while(!okuma.eof()){
//			  getline(okuma, siparisNo ,',');
//			  sip.push_back(stof(kuryeNo));
//
//			  getline(okuma, kuryeNo ,',');
//			  kur.push_back(stof(kuryeNo));
//
//			  getline(okuma, teslimzamani ,'\n');
//			  zam.push_back(stof(teslimzamani));
//
//			  i+= 1;
//			}
//			okuma.close();
//			cout<<"Verilen toplam siparis sayisi: "<< i-1<< endl;
//			cout<< "okuma tamamlandi" << endl;
//
//		}
//		else{
//			cout<<"Dosya okunamiyor!"<<endl;
//		}
//
//		}*/
//
//}
//
//
//int b = 1;
//
//void KuryeCagir(siparis a) {
//
//	kurye hasan;
//	hasan.setKuryeNo(b);
//	hasan.setSiparisNumaralari(a.getsipNo());
//
//
//	cout << "kurye no: " << hasan.getKuryeNo();
//	cout << "\nsiparis no: " << a.getsipNo() << endl;
//	cout << "-------------------------" << endl;
//
//	hasan.setDagitimBitisler(a.getUlasZaman());
//
//	dosyayaYaz(hasan);
//
//	cout << "-------------------------" << endl;
//
//	b++;
//
//};
//
//int main() {
//
//	KuryeCagir(SiparisAl()); //1
//	KuryeCagir(SiparisAl()); //2
//	KuryeCagir(SiparisAl()); //3
//	KuryeCagir(SiparisAl()); //4
//	KuryeCagir(SiparisAl()); //5
//	KuryeCagir(SiparisAl()); //6
//	KuryeCagir(SiparisAl()); //7
//
//
//	return 0;
//}
