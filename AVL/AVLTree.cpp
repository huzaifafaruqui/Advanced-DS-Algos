
template<typename T>
bool AVLTree<T>::insert(T val)
{
    if(insert(val, root))
        return true;
    return false;
}

template<typename T>
std::shared_ptr<typename AVLTree<T>::AVLNode> AVLTree<T>::insert(T val, std::shared_ptr<AVLNode>& p)
{
    //https://stackoverflow.com/questions/30287402/c-nested-class-in-class-template-declaration
    if(p == nullptr)
    {
        p = std::make_shared<AVLNode>(val);
    }

    else if(val < p->data)
    {
        p->left = insert(val, p->left);
    }

    else if(val > p->data)
    {
        p->right = insert(val, p->right);
    }


    return p;
}


template<typename T>
bool AVLTree<T>::search(T val) 
{
    if(search(val, root))
        return true;
    return false;
}


template<typename T>
std::shared_ptr<typename AVLTree<T>::AVLNode> AVLTree<T>::search(T val, std::shared_ptr<AVLNode>& p)
{
    if(p == nullptr || p->data == val)
    {
        return p;
    }

    else if(val < p->data)
    {
        return search(val, p->left);
    }

    return search(val, p->right);

}


template<typename T>
std::shared_ptr<typename AVLTree<T>::AVLNode> AVLTree<T>::extract_min(std::shared_ptr<AVLNode>& p)
{
    if(p->left) //make sure p!=nullptr
    {
        return extract_min(p->left);
    }

    return p;

}


template<typename T>
bool AVLTree<T>::remove(T val) 
{
    auto temp = search(val, root);
    if(temp)
    {
        remove(temp);
        return true;
    }
    return false;
}


template<typename T>
void AVLTree<T>::remove(std::shared_ptr<AVLNode>& p)
{
    if(p->left == nullptr)
    {
        p = std::move(p->right);
        //https://stackoverflow.com/questions/41871115/why-would-i-stdmove-an-stdshared-ptr
    }

    else if(p->right == nullptr)
    {
        p = std::move(p->left);
    }

    else
    {
        auto temp = extract_min(p->right);
        p->data = temp->data;
        remove(temp);
    }


}

template<typename T>
void printInorder(std::ostream& out, std::shared_ptr<typename AVLTree<T>::AVLNode>& p)
{
    if(p)
    {
        printInorder(out, p->left);
        out << p->data;
        printInorder(out, p->right);
    }
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const AVLTree<T>& A) //TODO
{
    A.printInorder(out, A.root);
    return out;
}