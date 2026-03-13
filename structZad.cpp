/*
    Szymon Zeller Informatyka1
    PRogram do czytania i wpisywania structów do pliku .txt
*/

#include <iostream>
#include <vector>
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

    //Pętla z wyborem zapisu i czytania z pliku
    string checkIntent = "K";
    while(true){
        cout<<"Chcesz wpisac uczniow czy czytac uczniow z pliku? (W/C)"<<endl;
        cin>>checkIntent;
        if(checkIntent == "W" || checkIntent == "C"){
            break;
        }
    }

    //Wypisywanie danych z pliku i zapamiętywanie ostatniego id
    int lastStudentId = 0;
    if(checkIntent == "C"){
        ifstream studentData("student_data.txt");
        string x = "";
        while(studentData >> x){
            lastStudentId = stoi(x);        //TODO refactor for this value
            cout<<"ID: "<<x<<endl;
            studentData >> x; cout<<"Imie: "<<x<<endl;
            studentData >> x; cout<<"Nazwisko: "<<x<<endl;
        }
        studentData.close();
    }
    
    //Wypełnianie danych do wpisania poprzez vector
    if(checkIntent == "W"){
        cout<<"Ile studentow do wpisania?"<<endl;
        int studentsNumber;
        cin>>studentsNumber;
        vector<student> studentsToWrite;
        for(int i = 1; i <= studentsNumber; i++){
            while(true){
                student newStudent;
                newStudent.id = i+lastStudentId;
                cout<<"Imie: "; cin>>newStudent.name;
                cout<<"Nazwisko: "; cin>>newStudent.surname;
                cout<<"Student nr."<<newStudent.id<<" "<<newStudent.name<<" "<<newStudent.surname<<endl;
                string confirmation = "K";
                cout<<"Czy to poprawne? (T/N)";
                while(true){
                    cin>>confirmation;
                    if(confirmation == "T" || confirmation == "N"){
                        break;
                    }
                }
                if(confirmation == "T"){
                    fstream studentData("student_data.txt", ios_base::app);     //TODO not writing out into the file
                    studentData<<newStudent.id;
                    studentData<<"Writeout check";      //This one does not work as well...
                    studentData<<" ";
                    studentData<<newStudent.name;
                    studentData<<" ";
                    studentData<<newStudent.surname<<endl;
                    studentData.close();
                    break;
                }
                if(confirmation == "N"){
                    cout<<"Prosze ponownie wstawic dane:"<<endl;
                }
            }
        }
    }
    
    return 0;
}
