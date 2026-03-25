class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long >rowsum(n);
        vector<long long >horsum(m);
        long long  totalsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowsum[i]+=grid[i][j];
                totalsum+=grid[i][j];

            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                horsum[j]+=grid[i][j];
            }
        }
        // now prefix of both
        vector<long long >prefix(n);
        prefix[0]=rowsum[0];
        for(int i=1;i<n;i++){
            prefix[i]=rowsum[i]+prefix[i-1];
        }
        vector<long long>prefixhor(m);
        prefixhor[0]=horsum[0];
        for(int i=1;i<m;i++){
            prefixhor[i]=horsum[i]+prefixhor[i-1];
        }
        // now we check all the splits of these 
        for(int i=0;i<n-1;i++){
            if(totalsum==(2*prefix[i])) return true;
        }
        for(int j=0;j<m-1;j++){
            if(totalsum==(2*prefixhor[j])) return true;
        }
        return false;
        
    }
};