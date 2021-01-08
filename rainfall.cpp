/*
    rainfall.cpp

    Rainfall report. Individual rain amounts per hour are input. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main() {

    // input hourly rainfall data
    std::vector<double> rainfall;
    double n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size())
        return 1;

    // calculate average and heaviest rainfall
    double t = rainfall[0];
    double m = rainfall[0];
    for (int i = 1; i < rainfall.size(); ++i) {
        t += rainfall[i];
        if (rainfall[i] > m)
            m = rainfall[i];
    }

    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << m << " hundreds of inches" << '\n';

    return 0;
}
