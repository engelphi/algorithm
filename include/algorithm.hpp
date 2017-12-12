#pragma once
#include <iterator>
#include <type_traits>
#include <utility>

namespace algo {

template <typename InputIterator, typename OutputIterator, typename UnaryOp,
          typename Pred>
OutputIterator transform_if(InputIterator first, InputIterator last,
                            OutputIterator d_first, UnaryOp unary_op,
                            Pred predicate) {
    while (first != last) {
        if (predicate(*first)) {
            *d_first++ = unary_op(*first++);
        } else {
            *d_first++ = *first++;
        }
    }
    return d_first;
}

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
