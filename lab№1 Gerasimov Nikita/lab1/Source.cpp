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
    cout << "1.Добавить трубу\
		   \n2.Добавить КС\
           \n3.Просмотр всех объектов\
           \n4.Редактировать трубу\
           \n5.Редактировать КС\
           \n6.Сохранить\
           \n7.Загрузить\
           \n0.Выход";
    cout << "\n\nВвод: ";
}

void AddPipe(){
  
  /*  cout << "Введите длинну трубы: "<<Truba.lenght << endl;
    cout << "Введите диаметр трубы: " << Truba.diameter << endl;
    cout << "Введите ID" << Truba.id << endl;
    cout << "Введите Дееспособность трубы" << Truba.WorkingOrNotWorking << endl;
    return 0;*/
}



void AddCompressionStation() {

   
}

//void EditPipe() {
   

int EditCompressionStation() {
    setlocale(LC_ALL, "rus");
    CompressionStation station;
    int n;

    cout << "1.Поменять ID "<<endl;
    cout << "2.Поменять Назавание КС" << endl;
    cin >> n;
    
    switch (n)
    {
    case 1:
        cout << "Введите новое ID: " << endl;
        cin >> station.NumberOfWorkShops;
        cout << station.NumberOfWorkShops;
        break;
    case 2:
        cout << "Введите новое название КС" << endl;
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