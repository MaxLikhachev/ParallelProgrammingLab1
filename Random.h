#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

const double degreesToRadiansCoefficient = 0.0174533;

template <typename T>
vector<vector<T>> random(int size, T min, T max)
{
	minstd_rand rand(clock());
	uniform_int_distribution<> distribution(min, max);

	vector<vector<T>>array(size, vector<T>(size, 0.0));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			array[i][j] = distribution(rand) * degreesToRadiansCoefficient;

	return array;
}
