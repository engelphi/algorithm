/**
 * @file transform_if.hpp
 */
#pragma once

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

} // namespace algo
