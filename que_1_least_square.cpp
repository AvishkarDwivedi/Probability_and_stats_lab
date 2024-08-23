#include<bits/stdc++.h>
using namespace std;

int main(){
 double i,n,j;
 vector<int> x{5,10,15,20,25};

 vector<int> y{16,19,23,26,30};


 double m,c;
 double sum_x= accumulate(x.begin(),x.end(),0);
 double mean_x = sum_x/x.size();

 double sum_y= accumulate(y.begin(),y.end(),0);
 double mean_y= sum_y/y.size();

 vector <double> x1(x.size());
 for(i=0;i<x.size();i++){
    x1[i]= mean_x - x[i];


 }
 for(i=0;i<x1.size();i++){
     cout<<x1[i]<<" ";
 }
  vector <double> y1(y.size());
 for(i=0;i<x.size();i++){
    y1[i]= mean_y - y[i];


 }
 cout<<endl;
 for(i=0;i<y1.size();i++){
     cout<<y1[i]<<" ";
 }
 cout<<endl;

 // making the neumerator

 vector <double> slope_numerator(x.size());
 transform(x1.begin(),x1.end(),y1.begin(),slope_numerator.begin(),multiplies<double>());

 for(i=0;i<x.size();i++){
     cout<<slope_numerator[i]<<" ";
 }
 cout<<endl;
 // making the denominator

 vector<double> slope_denominator(x.size());
 transform(x1.begin(),x1.end(),slope_denominator.begin(),[](double val)){
     return val*val;
 };

 for(i=0;i<x1.begin();i++){
     cout<<slope_denominator[i]<<" ";
 }
}
