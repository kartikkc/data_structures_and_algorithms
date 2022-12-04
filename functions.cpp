#include<iostream>
using namespace std;



int sum(int a, int b){
    cout<<"Using functions with 2 arguements";
    return a+b;
}

int sum(int a, int b, int c){
    return a+b+c;
    // return c;
}
// int sum(int a, int b);
int main(){

    return 0;
}

// creating class

class jayden{
    private: 

     int a, b, c;
    
     public :
     
     int d ,e;
     void setdata(int a, int b, int c);  //Declaration of the function !! which will use the private variables in the class and will put the values into them ! (setdata is a custom build function)
     void getdata(){
        cout << "The value of";
     }
};

