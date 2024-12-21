/**
 * @file cs19_template_practice.h
 * @author A student in CS 19, someone@jeff.cis.cabrillo.edu
 *
 * Definitions of two function templates for as03.
 */
 
// Guard to prevent multiple inclusion
// See: https://google.github.io/styleguide/cppguide.html#The__define_Guard
#ifndef CS19_TEMPLATE_PRACTICE_H_
#define CS19_TEMPLATE_PRACTICE_H_
 
#include <iterator>  // You may want to use functions from this library header
 
// Anything defined within this block becomes part of namespace `cs19`:
namespace cs19 {
    
/**
 * Determines whether an iterable object contains elements in palindromic order,
 * i.e. the same values are encountered while iterating both forward and backward.
 *
 * @tparam BidirectionallyIterableContainer a type offering bidirectional iterators,
 *          e.g. `std::string`, `std::vector`, `std::list`, with elements that are
 *          mutually comparable for equality
 * @see https://cplusplus.com/reference/iterator/BidirectionalIterator/
 *
 * @param data the container to inspect
 * @return whether `data` contains elements in palindromic order
 */
// this function is now case senstive and returns true for empty strings
template <typename BidirectionallyIterableContainer>
bool is_palindromic(const BidirectionallyIterableContainer &data) {
  typename BidirectionallyIterableContainer::const_iterator left = data.begin();
  typename BidirectionallyIterableContainer::const_iterator right = data.end();
  if (data.empty() || data.size() == 1) { return true; }
  while (left != data.end() && right != data.begin()) {
    --right;
    if (*right != *left) return false;
    ++left;
    if (left == right) break;
  }
  return true;
}
 
/**
 * Iterates over two sequences in parallel, producing a sequence of the same type
 * with elements alternating from each of the input sequences.
 *
 * @tparam Sequence any iterable sequence that is default-constructible
 *         (i.e. `Sequence()` constructs an empty such object) and offers a standard
 *         `push_back()` function, e.g. `std::string`, `std::vector`, `std::list`
 *
 * @param a the first input sequence
 * @param b the second input sequence
 * @return a new sequence consisting of elements appended alternately from `a` and `b`, respectively
 *         until both input sequences are exhausted and inserted into the result
 */
template <typename Sequence>
Sequence zip(const Sequence &a, const Sequence &b) {
  Sequence result;
  typename Sequence::const_iterator itr_a = a.begin();
  typename Sequence::const_iterator itr_b = b.begin();

  while (itr_a != a.end() || itr_b != b.end()) {
    if (itr_a != a.end()) {
      result.push_back(*itr_a);
      ++itr_a;
    }
    if (itr_b != b.end()) {
      result.push_back(*itr_b);
      ++itr_b;
    }
  }
  return result;
}
 
}  // namespace cs19
 
#endif  // CS19_TEMPLATE_PRACTICE_H_