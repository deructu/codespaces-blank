#include <iostream>

using namespace std;

int main()
{

int x;
cin >> x;


for(int i = 0;i<=x;i++){
    for(int j = i-1; j>=0;j--){
        cout << ' ';
    }
    
    for(int e = i;e<x;e++){
        cout << '*';
    }

    for(int k = x-1; k>i;k--){

        cout << k;
        
    }

cout << '\n';



}

}