class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size();
        vector<int> hams;
        hams.push_back(-1);//to detect first two hamsters.
        for(int i=0;i<n;++i){
            if(hamsters[i]=='H'){
                hams.push_back(i);
            }
        }
        hams.push_back(n);//to detect last two hamsters.
        int count=0;
        for(int i=1;i<hams.size()-1;++i){
            int id_pr=hams[i-1];
            int id_nxt=hams[i+1];
            if(hams[i]-id_pr==1 && id_nxt-hams[i]==1){
                return -1;
            }
            if(id_nxt<n && id_nxt-hams[i]==2){
                i++;
            }
            count++;
        }
        return count;
    }
};