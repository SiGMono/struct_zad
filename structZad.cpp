/*
    Szymon Zeller Informatyka1
    PRogram do czytania i wpisywania structów do pliku .txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    
    //Wypełnianie danych do wpisania poprzez vector i zapisywnie ich do pliku           (mam wrazenie ze lepiej by to dzialalo bez vectora wiec dodałem potwierdzenie czy dane sie zgadzają żeby nadać sensu istnienia temu vectorowi)
    if(checkIntent == "T"){
        cout<<"Ile studentow do wpisania?"<<endl;
        int studentsNumber;
        cin>>studentsNumber;
        vector<student> students;//<--- temu vectorowi
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
                    students.push_back(newStudent);
                    break;
                    //Ten kod znajdował się tutaj przed wpisywaniem do vectora i wpisywał wprost bez końcowego potwierdzenia
                    /*fstream studentData;
                    studentData.open("student_data.txt", ios_base::app);
                    studentData<<newStudent.id;
                    studentData<<" ";
                    studentData<<newStudent.name;
                    studentData<<" ";
                    studentData<<newStudent.surname<<endl;
                    studentData.close();
                    break;*/
                }
                if(!confirmation.compare("N")){
                    cout<<"Prosze ponownie wstawic dane:"<<endl;
                }
            }
        }
        for(auto s:students){
            cout<<"ID: "<<s.id<<" - "<<s.name<<" "<<s.surname<<endl;
        }
        cout<<"Czy te dane sie zgadzaja? (T/N) ";
        string fullCorrectness = "K";
        while(true){
            cin>>fullCorrectness;
            if(fullCorrectness == "T"){
                for(auto s:students){
                    fstream studentData;
                    studentData.open("student_data.txt", ios_base::app);
                    studentData<<s.id<<" "<<s.name<<" "<<s.surname<<endl;
                    studentData.close();
                }
                break;
            }
            if(fullCorrectness == "N"){
                cout<<"Dane nie zostaly zapisane i program zostanie zamkniety.";
                break;
            }
        }
    }
    
    return 0;
}
