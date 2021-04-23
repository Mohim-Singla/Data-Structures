//insert delete function of trie data structure.
#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

struct Trinode
{
public:
    char data;
    int we;
    Trinode *child[26];

    Trinode()
    {
        we=0;
        for (int i=0;i<26;i++)
        {
            this->child[i]=NULL;
        }
    }
    explicit Trinode(char data)
    {
        this->data=data;
        we=0;
        for (int i=0;i<26;i++)
        {
            this->child[i]=NULL;
        }
    }
};

struct Trinode* insert(Trinode* root, string s)
{
    Trinode* curr=root;
    for (int i=0;i<s.size();i++)
    {


        int loc=s[i]-'a';
        if (curr->child[loc]==NULL)
        {
            Trinode* temp= new Trinode(char(s[i]));
            curr->child[loc]=temp;
        }
        curr=curr->child[loc];

    }
    curr->we=1;
    cout<<s<<" added to the dictionary successfully."<<endl;
    return root;
}

struct Trinode* del(Trinode* root, string s)
{
    Trinode* curr=root;
    for (int i=0;i<s.size();i++)
    {
        int loc=s[i]-'a';
        if (curr->child[loc]==NULL)
        {
            cout<<s<<": Word not found."<<endl;
            return root;
        }
        curr=curr->child[loc];
        if (i==s.size()-1)
        {
            if (curr->we==0)
            {
                cout<<s<<": Word not found."<<endl;
                break;
            }
            curr->we=0;
            cout<<s<<": deleted successfully."<<endl;
        }
    }
    return root;
}

int main()
{
    struct Trinode* root=new Trinode;
    string s = "aabcab";
    root = insert(root, s);
    s="aabder";
    root = insert(root, s);
    s="afgrfder";
    root = insert(root, s);
    s="aabdghfc";
    root = insert(root, s);
    s="aabdghfcdsw";
    root = insert(root, s);
    s="bder";
    root = insert(root, s);
    s="bderfr";
    root = insert(root, s);
    s="abdehjur";
    root = insert(root, s);

    s="aabdghfc";
    del(root, s);
    s="aahghc";
    del(root, s);
    s="aabdghfc";
    del(root, s);
    return 0;
}
