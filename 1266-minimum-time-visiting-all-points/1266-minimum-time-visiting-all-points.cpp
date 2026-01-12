class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int totalsteps=0;
        for(int i=0;i<n-1;i++){
            int absx=abs(points[i][0]-points[i+1][0]);
            int absy=abs(points[i][1]-points[i+1][1]);
            if(absx==absy){
                totalsteps+=absx;
                continue;
            }
            else{
                int mini=min(absx,absy);
                totalsteps+=mini;
                totalsteps+=absx>absy?absx-mini:absy-mini;
            }
        }
        return totalsteps;
        
    }
};