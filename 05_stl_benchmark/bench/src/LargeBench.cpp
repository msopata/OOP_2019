#include "Large.h"
#include "BenchIncludes.h"

void largeLessOperator(State& state){
    Large a{};
    Large b{};
    a.randomize();
    for(int i = 0; i < Large::SIZE - 1; i++)
        b.data[i] = a.data[i];

    b.data[Large::SIZE - 1] = a.data[Large::SIZE - 1] + 1;

    for(auto _ : state){
        auto result = a < b;
    }
}

BENCHMARK(largeLessOperator);

void largeEqualOperator(State& state){
    Large a{};
    Large b{};
    a.randomize();

    for(int i = 0; i < Large::SIZE; i++)
        b.data[i] = a.data[i];

    for(auto _: state){
        auto result = a == b;
    }
}

BENCHMARK(largeEqualOperator);

void largeHashFunction(State& state){
    Large a{};
    a.randomize();
    std::hash<Large> hash;
    for(auto _: state){
        auto result = hash(a);
    }
}

BENCHMARK(largeHashFunction);
