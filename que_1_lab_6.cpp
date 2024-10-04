#include<bits/stdc++.h>
using namespace std;

int main(){
int n= 6,i,j;
vector<int> x={10,8,12,15,8,10};
vector<int> y={7,4,6,7,9,8};

int sum_x=accumulate(x.begin(),x.end(),0);
int sum_y= accumulate(y.begin(),y.end(),0);
double mean_x = sum_x/n;
double mean_y = sum_y/n;

cout<<mean_x<<"  "<<mean_y<<endl;


}
