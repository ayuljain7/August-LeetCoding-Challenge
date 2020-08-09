class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int orange=0,count=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>0)
                {
                    orange++;
                    if(grid[i][j]==2)
                    {
                        orange--;
                        q.push(make_pair(i,j));
                    }
                }
            }
        }
        while(!q.empty())
        {
            //cout<<q.size()<<" ";
            count++;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                 pair<int,int> p=q.front();
                 q.pop();
                 if(p.first<grid.size()-1 && grid[p.first+1][p.second]==1)
                 {
                     orange--;
                     q.push(make_pair(p.first+1,p.second));
                     grid[p.first+1][p.second]=2;
                 }
                if(p.second<grid[p.first].size()-1 && grid[p.first][p.second+1]==1)
                 {
                     orange--;
                     q.push(make_pair(p.first,p.second+1));
                    grid[p.first][p.second+1]=2;
                 }
                if(p.first>0 && grid[p.first-1][p.second]==1)
                 {
                     orange--;
                     q.push(make_pair(p.first-1,p.second));
                    grid[p.first-1][p.second]=2;
                 }
                 if(p.second>0 && grid[p.first][p.second-1]==1)
                 {
                     orange--;
                     q.push(make_pair(p.first,p.second-1));
                     grid[p.first][p.second-1]=2;
                 }
            }
        }
        if(orange==0)
        {
            return max(count,0);
        }
        return -1;
    }
};