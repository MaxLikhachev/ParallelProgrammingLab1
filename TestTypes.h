#pragma once
#include <string>

enum TestTypes 
{
    PARALLEL_COLUMNS,
    PARALLEL_ROW,
    SEQENTIAL
};

string getTestType(int index) 
{
    switch (index) 
    {
        case SEQENTIAL: return "Seqential method"; break;
        case PARALLEL_ROW: return "Parallel by rows method"; break;
        case PARALLEL_COLUMNS: return "Parallel by columns method"; break;
        default: return "Unknown method";
    }
}
