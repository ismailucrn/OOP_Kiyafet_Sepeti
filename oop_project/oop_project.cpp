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
		case 1:
			int y;
			cout << "Yonetici Girisi" << endl;
			cout << "Musteri Girisi" << endl;
			cin >> y;
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}
