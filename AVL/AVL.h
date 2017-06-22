#ifndef AVL_H
#define AVL_H
//https://en.wikipedia.org/wiki/Include_guard

#include <memory>



template<typename T>
class AVLTree
{
private:
    struct AVLNode
    {
        T data;
        std::shared_ptr<AVLNode> left;
        std::shared_ptr<AVLNode> right;
        unsigned int height;
        AVLNode() : data(), left(), right(), height() {}
        AVLNode(T val) : data(val), left(), right(), height() {}
    };
    size_t count = 0;
    std::shared_ptr<AVLNode> root;
    int getHeight(std::shared_ptr<AVLNode>& p)
    {
        if(p)
            return p->height;
        return 0;
    }

    std::shared_ptr<AVLNode> insert(T, std::shared_ptr<AVLNode>&);
    //https://stackoverflow.com/questions/10643563/how-to-return-smart-pointers-shared-ptr-by-reference-or-by-value
    bool remove(T, std::shared_ptr<AVLNode>&);
    //shared pointers are heavy objects that should be passed by reference
    std::shared_ptr<AVLNode> find(T, std::shared_ptr<AVLNode>&);
    void adjustBalanceFactors(std::shared_ptr<AVLNode>&, std::shared_ptr<AVLNode>&);
    void rotateLeft(std::shared_ptr<AVLNode>&);
    void rotateRight(std::shared_ptr<AVLNode>&);
    void adjustLeftRight(std::shared_ptr<AVLNode>&, std::shared_ptr<AVLNode>&);
    void adjustRightLeft(std::shared_ptr<AVLNode>&, std::shared_ptr<AVLNode>&);
    
public:
    AVLTree():root(){}
    ~AVLTree() {
        //while(root)
          //  remove(root->data);
    }
    AVLTree(AVLTree&&) = default;
    AVLTree& operator =(AVLTree&&) = default;
    AVLTree(const AVLTree&);
    AVLTree& operator =(const AVLTree&);
    bool insert(T);
    bool remove(T);
    void inorder();
    bool search(T x) {
        return !(find(x, root)==nullptr);
    }
    size_t size(){
        return count;
    }
    //void restoreAVL(AVLTreeNode *ancestor, AVLTreeNode *newNode);
    
    template<class U>
    friend std::ostream& operator<<(std::ostream&, const AVLTree<U>& );

};



#include "AVLTree.cpp"

#endif