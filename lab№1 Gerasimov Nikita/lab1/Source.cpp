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
           \n3.Просмотр всех объектов\
           \n4.Редактировать трубу\
           \n5.Редактировать КС\
           \n6.Сохранить\
           \n7.Загрузить\
           \n0.Выход";
    cout << "\n\nВвод:\t";
}

int AddPipe(){
    setlocale(LC_ALL, "ru");
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
            string a;
            cout << "Введите id трубы " << i<<":\t";
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
    EditCS.open("Данные по КС.txt");
    if (!EditCS) {
        cout << "Файл не создался.";
    }
    else {
       for (int i = 1; i < 2; i++) {
           cout << "Ввод" << endl;
           cin >> b;
           EditCS << b << endl;
        }
    }
    EditCS.close();
    return 0;
}

void ViewAllObject() {
    ifstream fin;
    string path = ("Даныне по Трубам.txt");
    fin.open(path);
    if (!fin.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
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
            cout << "Выберите Из придложенного в меню\n" << endl;
            
            
            run = true;
            Menu();

            break;
        }
     

    
    }

    return 0;
}