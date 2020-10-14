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
    cout << "Введите изменения: ";
}

void Menu(){
    cout << "1.Добавить трубу\
		   \n2.Добавить КС\
           \n3.Просмотр всех объектов трубы\
           \n4.Просмотр всех объектов КС\
           \n5.Редактировать трубу\
           \n6.Редактировать КС\
           \n7.Сохранить\
           \n8.Загрузить\
           \n0.Выход";
    cout << "\n\nВвод:\t";
}
 
int AddPipe(){                                                     //Создание новой трубыч  
    setlocale(LC_ALL, "ru");
    Pipe AddTruba;
    int r;
    ofstream EditPipe;
    EditPipe.open("Даныне по Трубам.txt");
    if (!EditPipe) {
        cout << "Ошибка открытия файла";
    }
    else {
        cout << "Сколько новых труб вы хотите внести в данные?" << endl;
        cout << "Введите число:\t" << endl;
        cin >> r;
        for (int i = 1; i <= r; i++) {
            AddTruba.id;
            cout << "Введите id трубы " << i<<":\t";
            cin >> AddTruba.id;
            cout << "\nВведите длину трубы" << endl;
            cin >> AddTruba.lengh;
            cout << "\nВвелмие диаметр трубы" << endl;
            cin >> AddTruba.diameter;

            
            EditPipe << "ID Трубы: " << AddTruba.id << "\n" << endl;
            EditPipe <<"Длина Трубы: "<< AddTruba.lengh << endl;
            EditPipe << "Диаметр Трубы: " << AddTruba.diameter <<"\n"<< endl;
            
        }
        cout << "\n" << endl; 
               
    }
    
    
    
    return 0;
}

                                       
int AddCompressionStation() {                                      //Создание Новой КС
    setlocale(LC_ALL, "ru");
    CompressionStation AddCS;
    ofstream EditCS;
    string b;
    
    EditCS.open("Данные по КС.txt");
    if (!EditCS) {
        cout << "Файл не создался.";
    }
    else {
       int t;
       int u;
       cout << "Сколько нужно добавить КС" << endl;
       cout << "Введите число : ";
       cin >> t;
       for (int i = 1; i < t; i++) {
           cout << "Введите новое ID КС: " ;
           cin >> AddCS.id;
           cout << "Ввдеите новое название КС:  ";
           cin >> AddCS.name;
           cout << "Введите Кол-во Цехов" << endl;
           cin >> AddCS.NumberOfWorkShopsInOperation;
           cout << "Введите Кол-во цехов в работе" << endl;
           cin >> AddCS.NumberOfWorkShops;
           if (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops) {
               cout << "Рабочех цехов больше, чем общее кол-во цехов, введите другое значение" << endl;
               while (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops){
               cin >> AddCS.NumberOfWorkShops;
              
               }
           }
           else {
               u = (AddCS.id + AddCS.NumberOfWorkShopsInOperation + AddCS.NumberOfWorkShops) / 3;
               EditCS << "ID КС : " << AddCS.Eficiency << endl;
               EditCS << "Название КС" << AddCS.name << endl;;
               EditCS << "Кол-во Цехов : " << AddCS.NumberOfWorkShopsInOperation << endl;
               EditCS << "Кол-во Рабочих Цехов : " << AddCS.NumberOfWorkShops << endl;
               EditCS << u << endl;
               EditCS << "\n" << endl;
           }
        }
    }
    
    return 0;
}

void ViewAllObjectPipe() {                         //Просмотреть все объекты из файла "Данные по трубам".
    ifstream fin;
    string path = ("Даныне по Трубам.txt");
    fin.open(path);
    if (!fin.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт\n" << endl;
        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }
    }
}
void ViewAllObjectCS() {                            //Просмотр всех объектов из файла "Данные по КС".
    ifstream CSView;
    string documentsCS="Данные по КС.txt";
    CSView.open(documentsCS);
    if (!CSView.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт!\n" << endl;
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
    cout << "1.Введите новое ID трубы" << endl;
    cout << "2.Изменить длину трубу" << endl;
    cout << "3.Изменить диаметр трубы" << endl;
    cout << "4.Признак" << endl;
    cout << "Ввод:\t";
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
            cout << "Выберите Из придложенного в меню\n" << endl;
            
            
            run = true;

            break;
        }
     

    
    }

    return 0;
}