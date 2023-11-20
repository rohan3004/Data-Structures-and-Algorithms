/*Copyright© 2023 Rohan Chakaravarty
This header file contains Binray Search Tree:
    -> Insertion in Binary Search Tree
    -> Deletion in Binray Search Tree
    -> Tree Traversal:
        -> Inorder
        -> Preorder
        -> Postorder
    -> Returns Kth Smallest Element
    -> Returns Kth Largest Element
    

This is opensource project and feel free contribute*/


#ifndef BST_H
#define BST_H

template <class T>
class Node{
    public:
    T data;
    Node* left;
    Node* right;
    Node(T d):data(d),left(nullptr),right(nullptr){}
};

template <typename T>
class BST{
    Node<T>* root;
    Node<T>* insert(Node<T>* root, T data)
    {
        if(root==nullptr)
            return new Node<T>(data);

        if(data<root->data)
        root->left=insert(root->left,data);
        else if(data>root->data)
        root->right=insert(root->right,data);

        return root;    
    }
    Node<T>* find_Min(Node<T>* node)//inorder successor
    {
        while(node->left!=nullptr)
            node=node->left;
        
        return node;
    }
    Node<T>* remove(Node<T>* node, T data)
    {
        if(node==nullptr)
            return nullptr;

        //find the node according to the value
        if(data<node->data)
        node->left=remove(node->left,data);
        else if(data>node->data)
        node->right=remove(node->right,data);
        else{
            //Node to be deleted found

            //Case 1: No child or one child
            if(node->left==nullptr)
            {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right==nullptr)
            {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            //Case 2: Two children
            Node<T>* temp = find_Min(node->right);
            node->data=temp->data;
            node->right = remove(node->right,temp->data);//finding the node which is inorder successor and then deleting it
        }
        return node;
    }
    void inOrder(Node<T>* root)
    {
        if(root)
        {
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
    void preOrder(Node<T>* root)
    {
        if(root)
        {
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void postOrder(Node<T>* root)
    {
        if(root)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    void kth_smallest(Node<T>* root, int& c,int pos)
    {
        if(root)
        {
            kth_smallest(root->left,c,pos);
            c++;
            if(c==pos)
                cout<<root->data;
            kth_smallest(root->right,c,pos);
        }
    }
    void kth_largest(Node<T>* root, int& c,int pos)
    {
        if(root)
        {
            kth_largest(root->right,c,pos);
            c++;
            if(c==pos)
                cout<<root->data;
            kth_largest(root->left,c,pos);
        }
    }
    public:
    BST():root(nullptr){}
    void insert(T data)
    {
        root=insert(root,data);
    }
    void remove(T data)
    {
        root=remove(root,data);
    }
    void inorder()
    {
        inOrder(root);
        cout<<endl;
    }
    void preorder()
    {
        preOrder(root);
        cout<<endl;
    }
    void postorder()
    {
        postOrder(root);
        cout<<endl;
    }
    void kth_largest(int pos)
    {
        int c=0;
        kth_largest(root,c,pos);
        cout<<endl;
    }
    void kth_smallest(int pos)
    {
        int c=0;
        kth_smallest(root,c,pos);
        cout<<endl;
    }
    ~BST()
    {
        delete root;
    }
};

#endif