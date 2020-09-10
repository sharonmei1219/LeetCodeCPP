class Solution {
public:
    int numTrees(int n) {
        vector<int> numOfTrees(n+1, 0);
        numOfTrees[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < i; k++){
                numOfTrees[i] += numOfTrees[k] * numOfTrees[i-k-1];
            }
        }
        return numOfTrees[n];
    }
};