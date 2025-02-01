#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <matplotlibcpp.h>
using namespace std;

namespace plt = matplotlibcpp;

void insertionSort(int A[], int n, int &comparisons, int &assignments){
        /*
    Function: Sorts an array A[] of length n using Insertion Sort.
    Input: 
        - A: An array to sort (modified in place).
        - comparisons: Counts comparisons made.
        - assignments: Counts assignments made.
    Output: 
        - Sorted array A.
        - Updated counts for comparisons and assignments.
    */
    for( int i = 1; i<=n-1; i++){
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j]>key){
            //No. of comparisons computed here
            comparisons++;
            A[j+1] = A[j];
            //No. of assignments computed here
            assignments++;
            j = j-1;
        }
          
        if (j >= 0) {
            comparisons++; // final comparison when key is inserted
        }

        A[j+1] = key;
        assignments++;
    }

}

int main(){

    srand(time(0));
    vector <int> n_values;

    vector <int> best_casesC;
    vector <int> worst_casesC;
    vector <int> average_casesC;

    vector <int> best_casesA;
    vector <int> worst_casesA;
    vector <int> average_casesA;

    for(int n = 0; n<100; n+=5){
        
        n_values.push_back(n);
        
        int sumForAverage = 0;
        int averagecaseComparisons;
        int bestcaseComparisons = INT_MAX;
        int worstcaseComparisons = INT_MIN;

        int sumForAverage2 = 0;
        int averagecaseAssignments;
        int bestcaseAssignments = INT_MAX;
        int worstcaseAssignments = INT_MIN;
        
        for (int i = 0; i < 10; i++) {

            int arr[n];
            int comparisons=0;
            int assignments=0;

            for (int i = 0; i < n; i++) {
                arr[i] = rand() % n + 1; 
            }

            insertionSort(arr, n,comparisons, assignments);

            bestcaseComparisons = min(bestcaseComparisons, comparisons);
            worstcaseComparisons = max(worstcaseComparisons, comparisons);
            sumForAverage = sumForAverage + comparisons;


            bestcaseAssignments = min(bestcaseAssignments, assignments);
            worstcaseAssignments = max(worstcaseAssignments, assignments);
            sumForAverage2 = sumForAverage2 + assignments;

        }

        averagecaseComparisons = (sumForAverage / 10);
        averagecaseAssignments = (sumForAverage2/ 10);

        best_casesC.push_back(bestcaseComparisons);
        worst_casesC.push_back(worstcaseComparisons);
        average_casesC.push_back(averagecaseComparisons);

        best_casesA.push_back(bestcaseAssignments);
        worst_casesA.push_back(worstcaseAssignments);
        average_casesA.push_back(averagecaseAssignments);

        cout << "*** No. of comparisons in (n= " << n << ") ****" << endl;
        cout << "Best Case: " << bestcaseComparisons << endl;
        cout << "Worst Case: " << worstcaseComparisons << endl;
        cout << "Average Case: " << averagecaseAssignments<< endl;
        cout << "*** No. of Assignments in (n= " << n << ") ****" << endl;
        cout << "Best Case: " << bestcaseAssignments<< endl;
        cout << "Worst Case: " << worstcaseAssignments << endl;
        cout << "Average Case: " << averagecaseAssignments<< endl;
        cout<<endl;
        cout<<endl;

    }

    // Plotting comparisons
    plt::figure();
    plt::scatter(n_values, best_casesC, 50.0); // Increase the size
    plt::scatter(n_values, worst_casesC, 50.0); 
    plt::scatter(n_values, average_casesC, 50.0);
    plt::plot(n_values, best_casesC, {{"label", "Best Case Comparisons"}, {"color", "green"}});
    plt::plot(n_values, worst_casesC, {{"label", "Worst Case Comparisons"}, {"color", "red"}});
    plt::plot(n_values, average_casesC, {{"label", "Average Case Comparisons"}, {"color", "blue"}});
    plt::xlabel("n");
    plt::ylabel("Number of Comparisons");
    plt::title("Insertion Sort Comparisons vs Array Size");
    plt::legend();

    // Plotting assignments
    plt::figure();
    plt::scatter(n_values, best_casesA, 50.0); 
    plt::scatter(n_values, worst_casesA, 50.0);
    plt::scatter(n_values, average_casesA, 50.0);
    plt::plot(n_values, best_casesA, {{"label", "Best Case Assignments"}, {"color", "green"}});
    plt::plot(n_values, worst_casesA, {{"label", "Worst Case Assignments"}, {"color", "red"}});
    plt::plot(n_values, average_casesA, {{"label", "Average Case Assignments"}, {"color", "blue"}});
    plt::xlabel("n");
    plt::ylabel("Number of Assignments");
    plt::title("Insertion Sort Assignments vs Array Size");
    plt::legend();

    // Show the plots
    plt::show();
    return 0;
}