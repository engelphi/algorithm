#pragma once

namespace algo {
template <typename InputIterator, typename OutputIterator, typename Pred>
void span(InputIterator first, InputIterator last, OutputIterator a_first,
          OutputIterator b_first, Pred pred) {
    while (first != last) {
        if (pred(*first)) {
            *a_first++ = *first++;
        } else {
            *b_first++ = *first++;
        }
    }
}
} // namespace algo
