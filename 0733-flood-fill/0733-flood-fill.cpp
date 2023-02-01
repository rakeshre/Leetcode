class Solution {
public:
    void fill_n(vector<vector<int>>& image, int color, int a, int b, int pc){
        if(a<0 || a>=image.size()){
            return;
        }
        if(b<0 || b>=image[0].size()){
            return;    
        }
        if(image[a][b]!=pc){ //why?
            return;
        }
        image[a][b]=color;
        fill_n(image,color,a+1,b,pc);
        fill_n(image,color,a-1,b,pc);
        fill_n(image,color,a,b+1,pc);
        fill_n(image,color,a,b-1,pc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int pc=image[sr][sc];
        if(color==pc){
            return image;
        }
        fill_n(image,color,sr,sc,pc);
        return image;
    }
};