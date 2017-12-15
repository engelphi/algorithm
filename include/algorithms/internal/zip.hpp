/**
 * @file zip.hpp
 */
#pragma once
#include <utility>

namespace algo {

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
