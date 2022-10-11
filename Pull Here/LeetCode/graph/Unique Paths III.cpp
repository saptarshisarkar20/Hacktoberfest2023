#define sz(x) int(x.size())
vector<vector<int>>grid2;
vector<vector<bool>>visited;
int n , m;
int startsi,startsj;
int empty_cnt_l = 0,empty_cnt_g = 0;
bool is_valid(int i , int j)
{
    return i >= 0 && i < n && j >=0 && j < m &&  grid2[i][j] != -1 && (!visited[i][j]); 
}

int rec2(int r ,int c)
{
    if(!is_valid(r , c))
        return 0;
        
    
    if(grid2[r][c] == 2)
               return empty_cnt_l == empty_cnt_g;
    
    visited[r][c] = 1;
    empty_cnt_l++;
    int ans = rec2(r , c + 1) + rec2(r , c - 1) + rec2(r + 1 , c) + rec2(r - 1 ,c); 
    empty_cnt_l-- ,visited[r][c] = 0;
    return ans;
}
class Solution {
    public:
    int uniquePathsIII(vector<vector<int>>& grid){
        n = sz(grid),m=sz(grid[0]);
        empty_cnt_l = 0,empty_cnt_g = 0;
        grid2.assign(n,vector<int>(m,0));

        grid2 = grid;

        visited.assign(n,vector<bool>(m,0));

        grid2=grid;

        for(int i = 0 ; i < n;i++)
        {
            for(int  j = 0 ; j < m ;j++)
            {
                if(grid[i][j] == 1)
                    startsi =i,startsj = j;

                else if(grid[i][j] == 0)
                        empty_cnt_g++;
            }
        }
        empty_cnt_g++;
        //cout_2d(grid2);
       return rec2(startsi, startsj);
    }
};