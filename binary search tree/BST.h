#include<iostream>
#include<stack>
#include<stdexcept>

template<class T>
class BinarySearchTree{


    struct Node{
        T data;
        Node *left;
        Node *right;
        Node(const T& val): data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t count;
    void print(std::ostream& = std::cout) const;
    Node* find(const T&);
public:
    //BinarySearchTree(const BinarySearchTree<T>&);
   // BinarySearchTree& operator=(BinarySearchTree<T>);
    BinarySearchTree(): root(nullptr), count(0) {}
    BinarySearchTree(Node *node): root(node), count(0) {}
    //~BinarySearchTree();
    size_t size() const;
    const T& Min();
    const T& Max();
    bool search(const T&);
    
    BinarySearchTree<T>& insert(const T&);
    size_t remove(const T&);
    template<class U>
    friend std::ostream& operator<<(std::ostream&, const BinarySearchTree<U>& );
};


template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::find(const T& val)
{
    //https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    Node *temp = root;
    bool found = false;
    while(temp)
    {
        if(val==temp->data)
        {
            found = true;
            break;
        }
        else if(val>temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if(found)
        return temp;
    return nullptr;
}


/*template<class T>
size_t BinarySearchTree<T>::remove(const T& val)
{
    Node *temp = find(val);
    
    if(temp==nullptr)
        return count;

    if(temp->left==nullptr && temp->right==nullptr)
    {
        temp = nullptr;
    }
}
*/

template<class T>
const T& BinarySearchTree<T>::Min() //TODO
{
    if(!count)
    {
        throw std::runtime_error("Empty Binary search tree");
    }

    Node *temp = root;

    while(temp->left)
    {
        temp = temp->left;
    }

    return temp->data;
}


template<class T>
const T& BinarySearchTree<T>::Max()
{
    
    if(!count)
    {
        throw std::runtime_error("Empty Binary search tree");
    }

    Node *temp = root;
    
    while(temp->right)
    {
        temp = temp->right;
    }

    return temp->data;
}

template<class T>
size_t BinarySearchTree<T>::size() const
{
    return count;
}

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::insert(const T& val)
{
    //This functions returns a reference so that I can allow chaining of insert function

    Node *temp = root, *prev = nullptr;
    bool exists = false;

    while(temp)
    {
        prev = temp;
        if(temp->data>val)
            temp = temp->left;
        else if(temp->data==val)
        {
            exists = true;
            break;
        }
        else
            temp = temp->right;
    }

    if(exists){
        return *this;
    }

    if(prev==nullptr)
    {
        root = new Node(val);
    }
    else if(prev->data>val)
    {
        prev->left = new Node(val);
    }
    else
    {
        prev->right = new Node(val);
    }

    count++;
    return *this;
}

template<class T>
bool BinarySearchTree<T>::search(const T& val)
{
    Node *result = find(val);

    if(result==nullptr)
        return false;
    return true;
}

template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
    std::stack<Node *> st;
    Node *temp = root;

    while(temp || !st.empty())
    {
        if(temp)
        {
            st.push(temp);
            temp = temp->left;
        }

        else
        {
            temp = st.top();
            st.pop();
            out<<temp->data<<" ";
            temp = temp->right;
        }
    }

}

template<class T>
std::ostream& operator<<(std::ostream& out, const BinarySearchTree<T>& BST)
{
    BST.print(out);
    return out;
}
