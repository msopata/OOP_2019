#include "Small.h"
#include "BenchIncludes.h"

void smallLessOperator(State& state){
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        auto result = a < b;
    }
}

BENCHMARK(smallLessOperator);

void smallEqualOperator(State& state){
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _: state){
        auto result = a == b;
    }
}

BENCHMARK(smallEqualOperator);

void smallHashFunction(State& state){
    Small a{};
    a.randomize();
    std::hash<Small> hash;
    for(auto _: state){
        auto result = hash(a);
    }
}

BENCHMARK(smallHashFunction);