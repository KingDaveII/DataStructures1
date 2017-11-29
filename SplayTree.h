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
        (g->left == p ? g->left : g->right ) = my_zig(node, p);
        my_zig(node, g);
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

public:
    

    SplayTree(): root(nullptr){}

    ~SplayTree() {
        delSubTree(root);
    }
}
#endif /* SplayTree_h */
