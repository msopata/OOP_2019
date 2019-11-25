#include "Medium.h"
#include "BenchIncludes.h"

void mediumLessOperator(State& state){
    Medium a{};
    Medium b{};
    a.randomize();
    for(int i = 0; i < Medium::SIZE - 1; i++)
        b.data[i] = a.data[i];

    b.data[Medium::SIZE - 1] = a.data[Medium::SIZE - 1] + 1;

    for(auto _ : state){
        auto result = a < b;
    }
}

BENCHMARK(mediumLessOperator);

void mediumEqualOperator(State& state){
    Medium a{};
    Medium b{};
    a.randomize();

    for(int i = 0; i < Medium::SIZE; i++)
        b.data[i] = a.data[i];

    for(auto _: state){
        auto result = a == b;
    }
}

BENCHMARK(mediumEqualOperator);

void mediumHashFunction(State& state){
    Medium a{};
    a.randomize();
    std::hash<Medium> hash;
    for(auto _: state){
        auto result = hash(a);
    }
}

BENCHMARK(mediumHashFunction);
