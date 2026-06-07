class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> isChild;

        for(auto& d : descriptions){
            int par = d[0], kid = d[1], isLeft = d[2];

            // create parent if not exists
            if(mpp.find(par) == mpp.end())
                mpp[par] = new TreeNode(par);

            // create child if not exists
            if(mpp.find(kid) == mpp.end())
                mpp[kid] = new TreeNode(kid);

            // attach child to parent
            if(isLeft)
                mpp[par]->left  = mpp[kid];
            else
                mpp[par]->right = mpp[kid];

            isChild.insert(kid); // kid can't be root
        }

        // root = node that never appeared as a child
        for(auto& [val, node] : mpp)
            if(isChild.find(val) == isChild.end())
                return node;

        return nullptr;
    }
};