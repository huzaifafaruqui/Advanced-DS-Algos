
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

    unsigned int hr = getheight(p->right);
    unsigned int hl = getheight(p->left);

    p->height = std::max(hr, hl) + 1;


    return p;
}
