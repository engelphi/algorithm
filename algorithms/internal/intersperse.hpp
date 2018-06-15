#pragma once

namespace algo {

namespace detail {
template <typename ForwardIterator, typename OutputIterator, typename T>
void prepend_to_all(ForwardIterator first, ForwardIterator last,
                    OutputIterator d_first, T sep) {
    while (first != last) {
        *d_first++ = sep;
        *d_first++ = *first++;
    }
}
} // namespace detail

template <typename ForwardIterator, typename OutputIterator, typename T>
void intersperse(ForwardIterator first, ForwardIterator last,
                 OutputIterator d_first, T sep) {
    if (first == last) {
        return;
    }

    *d_first++ = *first++;
    detail::prepend_to_all(first, last, d_first, sep);
}
} // namespace algo
