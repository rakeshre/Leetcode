class Solution {
public:
    string addBinary(string a, string b) {
        int al=a.size()-1;
        int bl=b.size()-1;
        int carry=0;
        string res="";
        while(al>=0 && bl>=0){
            int ac=a[al]-'0';
            int bc=b[bl]-'0';
            int sum=ac+bc+carry;
            char ch='0'+(sum%2);
            res+=ch;
            carry=(sum)/2;
            al--;
            bl--;
        }
        while(al>=0){
            int ac=a[al]-'0';
            int sum=ac+carry;
            char ch='0'+(sum%2);
            res+=ch;
            carry=(sum)/2;
            al--;
        }
        while(bl>=0){
            int bc=b[bl]-'0';
            int sum=bc+carry;
            char ch='0'+(sum%2);
            res+=ch;
            carry=(sum)/2;
            bl--;
        }
        if(carry){
            res+='0'+carry;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};