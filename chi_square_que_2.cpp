#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>  // for accumulate

// Function to calculate sample variance
double calculateVariance(const std::vector<int>& data) {
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    double variance = 0.0;
    for (const auto& val : data) {
        variance += (val - mean) * (val - mean);
    }
    return variance / (data.size() - 1); // Sample variance
}

// Pre-calculated chi-square critical values for df = 19 (20 - 1 degrees of freedom)
// for a 95% confidence interval (alpha = 0.05)
// Chi-square lower = 8.907, Chi-square upper = 32.852 (from standard chi-square table)
double chi2_lower = 8.907;
double chi2_upper = 32.852;

int main() {
    std::vector<int> data = {581, 580, 581, 577, 580, 581, 577, 579, 579, 578,
                             581, 583, 577, 578, 582, 581, 582, 580, 582, 579};
    
    int n = data.size(); // Sample size
    double alpha = 0.05; // Significance level
    double sampleVariance = calculateVariance(data);
    
    // Degrees of freedom
    int df = n - 1;
    
    // Confidence interval for variance
    double lowerVariance = (df * sampleVariance) / chi2_upper;
    double upperVariance = (df * sampleVariance) / chi2_lower;
    
    // Confidence interval for standard deviation
    double lowerStdDev = std::sqrt(lowerVariance);
    double upperStdDev = std::sqrt(upperVariance);
    
    // Display the results
    std::cout << "95% Confidence Interval for Variance: (" << lowerVariance << ", " << upperVariance << ")" << std::endl;
    std::cout << "95% Confidence Interval for Standard Deviation: (" << lowerStdDev << ", " << upperStdDev << ")" << std::endl;

    return 0;
}
