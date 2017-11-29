//
//  SplayTree.h
//  DataStructuresHW1
//
//  Created by DAVID KOPLEVATSKII & GERBORII ELNIKOV on 28/11/2017.
//  Copyright © 2017 DAVID KOPLEVATSKII & GERBORII ELNIKOV . All rights reserved.
//


#ifndef SplayTree_h
#define SplayTree_h

template <class T, class Key>
class SplayTree{

private:
    struct SplayTreeNode{
        Key key;
        T value;
        SplayTreeNode *left;
        SplayTreeNode *right;
        SplayTreeNode *daddy;
        
        SplayTreeNode(T val,Key k): key(k), value(val),
        left(nullptr), right(nullptr), daddy(nullptr) {}
    };
    SplayTreeNode* root;


    void delSubTree(SplayTreeNode* node){
        if (node == NULL){
            return NULL;
        }
        delSubTree(node->left);
        delSubTree(node->right);
        delete node;
    }

    SplayTreeNode* my_zig(SplayTreeNode* node, SplayTreeNode* p){
        if (!node)
            throw NULL_PTR;
        if (node->daddy != p)
            throw INVALID_INPT;
        if (!node->daddy)
            return;

        if (p->left == node) {
            p->left = node->right;
            node->right = node->daddy;
        }
        else{
            p->right = node->left;
            node->left = node->daddy;
        }
        node->daddy = p->daddy;
        return node;
    }

    void Zig(SplayTreeNode* node){
        my_zig(node, note->daddy);
        this->root = node;
    }

    void ZigZig(SplayTreeNode* node){
        SplayTreeNode* p = node->daddy;
        SplayTreeNode* g = p->daddy;
        my_zig(p, g);
        my_zig(node, p);
    }

    void ZigZag(SplayTreeNode* node){
        SplayTreeNode* p = node->daddy;
        SplayTreeNode* g = p->daddy;
        if (g->left == p)        +        (g->left == p ? g->left : g->right ) = my_zig(node, p);
            g->left = my_zig(node, p);
        else
            g->right = my_zig(node, p);        my_zig(node, g);
        if (this->root = g)
            this->root = node;
    }
    
    void SplayOne(SplayTreeNode* node){
        if (node != root) {
            if (node->daddy == root) {
                Zig(node);
            } else {
                if ((node == node->daddy->left) && (node->daddy == node->daddy->daddy->left)) {
                    ZigZig(node);
                } else {
                    if ((node == node->daddy->right) && (node->daddy == node->daddy->daddy->left)){
                        ZigZag(node);
                    }
                }
            }
        }
    }
    
    void join(SplayTree* t1, SplayTree* t2){
        t1->findMax();
        t1->root->right=t2->root;
    }

    void split(Key k, SplayTree** t1, SplayTree** t2){
        this->find();
        SplayTree* t1_new = new SplayTree;
        SplayTree* t2_new = new SplayTree;
        t1_new->root = this->root;
        t2_new->root = this->root->right;
        t1_new->root->right = nullptr;
        *t1 = t1_new;
        *t2 = t2_new;
    }
    
    
    
    
    
    
    SplayTreeNode* recFind(const Key key, SplayTreeNode* root){
        if (root->key == key)
            return root;

        if (root->key < key){
            if (root->left)
                Splay(recFind(key, root->left)->daddy) ;
            else
                Splay(root);
        }
        else{
            if (root->right)
                Splay(recFind(key, root->right)->daddy);
            else
                Splay(root);
            }
            return root;
        }
    
    
    
    
    
    SplayTreeNode* recFindMin(SplayTreeNode* root){
        if (root->left)
            Splay(recFind(key, root->left)->daddy) ;
        else
            Splay(root);
            return root;
    }

    SplayTreeNode* recFindMax(SplayTreeNode* root){
        if (root->right)
            Splay(recFind(key, root->right)->daddy) ;
        else
            Splay(root);
        return root;
    }

    
    
public:


    SplayTree(): root(nullptr){}

    ~SplayTree() {
        delSubTree(root);
    }
    
    
    
    
    
    
    T* find(const Key key){
        this->root = recFind(key, this->root);
        return this->root->value;
    }

    T* findMin(){
        this->root = recFindMin(this->root);
        return this->root->value;
    }

    T* findMax(){
        this->root =  recFindMin(this->root);
        return this->root->value;
    }

    void insert(const Key i, const T val){
        SplayTree *tmp1 = new SplayTree;
        SplayTree *tmp2 = new SplayTree;
        this->split(i, &tmp1, &tmp2);

        delSubTree(this->root);
        SplayTreeNode* node = new SplayTreeNode(i, val);
        this->root = node;

        join(this, tmp2);
        join(tmp1, this);

        delete tmp1;
        delete tmp2;
    }

    void del(Key i){
        find(i);
        SplayTree *tmpTree1 = new SplayTree;
        SplayTree *tmpTree2 = new SplayTree;
        this->split(i, &tmpTree1, &tmpTree2);

        SplayTreeNode* tmp = tmpTree1->root->left;
        tmp->daddy = nullptr;
        delete tmpTree1->root;
        tmpTree1->root = tmp;

        delete tmpTree1;
        delete tmpTree2;

    }
}
#endif /* SplayTree_h */
