//
// Created by Ivan Shynkarenka on 26.05.2016
//

#include "benchmark/cppbenchmark.h"

#include "template/function.h"

using namespace CppTemplate;

const uint64_t operations = 10000000;

BENCHMARK("function")
{
    uint64_t crc = 0;

    for (uint64_t i = 0; i < operations; ++i)
        crc += function(1000);

    // Update benchmark metrics
    context.metrics().AddOperations(operations - 1);
    context.metrics().SetCustom("CRC", crc);
}

BENCHMARK_MAIN()
