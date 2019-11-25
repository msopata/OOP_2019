#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        int i = 0;

        while( this->data[i] == rhs.data[i] )
            i++;

        return this->data[i] < rhs.data[i];
    }

    bool operator==(const Medium &rhs) const {
        bool isEqual = false;
        int i = 0;
        while( this->data[i] == rhs.data[i] )
        {
            if(i == SIZE)
                isEqual = true;
            i++;
        }
        return isEqual;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {
            int hashRes = 0;
            int i = 0;
            for(const int& val: d.data)
                hashRes += val * i++;

            return hashRes;
        }
    };
}