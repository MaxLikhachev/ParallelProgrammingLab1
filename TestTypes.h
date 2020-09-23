#pragma once
#include <string>

enum TestTypes 
{
    SEQENTIAL,
    PARALLEL_ROWS,
    PARALLEL_COLUMNS,
    PARALLEL_BLOCKS,
    PARALLEL_SCHEDULE_STATIC,
    PARALLEL_SCHEDULE_DYNAMIC,
    PARALLEL_SCHEDULE_RUNTIME,
};

string getTestType(int index) 
{
    switch (index) 
    {
        case SEQENTIAL: return "Seqential method"; break;
        case PARALLEL_ROWS: return "Parallel by rows method"; break;
        case PARALLEL_COLUMNS: return "Parallel by columns method"; break;
        case PARALLEL_BLOCKS: return "Parallel by blocks method"; break;
        case PARALLEL_SCHEDULE_STATIC: return "Parallel by shedule static method"; break;
        case PARALLEL_SCHEDULE_DYNAMIC: return "Parallel by shedule dynamic method"; break;
        case PARALLEL_SCHEDULE_RUNTIME: return "Parallel by shedule runtime method"; break;
        default: return "Unknown method";
    }
}

string getTestTypeByType(TestTypes index)
{
    switch (index)
    {
    case SEQENTIAL: return "Seqential method"; break;
    case PARALLEL_ROWS: return "Parallel by rows method"; break;
    case PARALLEL_COLUMNS: return "Parallel by columns method"; break;
    case PARALLEL_BLOCKS: return "Parallel by blocks method"; break;
    case PARALLEL_SCHEDULE_STATIC: return "Parallel by shedule static method"; break;
    case PARALLEL_SCHEDULE_DYNAMIC: return "Parallel by shedule dynamic method"; break;
    case PARALLEL_SCHEDULE_RUNTIME: return "Parallel by shedule runtime method"; break;
    default: return "Unknown method";
    }
}
