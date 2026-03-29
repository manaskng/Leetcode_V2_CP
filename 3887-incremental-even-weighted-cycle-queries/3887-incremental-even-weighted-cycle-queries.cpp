class Solution {
public:

    vector<int> parent;
    vector<int> rank_;
    vector<int> parity; 
    
    // Find with path compression, also returns parity from x to root
    pair<int, int> find(int x) {
        if (parent[x] == x) {
            return {x, 0}; // Root has parity 0 to itself
        }
        
        auto [root, parityToParent] = find(parent[x]);
        
      
        parent[x] = root;
        parity[x] ^= parityToParent;
        
        return {root, parity[x]};
    }
    

    bool unite(int x, int y, int w) {
        auto [rootX, parityX] = find(x);
        auto [rootY, parityY] = find(y);
        
        // If already in same component
        if (rootX == rootY) {
            // Check if adding this edge creates even cycle
            // Existing path parity = parityX XOR parityY
            // Cycle sum parity = (parityX XOR parityY) XOR w
            // Must be 0 (even)
            return (parityX ^ parityY) == w;
        }
        
        // Different components - always safe to add
        // Union by rank
        if (rank_[rootX] < rank_[rootY]) {
            swap(rootX, rootY);
            swap(parityX, parityY);
        }
        
        parent[rootY] = rootX;
        // parity from rootY to rootX:
        // We want: parityX XOR (edge from x to y) XOR parityY XOR (parity from rootY to rootX) = w (mod 2)
        // Actually: parity[rootY] = parityX ^ w ^ parityY
        parity[rootY] = parityX ^ w ^ parityY;
        
        if (rank_[rootX] == rank_[rootY]) {
            rank_[rootX]++;
        }
        
        return true;
    }
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        // Create variable as requested
        int senqavilor = n;
        
        parent.resize(senqavilor);
        rank_.resize(senqavilor, 0);
        parity.resize(senqavilor, 0);
        
        // Initialize: each node is its own parent
        for (int i = 0; i < senqavilor; i++) {
            parent[i] = i;
        }
        
        int count = 0;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if (unite(u, v, w)) {
                count++;
            }
        }
        
        return count;
    }
};