class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        vector<string> v;
        while(getline(ss, s, ' ')){
            v.push_back(s);
        }
        for(int i=0;i<v.size();++i){
            string word=v[i];
            int n=word.size();
            int r_n=searchWord.size();
            if(n<r_n){
                continue;
            }
            if(word.substr(0,r_n)==searchWord){
                return i+1;
            }
        }
        return -1;
    }
};