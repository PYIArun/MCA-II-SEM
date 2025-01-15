#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <matplotlibcpp.h>
using namespace std;

namespace plt = matplotlibcpp;

int LinearSearch(int arr[], int size, int key, int &count) {
    for (int i = 0; i < size; i++) {
        count++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}


int main() {
   

    vector <int> best_cases;
    vector <int> worst_cases;
    vector <int> average_cases;
    vector <int> n_values;


    for(int n = 1; n<100; n+=5){
        
        srand(time(0));
        n_values.push_back(n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n + 1; 
        }
        int size = sizeof(arr) / sizeof(arr[0]);
        

        srand(time(0) + 1);  

        int keys[n];
        for (int i = 0; i < 10; i++) {
            keys[i] = rand() % (n*2) + 1; 
        }
        int key_size = sizeof(keys) / sizeof(keys[0]);

        int sumForAverage = 0;
        int bestcase = INT_MAX;
        int worstcase = INT_MIN;
        for (int i = 0; i < key_size; i++) {
            int count = 0;
            LinearSearch(arr, size, keys[i], count);

            bestcase = min(bestcase, count);
            worstcase = max(worstcase, count);
            sumForAverage = sumForAverage + count;
        }

        int average_case = (sumForAverage / key_size);

        best_cases.push_back(bestcase);
        worst_cases.push_back(worstcase);
        average_cases.push_back(average_case);

        cout << "*** No. of comparisons in (n= " << n << ") ****" << endl;
        cout << "Best Case: " << bestcase << endl;
        cout << "Worst Case: " << worstcase << endl;
        cout << "Average Case: " << average_case << endl;


    }

    //Plotting
    plt::scatter(n_values, best_cases, 50.0); 
    plt::scatter(n_values, worst_cases, 50.0);
    plt::scatter(n_values, average_cases, 50.0);

    plt::plot(n_values, best_cases, {{"label", "Best Case"}, {"color", "green"}});
    plt::plot(n_values, worst_cases, {{"label", "Worst Case"}, {"color", "red"}});
    plt::plot(n_values, average_cases, {{"label", "Average Case"}, {"color", "blue"}});

    plt::xlabel("n");
    plt::ylabel("Number of Comparisons");
    plt::title("Linear Search Comparisons vs Array Size");
    plt::legend();

    plt::show();
    return 0;
}


