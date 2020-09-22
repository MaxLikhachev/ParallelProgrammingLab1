#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "TestTypes.h"

using namespace std;

template <typename T>
void analyse(vector<vector<T>> array) {
	cout << "\nAnalysys:\n";
	vector<T>averages(array.size(), 0.0);

	for (int i = 0; i < array.size(); i++)
	{
		cout << getTestType(i) << " test:";
		auto minmax = minmax_element(array[i].begin(), array[i].end());
		cout << " Min: " << *minmax.first;
		cout << " Max: " << *minmax.second;
		T average = accumulate(array[i].begin(), array[i].end(), 0.0 / array[i].size());
		cout << " Avg: " << average << endl;
		averages[i] = average;
	}

	cout << "\nConclusion:\n";
	cout << "Best method: " << getTestType(min_element(averages.begin(), averages.end()) - averages.begin()) << " (" << *min_element(averages.begin(), averages.end()) << ")\n";
	cout << "Worst method: " << getTestType(max_element(averages.begin(), averages.end()) - averages.begin()) << " (" << *max_element(averages.begin(), averages.end()) << ")\n";
}