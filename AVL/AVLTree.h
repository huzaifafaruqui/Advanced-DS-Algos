#ifndef AVL_H
#define AVL_H
// https://en.wikipedia.org/wiki/Include_guard

#include <memory>

template <typename T>
class AVLTree {
 private:

  struct AVLNode;

  size_t count;

  std::shared_ptr<AVLNode> root;

  unsigned int getHeight(std::shared_ptr<AVLNode>& p) {
    if (p) return p->height;
    return 0;
  }

  std::shared_ptr<AVLNode> insert(T, std::shared_ptr<AVLNode>&);
  // https://stackoverflow.com/questions/10643563/how-to-return-smart-pointers-shared-ptr-by-reference-or-by-value
  void remove(std::shared_ptr<AVLNode>&);
  // shared pointers are heavy objects that should be passed by reference
  std::shared_ptr<AVLNode> search(T, std::shared_ptr<AVLNode>&);

  std::shared_ptr<AVLNode> extract_min(std::shared_ptr<AVLNode>&);

  void adjustBalanceFactors(std::shared_ptr<AVLNode>&,
                            std::shared_ptr<AVLNode>&);
  void rotateLeft(std::shared_ptr<AVLNode>&);
  void rotateRight(std::shared_ptr<AVLNode>&);
  void adjustLeftRight(std::shared_ptr<AVLNode>&, std::shared_ptr<AVLNode>&);
  void adjustRightLeft(std::shared_ptr<AVLNode>&, std::shared_ptr<AVLNode>&);
  void printInorder(std::ostream&, std::shared_ptr<AVLNode>&);

 public:
  AVLTree();
  ~AVLTree();

  AVLTree(AVLTree&&) = default;
  AVLTree& operator=(AVLTree&&) = default;
  AVLTree(const AVLTree&) = delete;  //disable copy constructor
  AVLTree& operator=(const AVLTree&) = delete;  //disable copy assignment

  bool insert(T);
  bool remove(T);
  unsigned int getHeight() { return getHeight(root); }
  bool search(T);
  size_t size() { return count; }
  // void restoreAVL(AVLTreeNode *ancestor, AVLTreeNode *newNode);

  template <class U>
  friend std::ostream& operator<<(std::ostream&, const AVLTree<U>&);
};

#include "AVLTree.cpp"

#endif