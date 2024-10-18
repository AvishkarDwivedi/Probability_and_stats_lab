#include <iostream>
#include <vector>
#include <cmath>
#include <numeric> // for accumulate

using namespace std;

// Function to calculate sample variance
double calculateVariance(const vector<double>& data) {
    int n = data.size();
    double mean = accumulate(data.begin(), data.end(), 0.0) / n;
    double variance = 0.0;

    for(double x : data) {
        variance += (x - mean) * (x - mean);
    }

    return variance / (n - 1); // sample variance formula
}

int main() {
    // Given data
    vector<double> data = {2.02, 1.94, 2.09, 1.95, 1.98, 2.00, 2.03, 2.04, 2.08, 2.07,
                           1.99, 1.96, 1.99, 1.95, 1.99, 1.99, 2.03, 2.05, 2.01, 2.03};

    int n = data.size();
    double alpha = 0.05;

    // Step 1: Calculate sample variance
    double sampleVariance = calculateVariance(data);

    // Step 2: Use chi-square table values for degrees of freedom (n-1 = 19)
    double chi2_lower = 32.852; // chi-square critical value for 0.025 (upper)
    double chi2_upper = 8.907;  // chi-square critical value for 0.975 (lower)

    // Step 3: Compute confidence intervals for variance
    double variance_lower = (n - 1) * sampleVariance / chi2_lower;
    double variance_upper = (n - 1) * sampleVariance / chi2_upper;

    // Step 4: Compute confidence intervals for standard deviation
    double stddev_lower = sqrt(variance_lower);
    double stddev_upper = sqrt(variance_upper);

    // Output the results
    cout << "95% Confidence Interval for Variance: (" << variance_lower << ", " << variance_upper << ")" << endl;
    cout << "95% Confidence Interval for Standard Deviation: (" << stddev_lower << ", " << stddev_upper << ")" << endl;

    return 0;
}
