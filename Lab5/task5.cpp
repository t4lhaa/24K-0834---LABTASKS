#include <iostream>
using namespace std;

int sumDigits(int num) {
    if(num < 10) {
        return num;
    }
    int num1 = num/10;
    int num2 = num%10;
    num = num1+num2;
    num= sumDigits(num);


    return num;
}

int main() {
    cout <<"Enter your number: ";
    int num;
    cin>>num;
                                                                                                                                                              
    int sum = sumDigits(num);
    cout<< sum;

    return 0;
}
