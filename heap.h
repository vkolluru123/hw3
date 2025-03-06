#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  ~Heap();

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
  std::vector<T> myHeap_;
  int m_;
  PComparator comparator_;
  void heapifyUp(unsigned int idx) {
    if (idx==0) {
      return;
    }
    else {
      unsigned int parent = (idx-1)/m_;
      if (comparator_(myHeap_[idx],myHeap_[parent])) {
        std::swap(myHeap_[idx],myHeap_[parent]);
        heapifyUp(parent);
      }
    }
  }
  void heapifyDown(unsigned int idx) {
    unsigned int myIdx = idx;
    unsigned int childone = m_*idx+1;
    for ( int i = 0; i < m_; i++) {
      unsigned int childIdx = childone+i;
      if (childIdx < myHeap_.size() && comparator_(myHeap_[childIdx],myHeap_[myIdx])) {
        myIdx=childIdx;
      }
    }
    if (myIdx != idx) {
      std::swap(myHeap_[idx],myHeap_[myIdx]);
      heapifyDown(myIdx);
    }
  }

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator comp) : m_(m),comparator_(comp) {}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){};

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{return myHeap_.empty();}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {return myHeap_.size();}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  myHeap_.push_back(item);
  heapifyUp(myHeap_.size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else {
    return myHeap_.front();
  }

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap empty");

  }
  else {
    std::swap(myHeap_.front(),myHeap_.back());
    myHeap_.pop_back();
    if (!myHeap_.empty()) {
      heapifyDown(0);
    }
  }

}

#endif

