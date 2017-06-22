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
        int balanceFactor;
        AVLNode() : data(), left(), right(), balanceFactor() {}
        AVLNode(T val) : data(val), left(), right(), balanceFactor() {}
    };
    size_t count = 0;
    std::shared_ptr<AVLNode> root;

    bool remove(T, std::shared_ptr<AVLNode>&);
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
