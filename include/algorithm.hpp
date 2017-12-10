#pragma once

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

}  // namespace algo
