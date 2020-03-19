#include <iostream>
using namespace std; 
#define min_i(a,b) (a<b)? (a):(b)    


template <class T>
class nodetree{
    public:
    T info;
    nodetree<T>*child[];
    nodetree<T>*brother;
    nodetree<T>*parents; //opcional
};

template <class T>
class nodeAVL{
    public:
    T info;
    nodeAVL<T> *left;
    nodeAVL<T> *right;
    int balances;
};

template<class T>
class nodeBtree{
    public:
    T info;
    nodeBtree<T> *left;
    nodeBtree<T> *right;
};

template <class T>
class gentree{
    nodetree<T> *root;
    public:
    gentree(){
        root=NULL;
    }
    ~gentree(){
    }
    nodetree<T>* getroot(){
        return root;
    }
    nodetree<T>* getchild(nodetree<T> *id){
        return id->child[0];
    }
    nodetree<T>* getbrother(nodetree<T> *id){
        return id->brother;
    }
    bool existbrother(nodetree<T> *id){
        if(id->brother!=NULL)
            return true;
        return false;    
    }
    T* getvalue(nodetree<T> *id){
        return id->info;
    }
    nodetree<T>* getparent(nodetree<T> *id){
        return id->parents;
    }
    bool isLeaf(nodetree<T> *id){
        if(id->child[0]==NULL)
            return true;
        return false;    
    }
    bool isEmpty(){
        return root== NULL;    
    }
    void insert(nodetree<T> *id){
        if(root==NULL)
            root=id;
        else{
            if(root->child[0]==NULL){
                root->child[0]=id;
                root->child[0]->parents=root;
            }else if(root->child[1]==NULL){
                root->child[1]=id;
                root->child[1]->parents=root;
            }else if(root->child[2]==NULL){
                root->child[2]=id;
                root->child[2]->parents=root;
            }else if(root->child[3]==NULL){
                root->child[3]=id;
                root->child[3]->parents=root;
            }
        }
    }
    void erase(nodetree<T> *id){
    }
    int level(nodetree<T> *id){
        int cont=0;
        nodetree<T> temp=getparent(id);
        while(temp!=NULL){
            temp=getparent(temp);
            ++cont; 
        }
        return cont;
    }
    int peso_preorden(nodetree<T> *root){
        if(isLeaf(root))
            return 1+(existbrother(root)?peso_preorden(getbrother(root)):0);
            else
            return 1+ peso_preorden(getchild(root));
    }
    int peso(gentree<T> *g){
        nodetree<T> *temp=g.getroot();
        return peso_preorden(temp);
    }
};

template <class T>
class binary{
    nodeBtree<T> *root;
    public:
    binary(){
        root=NULL;
    }
    ~binary(){
    }

    int contar(nodeBtree<T> *id){
        if(id==NULL)
            return 0;
        else
            return 1+contar(id->left)+contar(id->right);    
    }
    bool isLeaf(nodeBtree<T> *id){
        if(id->left==NULL and id->right==NULL)
            return true;
        return false;    
    }
    T* min(nodeBtree<T> *id){
        if(isLeaf(id))
            return id->info;
        else          
            return min_i(id->info,min_i(min(id->left),min(id->right)));
    }
    void preorder(nodeBtree<T> *id){
        if(id!=NULL){
            print(id);
            preorder(id->left);
            preorder(id->right);
        }
    }
    void postorden(nodeBtree<T> *id){
        if(id!=NULL){
            postorden(id->left);
            postorden(id->right);
            print(id);
        }
    }
    void inorden(nodeBtree<T> *id){
        if(id!=NULL){
            inorden(id->left);
            print(id);
            inorden(id->right);
        }
    }
    bool iguales(nodeBtree<T> *a,nodeBtree<T> *b){
        if(a==NULL and b==NULL){
            return true;
        }else if(a!= NULL and b!=NULL and a->info ==b->info){
            return iguales(a->left, b->left) and iguales(a->right,b->right);
        }else{
            return false;
        }
    }
};

template <class T>
class BinarySearchTree{
    nodeBtree<T> *root;
    public:
    BinarySearchTree(){
        root=NULL;
    }
    ~BinarySearchTree(){
    }
    nodeBtree<T>* getroot(){
        return root;
    }
    bool isEmpty(){
        if(root==NULL)
            return true;
        return false;    
    }
    nodeBtree<T>* lookup(nodeBtree<T> *id, T &info){
        if(id==NULL)
            return false;
        else if(id->info==info)
            return id;
        else if(id->info<info)
            return lookup(id->right, info);
        else if(id->info>info)
            return lookup(id->left, info);            
    }
    nodeBtree<T>* insert(nodeBtree<T> *id,T &info){
        nodeBtree<T> *aux= new nodeBtree<T>;
        aux->info=info;
        if(root==NULL){
            aux->right=NULL;
            aux->left=NULL;
            root=aux;
            return root;
        }else
            if(id->info<info)
                if(id->right==NULL)
                    id->right=aux;
                else
                    return insert(id->right, info);
                else if(id->info>info)
                        if(id->left==NULL)
                            id->left=aux;
                        else
                            return insert(id->left, info);
                        else
                            return id;
                        
            }                    
    void erase(nodeBtree<T> *id, T &info){
        nodeBtree<T> *aux=new nodeBtree<T>;
        aux=lookup(id,info);
        if(aux->left==NULL and aux->right==NULL){
            delete aux;
        }else if(aux->left!=NULL){
            T temp=delmin(aux->left);
            aux->info=temp;
        }else if(aux->right!=NULL){
            T temp=delmax(aux->right);
            aux->info=temp;
        }
    }
    T* delmin(nodeBtree<T> *id){
        if(id->right==NULL){
            T aux=id->info;
            delete id;
            return aux;
        }else{
            return delmin(id->right);
        }
    }
    T* delmax(nodeBtree<T> *id){
        if(id->left==NULL){
            T aux=id->info;
            delete id;
            return aux;
        }else{
            return delmax(id->left);
        }
    }

    nodeBtree<T>* getchildL(nodeBtree<T> *id){
        return id->left;
    }
    nodeBtree<T>* getchildR(nodeBtree<T> *id){
        return id->right;
    }
};

