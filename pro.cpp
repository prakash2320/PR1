#include<iostream>
using namespace std;

int main(){
    int marks;
    cout<<"Enter your marks Mr. Sabare : ";
    cin>>marks;


    if(marks>=90){
        cout<<"congratulaions! you got A+ grade"<<endl;
    }
    else if(marks>=80){
        cout<<"congratulaions! you got A grade"<<endl;
    }
    else if(marks>=70){
        cout<<"congratulaions! you got B+ grade"<<endl;
    }

    else if(marks>=60){
        cout<<"congratulaions! you got B grade"<<endl;
    }

    else if(marks>=50){
        cout<<"congratulaions! you got C grade"<<endl;
    }

    else if(marks>=40){
        cout<<"congratulaions! you got D grade"<<endl;
    }

    else{
         cout<<"Sorry! you have not cleared exam"<<endl;
    }

}

