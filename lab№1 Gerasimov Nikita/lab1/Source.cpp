#include <iostream>
#include <string>
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
           \n3.�������� ���� ��������\
           \n4.������������� �����\
           \n5.������������� ��\
           \n6.���������\
           \n7.���������\
           \n0.�����";
    cout << "\n\n����: ";
}

void AddPipe(){
  
  /*  cout << "������� ������ �����: "<<Truba.lenght << endl;
    cout << "������� ������� �����: " << Truba.diameter << endl;
    cout << "������� ID" << Truba.id << endl;
    cout << "������� �������������� �����" << Truba.WorkingOrNotWorking << endl;
    return 0;*/
}



void AddCompressionStation() {

   
}

//void EditPipe() {
   

int EditCompressionStation() {
    setlocale(LC_ALL, "rus");
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
        break;
    default:
        break;
    }
    return 0;
}


int main() {
    setlocale(LC_ALL, "rus");

    int n;
    string a;

   
    
    Menu();
    
    while (run) {
        cin >> n;
        
        
        switch (n)
        {
        case 1:
              
            break;
        case 2:
         
            break;
        case 3:
            

            break;
        case 4:
           
            break;
        case 5:

            EditCompressionStation();
            break;

        case 6:

            break;
        case 7:
               
            break;
        case 0:
            
            
            break;

        default:
            run = true;
            Menu();

            break;
        }
     

    
    }

    return 0;
}