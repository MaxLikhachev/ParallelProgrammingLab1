#pragma once
#include <vector>
#include <omp.h>
#include "Formula.h"
// Параллельный метод с schedule(dynamic)
template <typename T>
vector<vector<T>> parallelScheduleStaticCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size);
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (static)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод с schedule(dynamic)
template <typename T>
vector<vector<T>> parallelScheduleDynamicCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size); 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (dynamic)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод с schedule(dynamic, 2)
template <typename T>
vector<vector<T>> parallelScheduleDynamic2Calculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size); 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (dynamic, 2)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод с schedule(dynamic, 4)
template <typename T>
vector<vector<T>> parallelScheduleDynamic4Calculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size); 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (dynamic, 4)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод с schedule(dynamic, 6)
template <typename T>
vector<vector<T>> parallelScheduleDynamic6Calculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size); 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (dynamic, 6)
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод с schedule(guided)
template <typename T>
vector<vector<T>> parallelScheduleGuidedCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size); 
	{
		for (int i = 0; i < size; i++)
#pragma omp for schedule (guided) 
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод по колонкам
template <typename T>
vector<vector<T>> parallelColumnsCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size);
	{
		for (int i = 0; i < size; i++)
#pragma omp for
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод по блокам
template <typename T>
vector<vector<T>> parallelBlocksCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0.0));

#pragma omp parallel shared(arrayA, arrayB) private(i, size);
	{
#pragma omp for
		for (int i = 0; i < size; i++)
#pragma omp for
			for (int j = 0; j < size; j++)
				array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

		return array;
	}
}
// Параллельный метод по строкам
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
// Последовательный метод
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
// Проверка отклонений значений от последовательного вычисления
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