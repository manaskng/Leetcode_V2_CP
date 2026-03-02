class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trail(n);

        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j) {
                count++;
            }
            trail[i] = count;
        }

        int steps = 0;
        vector<bool> used(n, false);

       
        for (int i = 0; i < n; ++i) {
            int req = n - 1 - i; 
            int bestIdx = -1;

            
            for (int j = 0; j < n; ++j) {
                if (!used[j] && trail[j] >= req) {
                    bestIdx = j;
                    break;
                }
            }

            if (bestIdx == -1) return -1; 

            
            steps += countUnusedBefore(bestIdx, used);
            used[bestIdx] = true;
        }

        return steps;
    }

private:
   
    int countUnusedBefore(int idx, const vector<bool>& used) {
        int count = 0;
        for (int i = 0; i < idx; ++i) {
            if (!used[i]) count++;
        }
        return count;
    }
};