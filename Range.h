#ifndef RANGE_H
#define RANGE_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
class Range {
public:
    Range(T start, T end, T step = 1) : start(start), end(end), step(step) {

        if (step == 0){
            throw std::invalid_argument("step cannot be zero");

        }

        for (T value = start; (step > 0) ? 

            (value <= end) : (value >= end); value += step) {

            values.push_back(value);
        }
    }

        double average() const {
        if (values.empty()){

            throw std::runtime_error("cannot be average of empty range");

        }

        return static_cast<double>(sum()) / length();
    }


    int length() const {

        return values.size();

    }

    T sum() const {

        return std::accumulate(values.begin(), values.end(), T(0));

    }

    T max() const {
        if (values.empty()){ 

            throw std::runtime_error("cannot be the max of empty range");

        }

        return *std::max_element(values.begin(), values.end());
    }

    T min() const {

        if (values.empty()){

            throw std::runtime_error("cannot be the min of empty range");

        }

        return *std::min_element(values.begin(), values.end());
    }


    friend std::ostream& operator<<(std::ostream& os, const Range& range) {

        for (const auto& value : range.values) {
            os << value << " ";
        }
        return os;

    }

private:
    T start, end, step;
    std::vector<T> values;
};

#endif