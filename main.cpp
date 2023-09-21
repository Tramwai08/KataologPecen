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
	
	cout << "Каким способом будем добавлять песню?\n[1]-С клавиатуры\n[2]-По файлу\nВаш выбор ";
	cin >> vib;
	if (vib == 1) {
		string line;
		string name2;
		cout << "\nВведите название песни ";
		cin.ignore();
		getline(cin, song.name);
		cout << "\nВведите автора песни ";
		cin.ignore();
		getline(cin, song.avtor);
		cout << "\nВведите год песни ";
		cin >> song.year;
		cout << "\nВведите текст песни\n";
		cin.ignore();
		while(true){
			getline(cin, line);
			if (line.empty()) break;
			song.txt += line+"\n";
		}
		cout << "Введите название файлика (название+автор) ";
		getline(cin, name2);
		ofstream file("./Katalog/"+name2 + ".txt");
		if (file) {
			file << "Название: " << song.name << endl;
			file << "Автор: " << song.avtor << endl;
			file << "Год: " << song.year << endl;
			file << "Текст песни: \n" << song.txt << endl;
			file << "*************************************************************************************************************" << endl;
			file.close();
			cout << "Песня была успешно добавлена и сохранена в каталог ";
		}
		else cout << "Ошибка файла ";

	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Songs song;
	int vib;
	cout << "Каталог текстовых песен\n[1]-Добавить\n[2]-Удалить\n[3]-Изменить\n[4]-Отобразить\n[5]-Найти\nВаш выбор ";
	cin >> vib;
	switch (vib) {
	case 1: add(song);break;
	/*case 2: dell();break;
	case 3: korekt();break;
	case 4: vivod();break;
	case 5: poisk();break;*/
	default: cout << "Неверный выбор";break;
	}
	return 0;
}