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




void Menu(){
    cout << "1.�������� �����\
		   \n2.�������� ��\
           \n3.�������� ���� �������� �����\
           \n4.�������� ���� �������� ��\
           \n5.���������\
           \n0.�����";
    cout << "\n\n����:\t";
}

int proverka() {
    int x; // �����-�� ����������
    do {
        cin.clear();
        cin.ignore(1000, '\ n');
        cin >> x;
    } while (cin.fail());
    return 0;
}
 
int AddPipe(){                                                                   //�������� ����� �����
    setlocale(LC_ALL, "ru");
    Pipe AddTruba;
    int r;
    ofstream EditPipe;
    
    EditPipe.open("������ �� ������.txt", ofstream::app);
    if (!EditPipe) {
        cout << "������ �������� �����";
    }
    else {
        cout << "������� ����� ���� �� ������ ������ � ������?" << endl;
        cout << "������� �����:\t";
        cin >> r;
        
        for (int i = 1; i <= r; i++) {
            AddTruba.id;
            cout << "������� id ����� " << i<<":\t";    
            cin >> AddTruba.id;
            cout << "\n������� ����� �����: ";
            cin >> AddTruba.lengh;
            cout << "\n������� ������� �����: ";
            cin >> AddTruba.diameter;
                               
            
           
            EditPipe << "ID �����: " << AddTruba.id << "\n" << endl;
            EditPipe <<"����� �����: "<< AddTruba.lengh << endl;
            EditPipe << "������� �����: " << AddTruba.diameter <<"\n"<< endl;
            EditPipe << "-------------------------------------------------" << endl;
            
        }
        
               
    }
    
    
    
    return 0;
}

                                       
int AddCompressionStation() {                                                      //�������� ����� ��
    setlocale(LC_ALL, "ru");
    CompressionStation AddCS;
    ofstream EditCS;
    string b;
    
    EditCS.open("������ �� ��.txt",ofstream::app);
    if (!EditCS) {
        cout << "���� �� ��������.";
    }
    else {
       int t;
       int k;
       cout << "������� ����� �������� ��" << endl;
       cout << "������� ����� : ";
       cin >> t;
       for (int i = 1; i <= t; i++) {
           cout << "������� ����� ID ��: " ;
           cin >> AddCS.id;
           cout << "������� ����� �������� ��:  ";
           cin >> AddCS.name;
           cout << "������� ���-�� �����: ";
           cin >> AddCS.NumberOfWorkShopsInOperation;
           cout << "������� ���-�� ����� � ������" << endl;
           cin >> AddCS.NumberOfWorkShops;
           if (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops) {
               cout << "������� ����� ������, ��� ����� ���-�� �����, ������� ������ ��������" << endl;
               while (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops){
                   cout << "������� ������ ���-�� ����� � ������: ";
               cin >> AddCS.NumberOfWorkShops;
              
               }
           }
         
               
          
           
        }
       EditCS << "ID �� : " << AddCS.id << endl;
       EditCS << "�������� ��: " << AddCS.name << endl;;
       EditCS << "���-�� ����� : " << AddCS.NumberOfWorkShopsInOperation << endl;
       EditCS << "���-�� ������� ����� : " << AddCS.NumberOfWorkShops << endl;
       EditCS <<"�������������: " <<  ((AddCS.id + AddCS.NumberOfWorkShopsInOperation + AddCS.NumberOfWorkShops) / 3)<<"%"<<endl;
       EditCS << "-------------------------------------------------" << endl;
       EditCS << "\n" << endl;
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
int loading() {
    ifstream Loading;
    string ld;
    int otvet;
    
    while (bool ok = true) {
        cout << "������� ������ ���� � .txt �����: ";
        cin >> ld;
        Loading.open(ld);
        

        if (!Loading.is_open()) {
            cout << "���� �� ��������" << endl;
            ok = false;

        }
        else {
            cout << "���� ������� ��������\n" << endl;
            cout << "������� ����?" << endl;
            cout << "1. �������\
                   \n2. �����" << endl;
            cout << "����";
            cin >> otvet;
            if (otvet == 1) {
                char ch3;
                while (Loading.get(ch3)) {
                    cout << ch3;
                }
                cout << "\n\n" << endl;
                string h;
                cout << "�����? " ;
                cout << "������� �� ����� ������: " << endl;
                cin >> h;
               
                return 0;
                
                
            }
            else {
                return 0;
            }
            

        }
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
            loading();
            run = true;
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