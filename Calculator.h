#pragma once
#include <vector>
#include <omp.h>
#include "Formula.h"

template <typename T>
vector<vector<T>> parallelScheduleStaticCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (static) // dynamic, runtime
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> parallelScheduleDynamicCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (dynamic)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> parallelScheduleRunTimeCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (runtime) 
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> parallelColumnsCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel 
	{
		for (int i = 0; i < size; i++)
#pragma omp for
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> parallelBlocksCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel 
	{
#pragma omp for
		for (int i = 0; i < size; i++)
#pragma omp for
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> parallelRowsCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));
#pragma omp parallel 
	{
#pragma omp for
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}

template <typename T>
vector<vector<T>> seqentialCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

	return array;
}

template <typename T>
T averageDeviationCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB, vector<vector<T>> arrayC)
{
	int size = arrayA.size();
	T controlSum = 0.0;
	int controlCounter = 0;
	vector<vector<T>>controlArray(size, vector<T>(size, 0.0));
	controlArray = seqentialCalculate(arrayA, arrayB);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++, controlCounter++)
			controlSum += controlArray[i][j] - arrayC[i][j];

	return controlSum / controlCounter;
}