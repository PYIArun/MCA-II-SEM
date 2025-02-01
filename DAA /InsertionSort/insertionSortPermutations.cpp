#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <matplotlibcpp.h>
using namespace std;
namespace plt = matplotlibcpp;

void insertionSort(vector<int>& A, int &comparisons, int &assignments) {
        /*
    Function: Sorts a vector using Insertion Sort.
    Input: 
        - A: Vector to sort (modified in place).
        - comparisons: Counts comparisons made.
        - assignments: Counts assignments made.
    Output: 
        - Sorted vector A.
        - Updated counts for comparisons and assignments.
    */
    int n = A.size();
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

int main() {
    int n = 5; // Fixed size of the array
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = i + 1; // Initialize array with values 1, 2, 3, 4, 5
    }

    vector<int> comparisonCounts;
    vector<int> assignmentCounts;

    int sumForAverage = 0;
    int sumForAverage2 = 0;
    int bestComparisons = INT_MAX;
    int worstComparisons = INT_MIN;
    int bestAssignments = INT_MAX;
    int worstAssignments = INT_MIN;

    // Generate all permutations of the array
    do {
        int comparisons = 0;
        int assignments = 0;
        vector<int> tempArray = array; // Copy the array for sorting

        insertionSort(tempArray, comparisons, assignments);

        // Update best and worst cases
        bestComparisons = min(bestComparisons, comparisons);
        worstComparisons = max(worstComparisons, comparisons);
        bestAssignments = min(bestAssignments, assignments);
        worstAssignments = max(worstAssignments, assignments);

        // Accumulate totals for average calculation
        sumForAverage += comparisons;
        sumForAverage2 += assignments;

        // Store counts for plotting
        comparisonCounts.push_back(comparisons);
        assignmentCounts.push_back(assignments);

    } while (next_permutation(array.begin(), array.end()));

    // Calculate average cases
    int averageComparisons = sumForAverage / comparisonCounts.size();
    int averageAssignments = sumForAverage2 / assignmentCounts.size();

    // Print results
    cout << "*** Results for n = " << n << " ***" << endl;
    cout << "Best Case Comparisons: " << bestComparisons << endl;
    cout << "Worst Case Comparisons: " << worstComparisons << endl;
    cout << "Average Case Comparisons: " << averageComparisons << endl;
    cout << "Best Case Assignments: " << bestAssignments << endl;
    cout << "Worst Case Assignments: " << worstAssignments << endl;
    cout << "Average Case Assignments: " << averageAssignments << endl;

    // Plotting the results
    // As 5 factorial is 120..
    // So there are 120 different permutations

    vector<int> permutationIndices(120);
    for (int i = 0; i < permutationIndices.size(); i++) {
        permutationIndices[i] = i + 1;
    }

    // Plot comparisons
    plt::figure();
    plt::plot(permutationIndices, comparisonCounts, {{"label", "Comparisons"}, {"color", "blue"}});
    plt::axhline(bestComparisons, 0, permutationIndices.size(), {{"label", "Best Case"}, {"color", "green"}});
    plt::axhline(worstComparisons, 0, permutationIndices.size(), {{"label", "Worst Case"}, {"color", "red"}});
    plt::axhline(averageComparisons, 0, permutationIndices.size(), {{"label", "Average Case"}, {"color", "orange"}});
    plt::xlabel("ith Permutation");
    plt::ylabel("Number of Comparisons");
    plt::title("Insertion Sort Comparisons for All Permutations (n = 5)");
    plt::legend();

    // Plot assignments
    plt::figure();
    plt::plot(permutationIndices, assignmentCounts, {{"label", "Assignments"}, {"color", "blue"}});
    plt::axhline(bestAssignments, 0, permutationIndices.size(), {{"label", "Best Case"}, {"color", "green"}});
    plt::axhline(worstAssignments, 0, permutationIndices.size(), {{"label", "Worst Case"}, {"color", "red"}});
    plt::axhline(averageAssignments, 0, permutationIndices.size(), {{"label", "Average Case"}, {"color", "orange"}});
    plt::xlabel("ith Permutation");
    plt::ylabel("Number of Assignments");
    plt::title("Insertion Sort Assignments for All Permutations (n = 5)");
    plt::legend();

    // Show plots
    plt::show();

    return 0;
}