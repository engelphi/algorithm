#pragma once

namespace algo {
template <typename InputIterator, typename OutputIteratorA,
          typename OutputIteratorB, typename Pred>
constexpr void span(InputIterator first, InputIterator last,
                    OutputIteratorA a_first, OutputIteratorB b_first,
                    Pred pred) {
    while (first != last) {
        if (pred(*first)) {
            *a_first++ = *first++;
        } else {
            *b_first++ = *first++;
        }
    }
}
} // namespace algo
