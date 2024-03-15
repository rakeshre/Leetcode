class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int sz=arr.size();
        
        vector<string> ans;
        for(int k=0;k<sz;++k){
            string min="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            string x=arr[k];
            int n=x.size();
            for(int i=1;i<=n;++i){
                if(min!="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"){
                    break;
                }
                for(int j=0;j<=n-i;++j){
                    string str=x.substr(j,i);
                    int ct=0;
                    for(int l=0;l<sz;++l){
                        if(l!=k){
                            if(arr[l].find(str)!=string::npos){
                                ct++;
                            }
                        }
                    }
                    if(ct==0){
                        if(str.size()<min.size()){
                            min=str;
                        }else if(str.size()==min.size()){
                            if(str<min){
                                min=str;
                            }
                        }
                    }
                }
            }
            if(min=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"){
                ans.push_back("");
            }else{
                ans.push_back(min);
            }
        }
        return ans;
    }
};