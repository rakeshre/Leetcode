class Node{
    public:
   Node *children[26]; //ptr to 26 nodes.
    bool isEnd;
    Node(){
        //children=new Node[26];
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
        isEnd=false;
    }
};
class Trie {
    Node *root; //root is trie, so type must be node.
public:
    
    Trie() {
        root=new Node(); //init root with node
    }
    
    void insert(string word) {
        Node *p=root;
        for(auto &ch:word){
            int i=ch-'a';
            if(p->children[i]==nullptr){ // this condition is important because of override.
                 p->children[i]=new Node(); //access ith childrem like this
            }
           
            p=p->children[i];
        }
        p->isEnd=true;
    }
    
    bool search(string word, bool prefix=false) {
        Node *iter=root;
        for(auto &ch:word){
            int i=ch-'a';
            if(iter->children[i]==nullptr){
                return false;
            }
            iter=iter->children[i];
        }
        if(prefix==true){
            return true;
        }
        return iter->isEnd;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */