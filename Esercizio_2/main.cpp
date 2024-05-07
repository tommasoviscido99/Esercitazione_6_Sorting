#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <cstdlib>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;
using namespace chrono;

vector<int> generateRandomVector(int size) {
    vector<int> vec;
    vec.reserve(size);
    for (int i = 0; i < size; i++) {
        vec.push_back(rand());
    }
    return vec;
}

vector<int> generateDescendingVector(int size) {
    vector<int> vec;
    vec.reserve(size);
    for (int i = size; i > 0; i--) {
        vec.push_back(i);
    }
    return vec;
}

void testSortingAlgorithm(const string& algorithmName, void (*sortFunc)(vector<int>&), vector<int>& vec) {
    auto start = steady_clock::now();
    sortFunc(vec);
    auto end = steady_clock::now();
    duration<double> time = end - start;
    cout << "Time taken by " << algorithmName << " for vector of size " << vec.size() << ": " << time.count() << "s" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Incorrect number of arguments. Provide the vector size." << endl;
        return 1;
    }

    int vectorSize;
    istringstream(argv[1]) >> vectorSize;

    vector<int> intVectorRandom = generateRandomVector(vectorSize);
    vector<int> intVectorDescending = generateDescendingVector(vectorSize);


    cout << "Testing BubbleSort:" << endl;
    testSortingAlgorithm("BubbleSort (Random)", BubbleSort, intVectorRandom);
    testSortingAlgorithm("BubbleSort (Descending)", BubbleSort, intVectorDescending);

    cout << endl;

    cout << "Testing MergeSort:" << endl;
    testSortingAlgorithm("MergeSort (Random)", MergeSort, intVectorRandom);
    testSortingAlgorithm("MergeSort (Descending)", MergeSort, intVectorDescending);

    return 0;
}
