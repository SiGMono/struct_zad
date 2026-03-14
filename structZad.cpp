/*
    Szymon Zeller Informatyka1
    PRogram do czytania i wpisywania structów do pliku .txt
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    struct student
    {
        int id;
        string name,surname;
    };

    //Wypisywanie danych z pliku i zapamiętywanie ostatniego id
    int lastStudentId = 0;
    ifstream studentData;
    studentData.open("student_data.txt");
    string x = "";
    while(studentData >> x){
        lastStudentId = stoi(x);
        cout<<"ID: "<<x<<" - ";
        studentData >> x; cout<<"Imie i Nazwisko: "<<x<<" ";
        studentData >> x; cout<<x<<endl;
    }
    studentData.close();

    //Pętla z wyborem zapisu i czytania z pliku
    string checkIntent = "K";
    while(true){
        cout<<"Chcesz wpisac uczniow? (T/N) ";
        cin>>checkIntent;
        if(checkIntent == "T" || checkIntent == "N"){
            break;
        }
        cout<<" ";
    }

    /*
    if(checkIntent == "C"){
        ifstream studentData;
        studentData.open("student_data.txt");
        string x = "";
        while(studentData >> x){
            lastStudentId = stoi(x);        //TODO refactor for this value
            cout<<"ID: "<<x<<endl;
            studentData >> x; cout<<"Imie: "<<x<<endl;
            studentData >> x; cout<<"Nazwisko: "<<x<<endl;
        }
        studentData.close();
    }*/
    
    //Wypełnianie danych do wpisania poprzez vector
    if(checkIntent == "T"){
        cout<<"Ile studentow do wpisania?"<<endl;
        int studentsNumber;
        cin>>studentsNumber;
        for(int i = 1; i <= studentsNumber; i++){
            while(true){
                student newStudent;
                newStudent.id = i+lastStudentId;
                cout<<"Imie: "; cin>>newStudent.name;
                cout<<"Nazwisko: "; cin>>newStudent.surname;
                cout<<"Student nr."<<newStudent.id<<" "<<newStudent.name<<" "<<newStudent.surname<<endl;
                string confirmation = "K";
                cout<<"Czy to poprawne? (T/N) ";
                while(true){
                    cin>>confirmation;
                    if(confirmation == "T" || confirmation == "N"){
                        break;
                    }
                }
                if(!confirmation.compare("T")){
                    fstream studentData;
                    studentData.open("student_data.txt", ios_base::app);
                    studentData<<newStudent.id;
                    studentData<<" ";
                    studentData<<newStudent.name;
                    studentData<<" ";
                    studentData<<newStudent.surname<<endl;
                    studentData.close();
                    break;
                }
                if(!confirmation.compare("N")){
                    cout<<"Prosze ponownie wstawic dane:"<<endl;
                }
            }
        }
    }
    
    return 0;
}
