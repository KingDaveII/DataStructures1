//
//  SplayTree.h
//  DataStructuresHW1
//
//  Created by DAVID KOPLEVATSKII on 28/11/2017.
//  Copyright © 2017 DAVID KOPLEVATSKII. All rights reserved.
//

#ifndef SplayTree_h
#define SplayTree_h

template <class T>
class SplayTree{
    
    
    struct SplayTreeNode{
    T value;
    SplayTreeNode *left;
    SplayTreeNode *right;
    SplayTreeNode *dad;
    }
    
    void delSubTree(SplayTreeNode* node){
        if (node == NULL){
            return NULL;
        }
        delSubTree(node->left);
        delSubTree(node->right);
        delete node;
    }
    
    
    
    
    SplayTreeNode* root;
    
public:
    SplayTree() {
        root = NULL;
    }
    ~SplayTree() {
       delSubTree(root);
    }
}
#endif /* SplayTree_h */
