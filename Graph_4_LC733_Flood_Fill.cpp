class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m = image[0].size();
        vector<vector<int>> ans(image);
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int i_c = image[sr][sc];
        queue<pair<int,int>> q;
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1};
        q.push({ sr,sc });
        vis[sr][sc] = true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            ans[row][col] = color;
            q.pop();
            for(int i = 0;i < 4;i++){
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && image[r][c]==i_c){
                    vis[r][c] = true;
                    q.push({ r,c });
                }
            }
        }
        return ans;
    }
};