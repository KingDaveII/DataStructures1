//
//  SplayTree.h
//  DataStructuresHW1
//
//  Created by DAVID KOPLEVATSKII & GERBORII ELNIKOV on 28/11/2017.
//  Copyright © 2017 DAVID KOPLEVATSKII & GERBORII ELNIKOV . All rights reserved.
//


#ifndef SplayTree_h
#define SplayTree_h

template <class T>
class SplayTree{

private:
    struct SplayTreeNode{
        int key;
        T value;
        SplayTreeNode *left;
        SplayTreeNode *right;
        SplayTreeNode *daddy;
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




public:


    SplayTree(): root(nullptr){}

    ~SplayTree() {
        delSubTree(root);
    }
}
#endif /* SplayTree_h */
