class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char> vowels{'a','e','i','o','u'};
        int ct=0;
        for(int i=left;i<=right;++i){
            auto word=words[i];
            int e=word.size()-1;
            if(vowels.find(word[0])!=vowels.end() && vowels.find(word[e])!=vowels.end()){
                ct+=1;
            }
        }
        return ct;
    }
};