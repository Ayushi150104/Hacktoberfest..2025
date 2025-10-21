class Solution {
public:
    int f(int i, int n, vector<int> &dp, vector<vector<bool>> &isPal) {
        if(i == n) return 0; 
        if(dp[i] != -1) return dp[i];
        int min_cost = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPal[i][j]) {
                int cost = 1 + f(j + 1, n, dp, isPal);
                min_cost = min(min_cost, cost);
            }
        }
        return dp[i] = min_cost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 1 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        vector<int> dp(n, -1);
        return f(0, n, dp, isPal) - 1;
    }
};
