#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function Declaration
void inputData(vector<string> &grade, vector<int> &creditHour, int coursesNum);
void calculateGradePoints(vector<string> &grade, vector<float> &GP, int coursesNum);
float calculateGPA(vector<int> &creditHour, vector<float> &GP, int coursesNum, int &credithrSUM, float &gpSUM);
float calculateCGPA(float currentCGPA, int creditearned, float gpSUM, int credithrSUM);
void displayTranscript(vector<string> &grade, vector<int> &creditHour, vector<float> &GP, 
     int coursesNum, float GPA, float CGPA);

// Main Function
int main(){
     float currentCGPA;
     int creditearned;
     int coursesNum;

     int credithrSUM=0;
     float gpSUM=0;
     float GPA = 0.0;
     float CGPA = 0.0;

     cout<<"ENTER YOUR CURRENT CGPA: ";
     cin>>currentCGPA;

     cout<<"ENTER PREVIOUSLY EARNED CREDITS: ";
     cin>>creditearned;

     cout<<"=====CURRENT SEMESTER====="<<endl;
     cout<<"ENTER NUMBER OF COURSES: ";
     cin>>coursesNum;

    while(coursesNum <= 0){
    cout << "ENTER A VALID NUMBER: ";
    cin >> coursesNum;
 }

    vector <string> grade(coursesNum);
    vector <int> creditHour(coursesNum);
    vector <float> GP(coursesNum);
    
    inputData(grade, creditHour, coursesNum);
    calculateGradePoints(grade, GP, coursesNum);
    GPA = calculateGPA(creditHour, GP, coursesNum, credithrSUM, gpSUM);
    CGPA = calculateCGPA(currentCGPA, creditearned, gpSUM, credithrSUM);
    displayTranscript(grade, creditHour, GP, coursesNum, GPA, CGPA);

    return 0;

}

// Function Definition
void inputData(vector<string> &grade, vector<int> &creditHour, int coursesNum){
 for(int i=0;i<coursesNum;i++){
        cout<<"COURSE "<<i+1<<endl;
            cout<<"ENTER CREDIT HOURS: ";
            cin>>creditHour[i];

            if(creditHour[i] <= 0){
             cout << "ERROR: CREDIT HOURS MUST BE POSITIVE. ENTER AGAIN!" << endl;
             i--;
             continue;
          }

            cout<<"ENTER GRADE: ";
            cin>>grade[i];


     if(grade[i]!="A+" && grade[i]!="A" && grade[i]!="A-" &&
       grade[i]!="B+" && grade[i]!="B" && grade[i]!="B-" &&
       grade[i]!="C+" && grade[i]!="C" && grade[i]!="C-" &&
       grade[i]!="D+" && grade[i]!="D"&& grade[i]!="F"){
        cout<<"INVALID GRADE, ENTER AGAIN!"<<endl;
        i--;
        continue;
    }
}
}

void calculateGradePoints(vector<string> &grade, vector<float> &GP, int coursesNum){

     for(int i =0;i<coursesNum;i++){
        if(grade[i]=="A+"){
              GP[i] = 4.00;
        }
        else if(grade[i]=="A"){
             GP[i] = 4.00;
        }
        else if(grade[i]=="A-"){
             GP[i] = 3.67;
        }
        else if(grade[i]=="B+"){
             GP[i] = 3.33;
        }
        else if(grade[i]=="B"){
             GP[i] = 3.00;
        }
        else if(grade[i]=="B-"){
             GP[i] = 2.67;
        }
        else if(grade[i]=="C+"){
             GP[i] = 2.33;
        }
        else if(grade[i]=="C"){
             GP[i] = 2.00;
        }
        else if(grade[i]=="C-"){
             GP[i] = 1.67;
        }
        else if(grade[i]=="D+"){
             GP[i] = 1.33;
        }
        else if(grade[i]=="D"){
             GP[i] = 1.00;
        }
        else if(grade[i]=="F"){
          GP[i] = 0.00;
        }
     }   
}

float calculateGPA(vector<int> &creditHour, vector<float> &GP, int coursesNum, int &credithrSUM, float &gpSUM){

     for(int i=0;i<coursesNum;i++)
     {
     credithrSUM+=creditHour[i];
     gpSUM+=GP[i]*creditHour[i];
     }

    return gpSUM/credithrSUM;
}

float calculateCGPA(float currentCGPA, int creditearned, float gpSUM, int credithrSUM){

     return (currentCGPA*creditearned+gpSUM)/(creditearned+credithrSUM);
}

void displayTranscript(vector<string> &grade, vector<int> &creditHour, 
     vector<float> &GP, int coursesNum, float GPA, float CGPA){

     cout<<"---------------------------------TRANSCRIPT-------------------------------------"<<endl;
     cout << fixed << setprecision(2);
     cout<<"\tGPA : "<<GPA<<"\t\t\t\t\t\t"<<"CGPA: "<<CGPA<<endl;
     
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"COURSE\t\t|\tCREDIT HRS\t|\tPOINTS\t\t|\tGRADES"<<endl;
    for(int i=0;i<coursesNum;i++){
     cout<<"   "<<i+1<<"\t\t|\t";
     cout<<"   "<<creditHour[i]<<"\t\t|\t";
     cout<<"   "<<GP[i]<<"\t\t|\t";
     cout<<"  "<<grade[i]<<endl;
    }
    cout<<"--------------------------------------------------------------------------------"<<endl;
}

