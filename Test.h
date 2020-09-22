#pragma once
#include <iostream>
#include <vector>
#include <omp.h>

#include "Random.h"
#include "Calculator.h" 
#include "TestTypes.h"

template <typename T>
T test(vector<vector<T>> arrayA, vector<vector<T>> arrayB, TestTypes type) {
    int size = arrayA.size();
    vector<vector<T>>arrayC(size, vector<T>(size, 0.0));
    double start = omp_get_wtime();

    switch (type)
    {
    case PARALLEL_COLUMNS: arrayC = parallelColumnCalculate(arrayA, arrayB); break;
    case PARALLEL_ROW: arrayC = parallelRowCalculate(arrayA, arrayB); break;
    case SEQENTIAL: arrayC = seqentialCalculate(arrayA, arrayB); break;
    default: break;

    }
    


    double end = omp_get_wtime(), time = end - start;
    if (averageDeviationCalculate(arrayA, arrayB, arrayC) != 0.0)
        cout << "ERROR: arrayC not correct";
    return time;
}


