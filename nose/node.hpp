#ifndef _node_h_
#define _node_h_

#include <iostream>

template <class T>
class node {
    private:
        T info;
        node<T> *left;
        node<T> *right;
    public:
        node(){
            this->left = NULL;
            this->right = NULL;
        }
        node(T value){
           this->info = value;
        }
        ~node(){
        }
        void setInfo(T value){
            this->info = value;
        }
        void setLeftChild(node<T> *left){
            this->left = left;
        }
        void setRightChild(node<T> *right){
            this->right = right;
        }
        T getInfo(){
            return this->info;
        }
        node<T>* getLeftChild(){
            return this->left;
        }
        node<T>* getRightChild(){
            return this->right;
        }
};

#endif
