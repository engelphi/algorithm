/**
 * @file algorithm.hpp
 */
#pragma once
#include <iterator>
#include <type_traits>
#include <utility>

namespace algo {

/**
 * Transforms the elements of the input range if the predicate is evaluates to
 * true. The resulting elements are stored to the output range.
 * @tparam InputIterator The type of the input iterator.
 * @tparam OutputIterator The type of the output iterator.
 * @tparam UnaryOp The type of transformation function.
 * @tparam Pred The type of the predicate function.
 * @param first The start of input range.
 * @param last The end of the input range.
 * @param d_first The start of the output range.
 * @param unary_op The transformation function.
 * @param predicate The predicate function.
 * @return Returns an iterator to past the last element of the output range
 */
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

/**
 * Zips the elements of the two input ranges together into a single output
 * range which contains pairs of the elements of both ranges.
 * @tparam InputIterator1 The type of the input iterator of the first range.
 * @tparam InputIterator2 The type of the input iterator of the second range.
 * @tparam OutputIterator The of type the output iterator.
 * @param first_a The start of the first input range.
 * @param last_a The end of the first input range.
 * @param first_b The start of the second input range.
 * @param out The start of the output range.
 * @return Returns an iterator to past the last element of the output range
 */
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
