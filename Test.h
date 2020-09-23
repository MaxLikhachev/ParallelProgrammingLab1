#pragma once
#include <iostream>
#include <vector>
#include <omp.h>

#include "Random.h"
#include "Calculator.h" 
#include "TestTypes.h"

template <typename T>
double test(vector<vector<T>> arrayA, vector<vector<T>> arrayB, TestTypes type) {
    int size = arrayA.size();
    vector<vector<T>>arrayC(size, vector<T>(size, 0.0));
    double start = omp_get_wtime();

    switch (type)
    {
    case PARALLEL_SCHEDULE_RUNTIME: arrayC = parallelScheduleRunTimeCalculate(arrayA, arrayB); break;
    case PARALLEL_SCHEDULE_DYNAMIC: arrayC = parallelScheduleDynamicCalculate(arrayA, arrayB); break;
    case PARALLEL_SCHEDULE_STATIC: arrayC = parallelScheduleStaticCalculate(arrayA, arrayB); break;
    case PARALLEL_BLOCKS: arrayC = parallelBlocksCalculate(arrayA, arrayB); break;
    case PARALLEL_COLUMNS: arrayC = parallelColumnsCalculate(arrayA, arrayB); break;
    case PARALLEL_ROWS: arrayC = parallelRowsCalculate(arrayA, arrayB); break;
    case SEQENTIAL: arrayC = seqentialCalculate(arrayA, arrayB); break;
    default: break;
    }
    
    double end = omp_get_wtime(), time = (end - start) * 1000;

    if (averageDeviationCalculate(arrayA, arrayB, arrayC) != 0.0)
        cout << "ERROR: arrayC not correct";

    return time;
}


