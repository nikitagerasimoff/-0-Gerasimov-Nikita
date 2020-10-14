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
           \n3.�������� ���� �������� �����\
           \n4.�������� ���� �������� ��\
           \n5.������������� �����\
           \n6.������������� ��\
           \n7.���������\
           \n8.���������\
           \n0.�����";
    cout << "\n\n����:\t";
}
 
int AddPipe(){                                                     //�������� ����� ������  
    setlocale(LC_ALL, "ru");
    Pipe AddTruba;
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
            AddTruba.id;
            cout << "������� id ����� " << i<<":\t";
            cin >> AddTruba.id;
            cout << "\n������� ����� �����" << endl;
            cin >> AddTruba.lengh;
            cout << "\n������� ������� �����" << endl;
            cin >> AddTruba.diameter;

            
            EditPipe << "ID �����: " << AddTruba.id << "\n" << endl;
            EditPipe <<"����� �����: "<< AddTruba.lengh << endl;
            EditPipe << "������� �����: " << AddTruba.diameter <<"\n"<< endl;
            
        }
        cout << "\n" << endl; 
               
    }
    
    
    
    return 0;
}

                                       
int AddCompressionStation() {                                      //�������� ����� ��
    setlocale(LC_ALL, "ru");
    CompressionStation AddCS;
    ofstream EditCS;
    string b;
    
    EditCS.open("������ �� ��.txt");
    if (!EditCS) {
        cout << "���� �� ��������.";
    }
    else {
       int t;
       int u;
       cout << "������� ����� �������� ��" << endl;
       cout << "������� ����� : ";
       cin >> t;
       for (int i = 1; i < t; i++) {
           cout << "������� ����� ID ��: " ;
           cin >> AddCS.id;
           cout << "������� ����� �������� ��:  ";
           cin >> AddCS.name;
           cout << "������� ���-�� �����" << endl;
           cin >> AddCS.NumberOfWorkShopsInOperation;
           cout << "������� ���-�� ����� � ������" << endl;
           cin >> AddCS.NumberOfWorkShops;
           if (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops) {
               cout << "������� ����� ������, ��� ����� ���-�� �����, ������� ������ ��������" << endl;
               while (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops){
               cin >> AddCS.NumberOfWorkShops;
              
               }
           }
           else {
               u = (AddCS.id + AddCS.NumberOfWorkShopsInOperation + AddCS.NumberOfWorkShops) / 3;
               EditCS << "ID �� : " << AddCS.Eficiency << endl;
               EditCS << "�������� ��" << AddCS.name << endl;;
               EditCS << "���-�� ����� : " << AddCS.NumberOfWorkShopsInOperation << endl;
               EditCS << "���-�� ������� ����� : " << AddCS.NumberOfWorkShops << endl;
               EditCS << u << endl;
               EditCS << "\n" << endl;
           }
        }
    }
    
    return 0;
}

void ViewAllObjectPipe() {                         //����������� ��� ������� �� ����� "������ �� ������".
    ifstream fin;
    string path = ("������ �� ������.txt");
    fin.open(path);
    if (!fin.is_open()){
        cout << "������ �������� �����" << endl;
    }
    else {
        cout << "���� ������\n" << endl;
        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }
    }
}
void ViewAllObjectCS() {                            //�������� ���� �������� �� ����� "������ �� ��".
    ifstream CSView;
    string documentsCS="������ �� ��.txt";
    CSView.open(documentsCS);
    if (!CSView.is_open()) {
        cout << "������ �������� �����" << endl;
    }
    else {
        cout << "���� ������!\n" << endl;
        char ch1;
        while (CSView.get(ch1)) {
            cout << ch1;
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

  
    
    while (run) {
        Menu();
        cin >> n;
        
        
        switch (n)
        {
        case 1:
            AddPipe();
            run = true;
            
            break;
        case 2:
            AddCompressionStation();
            break;
        case 3:
            ViewAllObjectPipe();
            run = true;
            break;
        case 4:
            ViewAllObjectCS();
            run = true;
            break;
        case 5:
            ChangePipe();
            run = true;
            break;
        case 6:

            EditCompressionStation();
            run = true;
            cout << " " << endl;
           
            break;

        case 7:

            break;
        case 8:
               
            break;
        case 0:
            run = false;
            
            break;

        default:
            cout << "�������� �� ������������� � ����\n" << endl;
            
            
            run = true;

            break;
        }
     

    
    }

    return 0;
}