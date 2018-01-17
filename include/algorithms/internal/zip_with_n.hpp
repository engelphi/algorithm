#pragma once

namespace algo {

/**
 * Zips the element of two input ranges together into an output range
 * by applying the given binary operation to the elements.
 * @ŧparam InputIterator1 The type of input iterator of the first range.
 * @ŧparam InputIterator2 The type of input iterator of the second range.
 * @tparam OutputIterator The type of the output iterator.
 * @tparam Size The size type for the count parameter.
 * @tparam BinOp The type of the binary operation which is applied to the
 * elements of the input ranges
 * @param first_a The start of the first range.
 * @param first_b The start of the second range.
 * @param out The start of the output range.
 * @param cnt The number of elements to be zipped.
 * @param bin_op The binary operation which should be applied.
 * @return Returns an iterator to past the last element of the output range
 */
template <typename InputIterator1, typename InputIterator2,
          typename OutputIterator, typename Size, typename BinOp>
OutputIterator zip_with_n(InputIterator1 first_a, InputIterator2 first_b,
                          OutputIterator out, Size cnt, BinOp bin_op) {
    if (cnt > 0) {
        *out++ = bin_op(*first_a, *first_b);
        for (Size i = 1; i < cnt; ++i) {
            *out++ = bin_op(*++first_a, *++first_b);
        }
    }
    return out;
}

} // namespace algo
