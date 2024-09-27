
#include<bits/stdc++.h>
using namespace std;

int main() {
    int i;
    int n = 10;
    vector<double> x = {12.5,5.0,3.0,5.0,6.5,6.0,4.0,7.0,5.5,4.0};
    vector<double> y = {10,26,41,29,27,19,18,20,28,33};

    double sum_x = accumulate(x.begin(), x.end(), 0);
    double sum_y = accumulate(y.begin(), y.end(), 0);
    double mean_x = sum_x/n;
    double mean_y = sum_y / n;

    vector<double> x_square(n);
    vector<double> y_square(n);
    vector<double> x_multiplies_y(n);

    for (i = 0; i < n; i++) {
        x_square[i] = x[i] * x[i];
        y_square[i] = y[i] * y[i];
        x_multiplies_y[i] = x[i] * y[i];
    }

    double sum_x_square = accumulate(x_square.begin(), x_square.end(), 0);
    double sum_y_square = accumulate(y_square.begin(), y_square.end(), 0);
    double sum_x_multiplies_y = accumulate(x_multiplies_y.begin(), x_multiplies_y.end(), 0);

    double L_xy = sum_x_multiplies_y - ((static_cast<double>(sum_x) * sum_y) / n);
    double L_xx = sum_x_square - (static_cast<double>(sum_x) * sum_x / n);
    double L_yy = sum_y_square - (static_cast<double>(sum_y) * sum_y / n);

    double r = L_xy / sqrt(L_xx * L_yy);

    cout << "Correlational coefficient is: " << r << endl;

    double standard_deviation_sum_x=0;
    double standard_deviation_sum_y=0;
    for(i=0;i<n;i++){
        standard_deviation_sum_x += pow(x[i]-mean_x,2);
        standard_deviation_sum_y += pow(y[i]-mean_y,2);
    }
    double standard_deviation_x = sqrt(standard_deviation_sum_x / n);
    double standard_deviation_y = sqrt(standard_deviation_sum_y / n);

    cout<<"standard deviation of x is: "<<standard_deviation_x<<endl;
    cout<<"Standard deviation of y is: "<<standard_deviation_y<<endl;

    cout<<"eq of line about y on x is  : y-"<<mean_y<<" = "<< r * (standard_deviation_y/ standard_deviation_x)<<"x - "<<mean_x<<endl;
    cout<<"eq of line about x on y is  : y-"<<mean_y<<" = "<< r * (standard_deviation_x/ standard_deviation_y)<<"x - "<<mean_x<<endl;


    return 0;
}
