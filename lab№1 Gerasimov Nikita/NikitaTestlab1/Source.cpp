#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Pipe {
	float lenght;
	int diameter;
	int ID;
	bool repair;
};

struct CompressionStation {
	int id;
	string name;
	int NumberOfWorkShops;
	int NumberOfWorkShopsInOperation;
	bool launch;
};

void wInput(string inf, int& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите " << inf;
		cin >> n;
	} while (cin.fail());
}

void wInput(string inf, float& n) {
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите " << inf;
		cin >> n;
	} while (cin.fail());
}

Pipe InputPipe()					
{
	Pipe p;
	wInput("длину ", p.lenght);
	wInput("диаметр ", p.diameter);
	wInput("ID ", p.ID);
	p.repair = true; \
		cout << "\n\n" << endl;
	return p;
}

/*void ShowPipe(const Pipe& p)					
{
	cout << "Length: " << p.lenght
		 <<"\tDiameter: "<<p.diameter
		 << "\tID: " << p.ID << endl;
	if (p.repair == true) {
		cout << "труба работает"<<endl;
	}
	else {
		cout << "труба не работает" << endl;
	}
}*/

ostream& operator<<(ostream& out, const Pipe& p) 
{
	out << "Lenght: " << p.lenght << endl;;
	out << "Diametr: " << p.diameter << endl;
	out << "ID: " << p.ID << endl;
	if (p.repair == true) {
		out << "труба работает" << endl;
	}
	else {
		out << "труба не работает" << endl;
	}
	out << endl << endl << endl;
	return out;
}

Pipe EditPipe(Pipe& p)
{						
	int n;
	cout << "\n";
	cout << "1.Труба работает\n2.Труба не работает" << endl;
	cout << "Ввод: ";
		cin >> n;
		if (n == 1) {
			p.repair = true;
		}
		else if (n == 2) {
			p.repair = false;
		}
		cout << "\n\n" << endl;
	return p;
}

CompressionStation InputCS() 
{
	CompressionStation cs;
	wInput("ID ", cs.id);
	cout << "Введите Название Компрессорной Станции: ";
	cin >> cs.name;
	wInput("Кол-во работающих станций: ", cs.NumberOfWorkShops);
	wInput("общее кол-во Станций: ", cs.NumberOfWorkShopsInOperation);
	
	if (cs.NumberOfWorkShopsInOperation < cs.NumberOfWorkShops) {
		cout << "Рабочех цехов больше, чем общее кол-во цехов, введите другое значение\n" << endl;
		while (cs.NumberOfWorkShopsInOperation < cs.NumberOfWorkShops) {
			cout << "Введите другое кол-во цехов в работе: ";
			cin >> cs.NumberOfWorkShops;

		}
	}
	cs.launch = true;
	return cs;
}

void ShowCS(const CompressionStation& cs) {
	cout << "ID КС: " << cs.id  << endl;
	cout << "Название КС: " << cs.name << endl;
	cout << "Кол-во работающих станций " << cs.NumberOfWorkShops << endl;
	cout << "Общее кол-во станций " << cs.NumberOfWorkShopsInOperation << endl;
	
	cout << "Статус: ";
	if (cs.launch == true) {
		cout << "КС запущена" << endl;
	}
	else {
		cout << "КС не активна" << endl;
	}
	cout << "\n\n" << endl;
}

CompressionStation EditCS(CompressionStation& cs) 
{
	int n;
	cout << "\n";
	cout << "1.КС запущена\n2.КС не запущена" << endl;
	cout << "Ввод: ";
	cin >> n;
	if (n == 1) {
		cs.launch = true;
	}
	else if (n == 2) {
		cs.launch == false;
	}

	return cs;
}
//----------------------------------------------------------------------------------------------

void save(Pipe p, CompressionStation cs)
{
	ofstream fout;
	fout.open("Pipe_CS.txt", ios::out);
	if (fout.is_open()) {
		fout << p.ID << endl;
		fout << p.lenght << endl;
		fout << p.diameter << endl;
		fout << p.repair << endl;

		fout << cs.id << endl;
		fout << cs.name << endl;
		fout << cs.NumberOfWorkShops << endl;
		fout << cs.NumberOfWorkShops << endl;
		fout << cs.NumberOfWorkShopsInOperation << endl;
		fout.close();
	}
}

void Load(Pipe& p, CompressionStation& cs)
{
	ifstream fin;
	fin.open("Pipe_CS.txt", ios::in);
	if (fin.is_open()) {
		fin >> p.ID;
		fin >> p.lenght;
		fin >> p.diameter;
		fin >> p.repair;
		fin >> cs.id;
		fin >> cs.name;
		fin >> cs.NumberOfWorkShops;
		fin >> cs.NumberOfWorkShopsInOperation;
		fin.close();
	}
	
}

	int main() {
		setlocale(LC_ALL, "ru");
		int n;
		bool run=true;
		Pipe pipe = Pipe();
		CompressionStation cs = CompressionStation();
		while (run) {
			cout << "1.Редактировать трубу\
					\n2.Просмотреть все объекты трубы\
					\n3.Редактировать трубу\
					\n4.Создать КС\
					\n5.Просмотр всех объектов КС\
					\n6.Редактировать КС\
				    \n7.Сохранить файл\
					\n8.Загрузить файл\
					\n0.Exit" << endl;

			cout << "Ввод: ";
			cin >> n;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Выберите действие:" << endl;
				cin >> n;
			}
			switch (n)
			{
			case(1): 
			{
				pipe = InputPipe();
				break;
			}
			case(2):
			{
				cout << pipe;
			
				break;
			}
			case(3):
			{
				EditPipe(pipe);
				break;
			}
			case(4): 
			{
				cs = InputCS();
				break;
			}
			case(5): 
			{
				ShowCS(cs);
				break;
			}
			case(6): 
			{
				EditCS(cs);
				break;
			}
			case(7):
			{
				Load(pipe, cs);
				break;
			}
			case (8):
			{
				save(pipe, cs);
				run = true;
				break;
			}
			case (0): 
			{
				run = false;
			}
			
			default:
				break;
			}
		}
	

	return 0;
	}