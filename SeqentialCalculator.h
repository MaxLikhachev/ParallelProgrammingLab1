#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include "Formula.h"

using namespace std;

template <typename T>
vector<vector<T>> seqentialCalculate(vector<vector<T>> arrayA, vector<vector<T>> arrayB)
{
	int size = arrayA.size();
	vector<vector<T>>array(size, vector<T>(size, 0));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			array[i][j] = calculate(arrayA[i][j], arrayB[i][j]);

	return array;
}

