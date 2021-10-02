#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    vector<TrieNode *> children;
    char c;

public:
    TrieNode(){};
    TrieNode(char ch) : c(ch){};
    // getters
    char getChar() { return this->c; }
    vector<TrieNode *> getChildren() { return this->children; }

    // setters
    void setChar(char c) { this->c = c; }
    void insertChildren(TrieNode *c) { this->children.push_back(c); }

    // utility
    TrieNode *checkIfCharacterIsInChild(int c)
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            if (children.at(i)->c == c)
            {
                return children.at(i);
            }
        }
        return nullptr;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(nullptr) {}
    void insertString(string s)
    {
        TrieNode *t = this->root;
        if (this->root == nullptr)
        {
            this->root = new TrieNode(' ');
            t = this->root;
            for (int i = 0; i < (int)s.size(); i++)
            {
                TrieNode *new_node = new TrieNode(s[i]);
                t->insertChildren(new_node);
                t = new_node;
            }
            return;
        }
        else if (this->root->checkIfCharacterIsInChild(s[0]) != nullptr)
        {
            int i;
            for (i = 0; i < (int)s.size(); i++)
            {
                TrieNode *child_node = t->checkIfCharacterIsInChild(s[i]);
                if (child_node == nullptr)
                {
                    break;
                }
                else
                {
                    t = child_node;
                }
            }
            if (i == s.size())
            {
                return;
            }
            else
            {
                for (int j = i; j < (int)s.size(); j++)
                {
                    TrieNode *new_node = new TrieNode(s[j]);
                    t->insertChildren(new_node);
                    t = new_node;
                }
            }
            return;
        }
        else
        {
            for (int i = 0; i < (int)s.size(); i++)
            {
                TrieNode *new_node = new TrieNode(s[i]);
                t->insertChildren(new_node);
                t = new_node;
            }
            return;
        }
    }
    void PrintTrie()
    {
        if (this->root == nullptr)
        {
            cout << "Empty Trie!!\n";
        }
        else
        {
            TrieNode *t = this->root;
            queue<TrieNode *> q;
            q.push(t);
            while (!q.empty())
            {
                t = q.front();
                cout << t->getChar() << " ";
                q.pop();
                vector<TrieNode *> children = t->getChildren();
                for (int i = 0; i < (int)children.size(); i++)
                {
                    q.push(children.at(i));
                }
            }
        }
    }
    bool checkWord(string s)
    {
        if (this->root == nullptr)
            return false;
        else
        {
            TrieNode *t = this->root;
            for (int i = 0; t != nullptr && i < (int)s.size(); i++)
            {
                t = t->checkIfCharacterIsInChild(s[i]);
                if (t == nullptr)
                {
                    return false;
                }
            }
            return true;
        }
    }
    TrieNode *getNextNode(TrieNode *prev, char c)
    {
        if (prev == nullptr)
            return prev;
        return prev->checkIfCharacterIsInChild(c);
    }
};
void leaveLines(int n)
{
    while (n--)
        cout << "\n";
}
int main()
{
    Trie trie;
    int opt;
    cout << "Trie Data Structure : ";
    leaveLines(2);
    while (true)
    {
        cout << "Options : 1] Store Word   2] Check For Word  3] Print  4] Exit \n";
        cout << "Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            string word;
            cout << "Enter Word : ";
            cin >> word;
            if (trie.checkWord(word))
            {
                cout << "Word Already Exists!\n";
            }
            else
            {
                trie.insertString(word);
                cout << "Word inserted successfully!!\n";
            }
            break;
        }
        case 2:
        {
            string word;
            cout << "Enter Word : ";
            cin >> word;
            if (trie.checkWord(word))
            {
                cout << "Word Found!\n";
            }
            else
            {
                cout << "Word Not Found!!\n";
            }
            break;
        }
        case 3:
        {
            cout << "Level Order Trie Traversal : ";
            trie.PrintTrie();
            cout << "\n";
            break;
        }
        case 4:
        {
            cout << "Thank You!!\n";
            return 0;
        }
        default:
        {
            cout << "Invalid Input Provided !!\n\n";
            break;
        }
        }
    }

    return 0;
}