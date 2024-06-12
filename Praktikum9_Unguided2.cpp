//Muhammad Dani Ayubi_2311102003
#include <iostream> 
using namespace std;
struct Pohon 
{ 
    char data; 
    Pohon *left, *right, *parent; 
}; 
 
Pohon *root, *baru; 
 
void init() 
{ 
    root = NULL; 
} 
 
int isEmpty() 
{ 
    if (root == NULL) 
        return 1; 
    else 
        return 0; 
} 
 
void buatNode(char data) 
{ 
    if (isEmpty() == 1) 
    { 
        root = new Pohon(); 
        root->data = data; 
        root->left = NULL; 
        root->right = NULL; 
        root->parent = NULL; 
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl; 
    } 
    else 
    { 
        cout << "\n Pohon sudah dibuat" << endl; 
    } 
} 
 
Pohon *insertLeft(char data, Pohon *node) 
{ 
    if (isEmpty() == 1) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return NULL; 
    } 
    else 
    { 
        if (node->left != NULL) 
        { 
            cout << "\n Node " << node->data << " sudah memiliki child kiri!" 
<< endl; 
            return NULL; 
        } 
        else 
        { 
            baru = new Pohon(); 
            baru->data = data; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node; 
            node->left = baru; 
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl; 
           
            return baru; 
        } 
    } 
} 
 
Pohon *insertRight(char data, Pohon *node) 
{ 
    if (root == NULL) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return NULL; 
    } 
    else 
    { 
        if (node->right != NULL) 
        { 
            cout << "\n Node " << node->data << " sudah memiliki child kanan!" 
<< endl; 
            return NULL; 
        } 
        else 
        { 
            baru = new Pohon(); 
            baru->data = data; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node; 
            node->right = baru; 
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan" << baru->parent->data << endl; 
            return baru; 
        } 
    } 
} 
 
void update(char data, Pohon *node) 
{ 
    if (isEmpty() == 1) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } 
    else 
    { 
        if (!node) 
            cout << "\n Node yang ingin diganti tidak ada!" << endl; 
        else 
        { 
            char temp = node->data; 
            node->data = data; 
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data 
<< endl; 
        } 
    } 
} 
 
void retrieve(Pohon *node) 
{ 
    if (!root) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } 
    else 
    { 
        if (!node) 
            cout << "\n Node yang ditunjuk tidak ada!" << endl; 
        else 
        { 
            cout << "\n Data node: " << node->data << endl; 
        } 
    } 
} 
 
void find(Pohon *node) 
{ 
    if (!root) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } 
    else 
    { 
        if (!node) 
            cout << "\n Node yang ditunjuk tidak ada!" << endl; 
        else 
        { 
            cout << "\n Data Node: " << node->data << endl; 
            cout << " Root: " << root->data << endl; 
            if (!node->parent) 
                cout << " Parent: (tidak punya parent)" << endl; 
            else 
                cout << " Parent: " << node->parent->data << endl; 
            if (node->parent != NULL && node->parent->left != node && 
                node->parent->right == node) 
                cout << " Sibling: " << node->parent->left->data << endl; 
            else if (node->parent != NULL && node->parent->right != node && 
                     node->parent->left == node) 
                cout << " Sibling: " << node->parent->right->data << endl; 
            else 
                cout << " Sibling: (tidak punya sibling)" << endl; 
            if (!node->left) 
                cout << " Child Kiri: (tidak punya Child kiri)" << endl; 
            else 
                cout << " Child Kiri: " << node->left->data << endl; 
            if (!node->right) 
                cout << " Child Kanan: (tidak punya Child kanan)" << endl; 
            else 
                cout << " Child Kanan: " << node->right->data << endl; 
        } 
    } 
} 
 
void preOrder(Pohon *node = root) 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        if (node != NULL) 
        { 
            cout << " " << node->data << ", "; 
            preOrder(node->left); 
            preOrder(node->right); 
        } 
    } 
} 
 
void inOrder(Pohon *node = root) 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        if (node != NULL) 
        { 
            inOrder(node->left); 
            cout << " " << node->data << ", "; 
            inOrder(node->right); 
        } 
    } 
} 
 
void postOrder(Pohon *node = root) 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        if (node != NULL) 
        { 
            postOrder(node->left); 
            postOrder(node->right); 
            cout << " " << node->data << ", "; 
        } 
    } 
} 
 
void deleteTree(Pohon *node) 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        if (node != NULL) 
        { 
            if (node != root) 
            { 
                node->parent->left = NULL; 
                node->parent->right = NULL; 
            } 
            deleteTree(node->left); 
            deleteTree(node->right); 
            if (node == root) 
            { 
                delete root; 
                root = NULL; 
            } 
            else 
            { 
                delete node; 
            } 
        } 
    } 
} 
 
void deleteSub(Pohon *node) 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        deleteTree(node->left); 
        deleteTree(node->right); 
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << 
endl; 
    } 
} 
 
void clear() 
{ 
    if (!root) 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    else 
    { 
        deleteTree(root); 
        cout << "\n Pohon berhasil dihapus." << endl; 
    } 
} 
 
int size(Pohon *node = root) 
{ 
    if (!root) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return 0; 
    } 
    else 
    { 
        if (!node) 
        { 
            return 0; 
        } 
        else 
        { 
            return 1 + size(node->left) + size(node->right); 
        } 
    } 
} 
 
int height(Pohon *node = root) 
{ 
    if (!root) 
    { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return 0; 
    } 
    else 
    { 
        if (!node) 
        { 
            return 0; 
        } 
        else 
        { 
            int heightKiri = height(node->left); 
            int heightKanan = height(node->right); 
            if (heightKiri >= heightKanan) 
            { 
                return heightKiri + 1; 
            } 
            else 
            { 
                return heightKanan + 1; 
            } 
        } 
    } 
} 
 
void characteristic() 
{ 
    cout << "\n Size Tree: " << size() << endl; 
    cout << " Height Tree: " << height() << endl; 
    cout << " Average Node of Tree: " << size() / height() << endl; 
} 
 
int main() 
{ 
    int choice; 
    char data; 
    init(); 
    cout << "PROGRAM BINARY TREE" << endl; 
    while (true) 
    { 
        cout << "\nMenu:" << endl; 
        cout << "1. Buat Node Baru" << endl; 
        cout << "2. Tambah Kiri" << endl; 
        cout << "3. Tambah Kanan" << endl; 
        cout << "4. Ubah Data Tree" << endl; 
        cout << "5. Lihat Isi Data Tree" << endl; 
        cout << "6. Cari Data Tree" << endl; 
        cout << "7. Penelusuran Pre-order" << endl; 
        cout << "8. Penelusuran In-order" << endl; 
        cout << "9. Penelusuran Post-order" << endl; 
        cout << "10. Hapus Node Tree" << endl; 
        cout << "11. Hapus SubTree" << endl; 
        cout << "12. Hapus Tree" << endl; 
        cout << "13. Karakteristik Tree" << endl; 
        cout << "14. Keluar" << endl; 
        cout << "Pilihan: "; 
        cin >> choice; 
        switch (choice) 
        { 
        case 1: 
            cout << "\nMasukkan data untuk root: "; 
            cin >> data; 
            buatNode(data); 
            break; 
        case 2: 
            cout << "\nMasukkan data baru: "; 
            cin >> data; 
            insertLeft(data, root); 
            break; 
        case 3: 
            cout << "\nMasukkan data baru: "; 
            cin >> data; 
            insertRight(data, root); 
            break; 
        case 4: 
            cout << "\nMasukkan data yang ingin diubah: "; 
            cin >> data; 
            update(data, root); 
            break; 
        case 5: 
            retrieve(root); 
            break; 
        case 6: 
            find(root); 
            break; 
        case 7: 
            cout << "\nPenelusuran Pre-order: "; 
            preOrder(root); 
            cout << endl; 
            break; 
        case 8: 
            cout << "\nPenelusuran In-order: "; 
            inOrder(root); 
            cout << endl; 
            break; 
        case 9: 
            cout << "\nPenelusuran Post-order: "; 
            postOrder(root); 
            cout << endl; 
            break; 
        case 10: 
            deleteTree(root); 
            cout << "\nPohon berhasil dihapus." << endl; 
            break; 
        case 11: 
            deleteSub(root); 
            break; 
        case 12: 
            clear(); 
            break; 
        case 13: 
            characteristic(); 
            break; 
        case 14: 
            return 0; 
        default: 
            cout << "\nInput salah, silakan masukkan pilihan yang benar!" << 
endl; 
        } 
    } 
    return 0; 
} 