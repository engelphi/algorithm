/**
 * @file unzip.hpp
 */
#pragma once
#include <utility>

namespace algo {

/**
 * Unzips a range of pairs into two output ranges.
 * @tparam InputIterator The iterator type of the input range
 * @tparam OutputIterator1 The iterator type of the first output range.
 * @tparam OutputIterator2 The iterator type of the second output range.
 * @param first The start of the input range.
 * @param last The last element of the input range.
 * @param out1_first The start of the first output range.
 * @param out2_first The start of the second output range.
 * @return Returns a pair containing the past the last element iterators of the
 *         two output ranges
 */
template <typename InputIterator, typename OutputIterator1,
          typename OutputIterator2>
constexpr decltype(auto) unzip(InputIterator first, InputIterator last,
                               OutputIterator1 out1_first,
                               OutputIterator2 out2_first) {
    while (first != last) {
        (*out1_first++) = (*first).first;
        (*out2_first++) = (*first).second;
        first++;
    }
    return std::pair(out1_first, out2_first);
}

} // namespace algo
