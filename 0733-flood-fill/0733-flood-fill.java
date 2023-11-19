class Solution {
    
    void fill(int i, int j, int[][] image, int srcColor, int color, int n, int m) {
        // boundary check
        
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != srcColor) return; //tata
        
        // change color
        image[i][j] = color;
        
        fill(i+1, j , image, srcColor, color, n,m);
        fill(i-1, j , image, srcColor, color, n,m);
        fill(i, j+1 , image, srcColor, color, n,m);
        fill(i, j-1 , image, srcColor, color, n,m);

    }
    
    
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length;
        int m = image[0].length;
        
        int srcColor = image[sr][sc];
        if (srcColor == color) return image;
        
        fill(sr,sc,image, srcColor, color, n, m);
        
        return image;
    }
}