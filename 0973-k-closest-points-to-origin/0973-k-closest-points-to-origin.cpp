class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>minheap;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int dis=x*x+y*y;
            minheap.push({dis,{x,y}});
        }
        // remove till k left 
        int kth=0;
        vector<vector<int>>ans;
        while(minheap.size()>0&&kth<k){
            auto p=minheap.top();
            minheap.pop();
            auto c=p.second;
            vector<int>curr;
            curr.push_back(c.first);
            curr.push_back(c.second);
            ans.push_back(curr);
            kth++;
        }
        return ans;
    }
};