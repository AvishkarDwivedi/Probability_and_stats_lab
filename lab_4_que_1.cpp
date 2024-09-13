
#include<bits/stdc++.h>
using namespace std;

int main() {
    int i;
    int n = 10;
    vector<int> x = {3, 3, 4, 5, 6, 6, 7, 8, 8, 9};
    vector<int> y = {9, 5, 12, 9, 14, 16, 22, 18, 24, 22};

    int sum_x = accumulate(x.begin(), x.end(), 0);
    int sum_y = accumulate(y.begin(), y.end(), 0);

    vector<int> x_square(n);
    vector<int> y_square(n);
    vector<int> x_multiplies_y(n);

    for (i = 0; i < n; i++) {
        x_square[i] = x[i] * x[i];
        y_square[i] = y[i] * y[i];
        x_multiplies_y[i] = x[i] * y[i];
    }

    int sum_x_square = accumulate(x_square.begin(), x_square.end(), 0);
    int sum_y_square = accumulate(y_square.begin(), y_square.end(), 0);
    int sum_x_multiplies_y = accumulate(x_multiplies_y.begin(), x_multiplies_y.end(), 0);

    double L_xy = sum_x_multiplies_y - ((static_cast<double>(sum_x) * sum_y) / n);
    double L_xx = sum_x_square - (static_cast<double>(sum_x) * sum_x / n);
    double L_yy = sum_y_square - (static_cast<double>(sum_y) * sum_y / n);

    double r = L_xy / sqrt(L_xx * L_yy);

    cout << "Correlational coefficient is: " << r << endl;

    return 0;
}
