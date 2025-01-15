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
    srand(time(0));
    //For n= 10
    int arr1[10];
    for (int i = 0; i < 10; i++) {
        arr1[i] = rand() % 10 + 1; 
    }
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int keys1[11];
    for (int i = 0; i < 11; i++) {
        keys1[i] = rand() % 11 + 1; 
    }
    int key_size1 = sizeof(keys1) / sizeof(keys1[0]);

    int sumForAverage1 = 0;
    int bestcase1 = INT_MAX;
    int worstcase1 = INT_MIN;
    for (int i = 0; i < key_size1; i++) {
        int count = 0;
        LinearSearch(arr1, size1, keys1[i], count);

        bestcase1 = min(bestcase1, count);
        worstcase1 = max(worstcase1, count);
        sumForAverage1 = sumForAverage1 + count;
    }

    int average_case1 = (sumForAverage1 / key_size1);
    cout << "*** No. of comparisons in (n=10) ****" << endl;
    cout << "Best Case: " << bestcase1 << endl;
    cout << "Worst Case: " << worstcase1 << endl;
    cout << "Average Case: " << average_case1 << endl;

    // For n = 100 

    int arr2[100];
    for (int i = 0; i < 100; i++) {
        arr2[i] = rand() % 100 + 1; 
    }
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int keys2[101];
    for (int i = 0; i < 101; i++) {
        keys2[i] = rand() % 101 + 1; 
    }
    int key_size2 = sizeof(keys2) / sizeof(keys2[0]);

    int sumForAverage2 = 0;
    int bestcase2 = INT_MAX;
    int worstcase2 = INT_MIN;
    for (int i = 0; i < key_size2; i++) {
        int count = 0;
        LinearSearch(arr2, size2, keys2[i], count);

        bestcase2 = min(bestcase2, count);
        worstcase2 = max(worstcase2, count);
        sumForAverage2 = sumForAverage2 + count;
    }

    int average_case2 = (sumForAverage2 / key_size2);
    cout << "*** No. of comparisons in (n=100) ****" << endl;
    cout << "Best Case: " << bestcase2 << endl;
    cout << "Worst Case: " << worstcase2 << endl;
    cout << "Average Case: " << average_case2<< endl;

    // For n = 1000 

    int arr3[1000];
    for (int i = 0; i < 1000; i++) {
        arr3[i] = rand() % 1000 + 1; 
    }
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    int keys3[1001];
    for (int i = 0; i < 1001; i++) {
        keys3[i] = rand() % 1001 + 1; 
    }
    int key_size3 = sizeof(keys3) / sizeof(keys3[0]);

    int sumForAverage3 = 0;
    int bestcase3 = INT_MAX;
    int worstcase3 = INT_MIN;
    for (int i = 0; i < key_size3; i++) {
        int count = 0;
        LinearSearch(arr3, size3, keys3[i], count);

        bestcase3 = min(bestcase3, count);
        worstcase3 = max(worstcase3, count);
        sumForAverage3 = sumForAverage3 + count;
    }

    int average_case3 = (sumForAverage3 / key_size3);
    cout << "*** No. of comparisons in (n=1000) ****" << endl;
    cout << "Best Case: " << bestcase3 << endl;
    cout << "Worst Case: " << worstcase3 << endl;
    cout << "Average Case: " << average_case3 << endl;

    //Plotting
    vector <int> n_values = {10, 100, 1000};
    vector <int> best_cases = {bestcase1, bestcase2, bestcase3};
    vector <int> worst_cases = {worstcase1, worstcase2, worstcase3};
    vector <int> average_cases = {average_case1, average_case2, average_case3};

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


// Feedback
// Random Numbers se input lena hai.
// Excel File ke andar plot karna from C++
// Lines mein dot chahiye.


