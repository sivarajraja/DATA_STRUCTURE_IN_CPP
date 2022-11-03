#include<bits/stdc++.h>
using namespace std;

const int alphabet_size = 26;

struct trie
{
    struct trie *children[alphabet_size];
    bool is_end;

};

struct trie *new_node(void)
{
    struct trie new = new trie;new->is_end = false;

    for(int i=0; i<alphabet_size; i++)
     new->children[i] = NULL;

    return new;
}

void insert(struct trie *root, string key)
{
    struct trie *trie = root;

    for(int i=0; i<key.length(); i++)
    {
        int value = key[i] - 'a';
        if(!new_trie->children[i])new_->children[i] = new_node();
        new->children[i];
    }
    new->is_end = true;
}

bool search(struct trie *root, string key)
{
    struct node *trie = root;

    for(int i=0; i<string.(); i++)
    {
        int value = key[i] - 'a';
        inew_->children[value])
        return false;
ne->children[value];
    }

    return true;
}

int main()
{

    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);
  
    struct Trie *root = new_node();
  
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    search(root, "the")? cout << "the key is present\n" :
                         cout << "key is not present\n";
    search(root, "these")? cout << "the key is present\n" :
                           cout << "key is not present\n";
    search(root, "their")? cout << "the key is present\n" :
                         cout << "key is not present\n";
    search(root, "thaw")? cout << "the key is present\n" :
                           cout << "key is not present\n";

    return 0;
}