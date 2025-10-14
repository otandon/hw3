#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm> // for swap

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void bubble_up(size_t index);
  void trickle_down(size_t index);
  std::vector<T> data_;
  size_t m_;
  PComparator comp_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : data_(), m_(static_cast<size_t>(m < 2 ? 2 : m)), comp_(c) {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data_.push_back(item);
  bubble_up(data_.size() - 1);
}

template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
  if (empty()) throw std::underflow_error("top of empty heap");
  return data_.front();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if (empty()) throw std::underflow_error("pop on empty heap");
  std::swap(data_.front(), data_.back());
  data_.pop_back();
  if (!empty()) trickle_down(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::bubble_up(size_t index) {
  while (index > 0) {
    size_t parent = (index - 1) / m_;
    if (comp_(data_[index], data_[parent])) {
      std::swap(data_[index], data_[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_down(size_t index) {
  while (true) {
    size_t priority = index;
    size_t firstChild = m_*index + 1;
    for (size_t k = 0; k < m_; k++) {
      size_t child = firstChild + k;
      if (child >= data_.size()) break;
      if (comp_(data_[child], data_[priority])) {
        priority = child;
      }
    }
    if ((priority == index)) break;
    std::swap(data_[index], data_[priority]);
    index = priority;
  }
}


#endif

