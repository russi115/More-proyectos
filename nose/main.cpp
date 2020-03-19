#include "BST.hpp"

int main() {
    BST<int> tree;

    tree.insert(11);
    tree.insert(6);
    tree.insert(8);
    tree.insert(19);
    tree.insert(4);
    tree.insert(10);
    tree.insert(5);
    tree.insert(17);
    tree.insert(21);

    std::cout << "Buscando el 30: " << tree.lookup(30) << std::endl;

    std::cout << "Preorden: ";
    tree.preorder();
    std::cout << std::endl;

    std::cout << "Inorden: ";
    tree.inorder();
    std::cout << std::endl;

    std::cout << "Postorden: ";
    tree.postorder();
    std::cout << std::endl;

    // tree.erase(5);
    // tree.erase(17);
    // tree.erase(4);
    // tree.erase(19);

    std::cout << "Buscando el 11: " << tree.lookup(11) << std::endl;
    tree.erase(11);
    std::cout << "Elimino el 11." << std::endl;
    std::cout << "Buscando el 11: " << tree.lookup(11) << std::endl;

    std::cout << "Inorden: ";
    tree.inorder();
    std::cout << std::endl;

    return 0;
}
