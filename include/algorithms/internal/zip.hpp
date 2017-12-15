#pragma once
#include <utility>

namespace algo {

template <typename InputIterator1, typename InputIterator2,
          typename OutputIterator>
OutputIterator zip(InputIterator1 first_a, InputIterator1 last_a,
                   InputIterator2 first_b, OutputIterator out) {
    while (first_a != last_a) {
        *out++ = std::pair(*first_a++, *first_b++);
    }
    return out;
}

} // namespace algo
