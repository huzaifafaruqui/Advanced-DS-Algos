// file AVLTree.h:
#ifndef AVL_H
#define AVL_H
// https://en.wikipedia.org/wiki/Include_guard

#include <memory>

template <typename T>
class AVLTree {
 private:
  struct AVLNode;

  std::shared_ptr<AVLNode> root = nullptr;

  unsigned getHeight(std::shared_ptr<AVLNode>& p) const {
    if (p) return p->height;
    return 0;
  }

  std::shared_ptr<AVLNode> insert(const T&, std::shared_ptr<AVLNode>&);
  // https://stackoverflow.com/questions/10643563/how-to-return-smart-pointers-shared-ptr-by-reference-or-by-value
  bool remove(std::shared_ptr<AVLNode>&, const T&);
  // shared pointers are heavy objects that should be passed by reference
  std::shared_ptr<AVLNode> search(const T&, std::shared_ptr<AVLNode>&);

  std::shared_ptr<AVLNode> extract_min(std::shared_ptr<AVLNode>&);

  void adjustBalanceFactors(std::shared_ptr<AVLNode>&, const T& val);
  std::shared_ptr<AVLNode> rotateLeft(std::shared_ptr<AVLNode>&);
  std::shared_ptr<AVLNode> rotateRight(std::shared_ptr<AVLNode>&);
  void printInorder(std::ostream&, std::shared_ptr<AVLNode>) const;

 public:
  ~AVLTree() = default;

  // disable copy&move constructor/assignmenet
  AVLTree(AVLTree&&) = delete;
  AVLTree& operator=(AVLTree&&) = delete;
  AVLTree(const AVLTree&) = delete;
  AVLTree& operator=(const AVLTree&) = delete;

  bool insert(const T&);
  bool remove(const T&);
  unsigned getHeight() const { return getHeight(root); }
  bool search(const T&);
  size_t size() const { return count; }
  // void restoreAVL(AVLTreeNode *ancestor, AVLTreeNode *newNode);

  template <class U>
  friend std::ostream& operator<<(std::ostream&, const AVLTree<U>&);
};

#include "AVLTree.cpp"

#endif  // AVLTREE_H