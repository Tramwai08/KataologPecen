#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Songs {
	string name;
	string avtor;
	int year;
	string txt;
};
void add(Songs song) {
	int vib;
	
	cout << "����� �������� ����� ��������� �����?\n[1]-� ����������\n[2]-�� �����\n��� ����� ";
	cin >> vib;
	if (vib == 1) {
		string line;
		string name2;
		cout << "\n������� �������� ����� ";
		cin.ignore();
		getline(cin, song.name);
		cout << "\n������� ������ ����� ";
		cin.ignore();
		getline(cin, song.avtor);
		cout << "\n������� ��� ����� ";
		cin >> song.year;
		cout << "\n������� ����� �����\n";
		cin.ignore();
		while(true){
			getline(cin, line);
			if (line.empty()) break;
			song.txt += line+"\n";
		}
		cout << "������� �������� ������� (��������+�����) ";
		getline(cin, name2);
		ofstream file("./Katalog/"+name2 + ".txt");
		if (file) {
			file << "��������: " << song.name << endl;
			file << "�����: " << song.avtor << endl;
			file << "���: " << song.year << endl;
			file << "����� �����: \n" << song.txt << endl;
			file << "*************************************************************************************************************" << endl;
			file.close();
			cout << "����� ���� ������� ��������� � ��������� � ������� ";
		}
		else cout << "������ ����� ";

	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Songs song;
	int vib;
	cout << "������� ��������� �����\n[1]-��������\n[2]-�������\n[3]-��������\n[4]-����������\n[5]-�����\n��� ����� ";
	cin >> vib;
	switch (vib) {
	case 1: add(song);break;
	/*case 2: dell();break;
	case 3: korekt();break;
	case 4: vivod();break;
	case 5: poisk();break;*/
	default: cout << "�������� �����";break;
	}
	return 0;
}