#pragma once
#include <iostream>
#include <vector>
#include <omp.h>

#include "Random.h"
#include "Calculator.h" 
#include "TestTypes.h"
#include "Analyser.h" 

template <typename T>
double test(vector<vector<T>> arrayA, vector<vector<T>> arrayB, TestTypes type) {
    int size = arrayA.size();
    vector<vector<T>>arrayC(size, vector<T>(size, 0.0));
    double start = omp_get_wtime();

    switch (type)
    {
    case TestTypes::PARALLEL_SCHEDULE_GUIDED: arrayC = parallelScheduleGuidedCalculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_SCHEDULE_DYNAMIC: arrayC = parallelScheduleDynamicCalculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_2: arrayC = parallelScheduleDynamic2Calculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_4: arrayC = parallelScheduleDynamic4Calculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_6: arrayC = parallelScheduleDynamic6Calculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_SCHEDULE_STATIC: arrayC = parallelScheduleStaticCalculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_BLOCKS: arrayC = parallelBlocksCalculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_COLUMNS: arrayC = parallelColumnsCalculate(arrayA, arrayB); break;
    case TestTypes::PARALLEL_ROWS: arrayC = parallelRowsCalculate(arrayA, arrayB); break;
    case TestTypes::SEQENTIAL: arrayC = seqentialCalculate(arrayA, arrayB); break;
    default: break;
    }
    
    double end = omp_get_wtime(), time = (end - start) * 1000;
    
    // cout << "Avg deviate: " << averageDeviationCalculate(arrayA, arrayB, arrayC) << endl;
    if (averageDeviationCalculate(arrayA, arrayB, arrayC) != 0.0)
         cout << "ERROR: arrayC not correct";

    return time;
}

template <typename T>
void tests(vector<vector<T>> arrayA, vector<vector<T>> arrayB, vector<TestTypes> types, int count)
{
    vector<vector<double>> times(types.size(), vector<double>(count, 0.0));

    for (int i = 0; i < types.size(); i++)
    {
        cout << getTestType(types[i]) << " testing...\n";
        for (int j = 0; j < count; j++)
            times[i][j] = test(arrayA, arrayB, types[i]);
        
        cout << getTestType(types[i]) << " tested\n\n";
    }

    analyse(times, types);
}

