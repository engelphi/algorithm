#pragma once
#include <tuple>

namespace algo {
template <typename OutputIterator, typename InputIterator,
          typename... InputIterators>
OutputIterator zip_n(OutputIterator out, InputIterator first,
                     InputIterator last, InputIterators &&... args) {
    while (first != last) {
        *out++ = std::tuple(*first++, *args++...);
    }
    return out;
}
} // namespace algo
