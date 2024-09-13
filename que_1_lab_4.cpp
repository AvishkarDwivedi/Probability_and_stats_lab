#include<bits/stdc++.h>
using namespace std;

int calculatePower(int x,unsigned n){
 long long pow=1;
 for(int i=0;i<n;i++){
    pow= pow *n;
 }
 return pow;
}

int main(){
int i,j,x,power;
unsigned n;

cout<<"enter the no: "<<endl;
cin>>x;

cout<<"enter the power"<<endl;
cin>>n;

cout<<"power of the number: "<<calculatePower(x,n)<<endl;



}
