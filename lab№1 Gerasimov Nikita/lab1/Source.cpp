#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool run=true;

struct CompressionStation {
    int id;
    string name;
    float NumberOfWorkShops;
    float NumberOfWorkShopsInOperation;
    float Eficiency;
};

struct Pipe {

    int id;
    double lengh;
    double diameter;
    float WorkingOrNotWorking;

};

void change() {
    cout << "������� ���������: ";
}

void Menu(){
    cout << "1.�������� �����\
		   \n2.�������� ��\
           \n3.�������� ���� ��������\
           \n4.������������� �����\
           \n5.������������� ��\
           \n6.���������\
           \n7.���������\
           \n0.�����";
    cout << "\n\n����:\t";
}

int AddPipe(){
    setlocale(LC_ALL, "ru");
    int r;
    ofstream EditPipe;
    EditPipe.open("������ �� ������.txt");
    if (!EditPipe) {
        cout << "������ �������� �����";
    }
    else {
        cout << "������� ����� ���� �� ������ ������ � ������?" << endl;
        cout << "������� �����:\t" << endl;
        cin >> r;
        for (int i = 1; i <= r; i++) {
            string a;
            cout << "������� id ����� " << i<<":\t";
            cin >> a;
            EditPipe << a << endl;
            
        }
        cout << "\n" << endl;
               
    }
    
    
    
    return 0;
}


int AddCompressionStation() {
    setlocale(LC_ALL, "ru");
    ofstream EditCS;
    string b;
    EditCS.open("������ �� ��.txt");
    if (!EditCS) {
        cout << "���� �� ��������.";
    }
    else {
       for (int i = 1; i < 2; i++) {
           cout << "����" << endl;
           cin >> b;
           EditCS << b << endl;
        }
    }
    EditCS.close();
    return 0;
}

void ViewAllObject() {
    ifstream fin;
    string path = ("������ �� ������.txt");
    fin.open(path);
    if (!fin.is_open()){
        cout << "������ �������� �����" << endl;
    }
    else {
        cout << "���� ������" << endl;
        char ch;
        while (fin.get(ch)) {
            cout << ch << "\n" << endl;
        }
    }
}


int ChangePipe() {
    setlocale(LC_ALL, "ru");
    int n;
    Pipe truba;
    cout << "1.������� ����� ID �����" << endl;
    cout << "2.�������� ����� �����" << endl;
    cout << "3.�������� ������� �����" << endl;
    cout << "4.�������" << endl;
    cout << "����:\t";
    cin >> n;
    switch (n)
    {
    case 1:
        change();
        cin >> truba.id;
        break;
    case 2:
        change();
        cin >> truba.lengh;
        break;
    case 3:
        change();
        cin >> truba.diameter;
        break;
    case 4:
        change();
        cin >> truba.WorkingOrNotWorking;
        break;
    default:
        break;
    }

    return 0;
}

int EditCompressionStation() {
    setlocale(LC_ALL, "ru");
    CompressionStation station;
    int n;

    cout << "1.�������� ID "<<endl;
    cout << "2.�������� ��������� ��" << endl;
    cin >> n;
    
    switch (n)
    {
    case 1:
        cout << "������� ����� ID: " << endl;
        cin >> station.NumberOfWorkShops;
        cout << station.NumberOfWorkShops;
        break;
    case 2:
        
        cout << "������� ����� �������� ��" << endl;
        cin >> station.name;
        cout << station.name << endl;
        break;
    default:
        break;
    }
    return 0;
}


int main() {
    setlocale(LC_ALL, "ru");

    int n;
    string a;

     Menu();
    
    while (run) {
        cin >> n;
        
        
        switch (n)
        {
        case 1:
            AddPipe();
            run = true;
            Menu();
            break;
        case 2:
            AddCompressionStation();
            break;
        case 3:
            ViewAllObject();
            run = true;
            Menu();
            break;
        case 4:
            ChangePipe();
            run = true;
            Menu();
            break;
        case 5:

            EditCompressionStation();
            run = true;
            cout << " " << endl;
            Menu();
            

            break;

        case 6:

            break;
        case 7:
               
            break;
        case 0:
            run = false;
            
            break;

        default:
            cout << "�������� �� ������������� � ����\n" << endl;
            
            
            run = true;
            Menu();

            break;
        }
     

    
    }

    return 0;
}