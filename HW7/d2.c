tree * findNode(tree *root, int key)
{
    //Если дерево пустое, выходим
    if(root == NULL)
        return NULL;

    //Если нашли искомый элемент, выходим
    if(root->key == key)
        return root;
    
    //Ищем элемент слева
    tree *left = findNode(root->left, key);
    if(left != NULL)
        return left;
    
    //Ищем элемент справа
    return findNode(root->right, key);
}

tree* findBrother(tree *root, int key)
{
    //Находим искомый узел
    tree *node = findNode(root, key);
    if(node == NULL)
        return NULL;

    //Если это корень, выходим
    tree *parent = node->parent;
    if(parent == NULL)
        return NULL;

    //Возвращаем соответствующего брата - левого или правого в зависимости от того, с какой стороны элемент
    if(parent->left == node)
        return parent->right;
    else
        return parent->left;
}
