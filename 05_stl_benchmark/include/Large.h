#pragma once

#include <random>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{};

        for (double &i : data) {
            i = dis(gen);
        }
    }

    bool operator<(const Large &rhs) const {

        int i = 0;

        while( this->data[i] == rhs.data[i] )
            i++;

        return this->data[i] < rhs.data[i];
    }

    bool operator==(const Large &rhs) const {

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
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {

            int hashRes = 0;
            int i = 0;
            for(const int& val: d.data)
                hashRes += val * i++;

            return hashRes;
        }
    };
}
