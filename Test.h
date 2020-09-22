#pragma once
#include <iostream>
#include <vector>
#include <omp.h>
#include "Random.h"
#include "SeqentialCalculator.h" 

template <typename T>
T seqentialTest(vector<vector<T>> arrayA, vector<vector<T>> arrayB) {
    cout << "Seqentional test: ";
    int size = arrayA.size();
    vector<vector<T>>arrayC(size, vector<T>(size, 0.0));
    double start = omp_get_wtime();
    arrayC = seqentialCalculate(arrayA, arrayB);
    double end = omp_get_wtime(), time = end - start;
    cout << "Average deviation: " << averageDeviationCalculate(arrayA, arrayB, arrayC) << " Time: " << time << endl;
    return time;
}


