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

int getValue(int left, int right) {
	int i;
	cin >> i;
	while (cin.fail() || i < left || i > right) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "��������� ����" << endl;
		cin >> i;
	}
	cin.ignore(10000, '\n');
	return i;
}

double getValue(double left, double right) {
	double i;
	cin >> i;
	while (cin.fail() || i < left || i > right) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "��������� ����" << endl;
		cin >> i;
	}
	cin.ignore(10000, '\n');
	return i;
}


Pipe InputPipe()					
{
	Pipe p;
	cout << "Input lenght: ";
	cin >> p.lenght;
	cout << "Input diamter: ";
	cin >> p.diameter;
	cout << "Input ID: ";
	cin >> p.ID;
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
		cout << "����� ��������"<<endl;
	}
	else {
		cout << "����� �� ��������" << endl;
	}
}*/

ostream& operator<<(ostream& out, const Pipe& p) 
{
	out << "Lenght: " << p.lenght << endl;;
	out << "Diametr: " << p.diameter << endl;
	out << "ID: " << p.ID << endl;
	if (p.repair == true) {
		out << "����� ��������" << endl;
	}
	else {
		out << "����� �� ��������" << endl;
	}
	out << endl << endl << endl;
	return out;
}

Pipe EditPipe(Pipe& p)
{						
	int n;
	cout << "\n";
	cout << "1.����� ��������\n2.����� �� ��������" << endl;
	cout << "����: ";
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
	cout << "������� ID: ";
	cin >> cs.id;
	cout << "������� �������� ������������� �������: " ;
	cin >> cs.name;
	cout << "������� ���-�� ���������� �������: ";
	cin >> cs.NumberOfWorkShops;
	cout << "������� ����� ���-�� �������: ";
	cin >> cs.NumberOfWorkShopsInOperation;

	if (cs.NumberOfWorkShopsInOperation < cs.NumberOfWorkShops) {
		cout << "������� ����� ������, ��� ����� ���-�� �����, ������� ������ ��������\n" << endl;
		while (cs.NumberOfWorkShopsInOperation < cs.NumberOfWorkShops) {
			cout << "������� ������ ���-�� ����� � ������: ";
			cin >> cs.NumberOfWorkShops;

		}
	}
	cs.launch = true;
	return cs;
}

void ShowCS(const CompressionStation& cs) {
	cout << "ID ��: " << cs.id << cs.id << endl;
	cout << "�������� ��: " << cs.name << cs.name << endl;
	cout << "���-�� ���������� ������� " << cs.NumberOfWorkShops << endl;
	cout << "����� ���-�� ������� " << cs.NumberOfWorkShopsInOperation << endl;
	
	cout << "������: ";
	if (cs.launch == true) {
		cout << "�� ��������" << endl;
	}
	else {
		cout << "�� �� �������" << endl;
	}
}

CompressionStation EditCS(CompressionStation& cs) 
{
	int n;
	cout << "\n";
	cout << "1.�� ��������\n2.�� �� ��������" << endl;
	cout << "����:";
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
void Save(Pipe p, CompressionStation cs)
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
		fout << cs.id << endl;
		fout << cs.NumberOfWorkShops << endl;
		fout << cs.NumberOfWorkShopsInOperation;
		fout.close();
	}
	else {
		cout << "���� �� ������!" << endl;
	}
}

void save(Pipe p, CompressionStation cs)
{
	ofstream fout;
	fout.open("results.txt", ios::out);
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
			cout << "1.������������� �����\
					\n2.����������� ��� ������� �����\
					\n3.������������� �����\
					\n4.������� ��\
					\n5.�������� ���� �������� ��\
					\n6.������������� ��\
	\n7.��������� ����\
	\n8.������� ����" << endl;
			cout << "����: ";
			cin >> n;
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
			case (0): {
				run = false;
			}
			}
			default:
				break;
			}
		}
	

	return 0;
	}