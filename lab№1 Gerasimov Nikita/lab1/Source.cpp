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
    cout << "1.Добавить трубу\
		   \n2.Добавить КС\
           \n3.Просмотр всех объектов трубы\
           \n4.Просмотр всех объектов КС\
           \n5.Загрузить\
           \n0.Выход";
    cout << "\n\nВвод:\t";
}

int proverka() {
    int x; // Какая-то переменная
    do {
        cin.clear();
        cin.ignore(1000, '\ n');
        cin >> x;
    } while (cin.fail());
    return 0;
}
 
int AddPipe(){                                                                   //Создание новой трубы
    setlocale(LC_ALL, "ru");
    Pipe AddTruba;
    int r;
    ofstream EditPipe;
    
    EditPipe.open("Даныне по Трубам.txt", ofstream::app);
    if (!EditPipe) {
        cout << "Ошибка открытия файла";
    }
    else {
        cout << "Сколько новых труб вы хотите внести в данные?" << endl;
        cout << "Введите число:\t";
        cin >> r;
        
        for (int i = 1; i <= r; i++) {
            AddTruba.id;
            cout << "Введите id трубы " << i<<":\t";    
            cin >> AddTruba.id;
            cout << "\nВведите длину трубы: ";
            cin >> AddTruba.lengh;
            cout << "\nВведите диаметр трубы: ";
            cin >> AddTruba.diameter;
                               
            
           
            EditPipe << "ID Трубы: " << AddTruba.id << "\n" << endl;
            EditPipe <<"Длина Трубы: "<< AddTruba.lengh << endl;
            EditPipe << "Диаметр Трубы: " << AddTruba.diameter <<"\n"<< endl;
            EditPipe << "-------------------------------------------------" << endl;
            
        }
        
               
    }
    
    
    
    return 0;
}

                                       
int AddCompressionStation() {                                                      //Создание Новой КС
    setlocale(LC_ALL, "ru");
    CompressionStation AddCS;
    ofstream EditCS;
    string b;
    
    EditCS.open("Данные по КС.txt",ofstream::app);
    if (!EditCS) {
        cout << "Файл не создался.";
    }
    else {
       int t;
       int k;
       cout << "Сколько нужно добавить КС" << endl;
       cout << "Введите число : ";
       cin >> t;
       for (int i = 1; i <= t; i++) {
           cout << "Введите новое ID КС: " ;
           cin >> AddCS.id;
           cout << "Введите новое название КС:  ";
           cin >> AddCS.name;
           cout << "Введите Кол-во Цехов: ";
           cin >> AddCS.NumberOfWorkShopsInOperation;
           cout << "Введите Кол-во цехов в работе" << endl;
           cin >> AddCS.NumberOfWorkShops;
           if (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops) {
               cout << "Рабочех цехов больше, чем общее кол-во цехов, введите другое значение" << endl;
               while (AddCS.NumberOfWorkShopsInOperation < AddCS.NumberOfWorkShops){
                   cout << "Введите другое кол-во цехов в работе: ";
               cin >> AddCS.NumberOfWorkShops;
              
               }
           }
         
               
          
           
        }
       EditCS << "ID КС : " << AddCS.id << endl;
       EditCS << "Название КС: " << AddCS.name << endl;;
       EditCS << "Кол-во Цехов : " << AddCS.NumberOfWorkShopsInOperation << endl;
       EditCS << "Кол-во Рабочих Цехов : " << AddCS.NumberOfWorkShops << endl;
       EditCS <<"Эффективность: " <<  ((AddCS.id + AddCS.NumberOfWorkShopsInOperation + AddCS.NumberOfWorkShops) / 3)<<"%"<<endl;
       EditCS << "-------------------------------------------------" << endl;
       EditCS << "\n" << endl;
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
int loading() {
    ifstream Loading;
    string ld;
    int otvet;
    
    while (bool ok = true) {
        cout << "Введите точный путь к .txt файлу: ";
        cin >> ld;
        Loading.open(ld);
        

        if (!Loading.is_open()) {
            cout << "Файл не открылся" << endl;
            ok = false;

        }
        else {
            cout << "Файл успешно загружен\n" << endl;
            cout << "Открыть файл?" << endl;
            cout << "1. Открыть\
                   \n2. Выход" << endl;
            cout << "Ввод";
            cin >> otvet;
            if (otvet == 1) {
                char ch3;
                while (Loading.get(ch3)) {
                    cout << ch3;
                }
                cout << "\n\n" << endl;
                string h;
                cout << "Выйти? " ;
                cout << "нажмите на любую кнопку: " << endl;
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

           
            cout << "Выберите Из придложенного в меню\n" << endl;
            
            
            run = true;

            break;
        }
     

    
    }

    return 0;
}