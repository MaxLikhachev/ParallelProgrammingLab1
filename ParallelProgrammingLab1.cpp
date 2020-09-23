// @ М.Ю.Лихачев 1к.маг.13гр.
//
// Написать программу с использованием технологии OpenMP, которая решает поставленную задачу.
// При этом вычислить максимальное, минимальное и среднее время выполнения программы. 
// Провести анализ для различной размерности задач при различных вариантах распараллеливания(по строкам, столбцам и блокам) и с различными значениями параметра schedule.
// 
// Отчет должен содержать постановку задачи, краткое описание решения, последовательную версию программы и параллельную (наиболее производительную) и таблицу с результатами, выводы.
// 
// Вариант № 5. Написать программу с использованием технологии OpenMP, которая реализует следующие действия :
//  формирует два массива А и В, размерностью N x N и формирует
//  новый массив, элементы которого равны sin(A[I, j])^2 + cos(B[I, j])^3 из
//  соответствующих элементов исходных массивов.
// Найти сумму элементов результирующего массива.


#include <iostream>
#include <vector>
#include <omp.h>

#include "Display.h"
#include "Test.h"
#include "Analyser.h" 
#include "TestTypes.h"

using namespace std;

const double minValue = 0.0;
const double maxValue = 360.0;

int main()
{
    int size = 0;
    cout << "Enter arrays size:\n";
    cin >> size;
    cout << "Arrays size: " << size << endl << endl;

    cout << "Generating array A...\n";
    vector<vector<double>> arrayA(size, vector<double>(size, 0.0));
    arrayA = random(size, minValue, maxValue);
    cout << "Array A generated\n\n";

    cout << "Generating array B...\n";
    vector<vector<double>> arrayB(size, vector<double>(size, 0.0));
    arrayB = random(size, minValue, maxValue);
    cout << "Array B generated\n\n";

    int count = 0;
    cout << "Enter tests count:\n";
    cin >> count;
    cout << "Tests count: " << count << endl << endl;

    vector<TestTypes> typesBeforeAnalyse = { SEQENTIAL, PARALLEL_ROWS, PARALLEL_COLUMNS, PARALLEL_BLOCKS };
    vector<vector<double>> timesBeforeAnalyse(typesBeforeAnalyse.size(), vector<double>(count, 0.0));

    for (int i = 0; i < typesBeforeAnalyse.size(); i++)
    {
        cout << getTestType(typesBeforeAnalyse[i]) << " testing...\n";
        for (int j = 0; j < count; j++)
            timesBeforeAnalyse[i][j] = test(arrayA, arrayB, typesBeforeAnalyse[i]);
        cout << getTestType(typesBeforeAnalyse[i]) << " tested\n\n";
    }
    analyse(timesBeforeAnalyse, typesBeforeAnalyse);

    vector<TestTypes> typesAfterAnalyse = { PARALLEL_SCHEDULE_STATIC, PARALLEL_SCHEDULE_DYNAMIC, PARALLEL_SCHEDULE_RUNTIME };
    vector<vector<double>> timesAfterAnalyse(typesAfterAnalyse.size(), vector<double>(count, 0.0));

    for (int i = 0; i < typesAfterAnalyse.size(); i++)
    {
        cout << getTestType(typesAfterAnalyse[i]) << " testing...\n";
        for (int j = 0; j < count; j++)
            timesAfterAnalyse[i][j] = test(arrayA, arrayB, typesAfterAnalyse[i]);
        cout << getTestType(typesAfterAnalyse[i]) << " tested\n\n";
    }

    analyse(timesAfterAnalyse, typesAfterAnalyse);
}