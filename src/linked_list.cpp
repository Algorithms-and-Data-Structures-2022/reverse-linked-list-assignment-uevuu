#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    // Напишите здесь свой код ...
    if (size_ <= 0) {
      return;
    }
    Node* prev_node = nullptr;
    Node* node = front_;
    Node* next_node = node->next;
    while (next_node != nullptr) {
      node->next = prev_node;
      prev_node = node;
      node = next_node;
      next_node = next_node->next;
    }
    node->next = prev_node;
    Node* front_copy = front_;
    front_ = back_;
    back_ = front_copy;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    // Напишите здесь свой код ...
    if (size_ <= 0) {
      return;
    }
    reverse_recursive_helper(front_->next, front_);
    front_->next = nullptr;
    Node* front_copy = front_;
    front_ = back_;
    back_ = front_copy;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    // Напишите здесь свой код ...
    if (curr == nullptr) {
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
