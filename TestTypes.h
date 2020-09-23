#pragma once
#include <string>

enum class TestTypes 
{
    SEQENTIAL,
    PARALLEL_ROWS,
    PARALLEL_COLUMNS,
    PARALLEL_BLOCKS,
    PARALLEL_SCHEDULE_STATIC,
    PARALLEL_SCHEDULE_DYNAMIC,
    PARALLEL_SCHEDULE_GUIDED,
    PARALLEL_SCHEDULE_DYNAMIC_2,
    PARALLEL_SCHEDULE_DYNAMIC_4,
    PARALLEL_SCHEDULE_DYNAMIC_6,
};

template<typename T>
string getTestType(T index) 
{
    switch (index) 
    {
        case TestTypes::SEQENTIAL: return "Seqential method"; break;
        case TestTypes::PARALLEL_ROWS: return "Parallel by rows method"; break;
        case TestTypes::PARALLEL_COLUMNS: return "Parallel by columns method"; break;
        case TestTypes::PARALLEL_BLOCKS: return "Parallel by blocks method"; break;
        case TestTypes::PARALLEL_SCHEDULE_STATIC: return "Parallel by shedule static method"; break;
        case TestTypes::PARALLEL_SCHEDULE_DYNAMIC: return "Parallel by shedule dynamic method"; break;
        case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_2: return "Parallel by shedule dynamic(2) method"; break;
        case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_4: return "Parallel by shedule dynamic(4) method"; break;
        case TestTypes::PARALLEL_SCHEDULE_DYNAMIC_6: return "Parallel by shedule dynamic(6) method"; break;
        case TestTypes::PARALLEL_SCHEDULE_GUIDED: return "Parallel by shedule guided method"; break;
        default: return "Unknown method";
    }
}
