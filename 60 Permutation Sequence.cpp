class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n - 1, 1);
        k = k - 1;
        vector<int> candidate;
        for(int i = 0; i < n; i++){
            candidate.push_back(i+1);
        }
        string result;
        for(int i = 1; i < n - 1; i++){
            fact[i] = fact[i-1] * (i+1);
        }

        for(int i = 0; i < n-1; i ++){
            const int index = k/fact[n-i-2];
            // cout << fact[n-i-2] << index;
            k = k%fact[n-i-2];
            result = result + to_string(candidate[index]);
            candidate.erase(candidate.begin() + index);
        }
        result = result + to_string(candidate[0]);
        return result;
    }
};