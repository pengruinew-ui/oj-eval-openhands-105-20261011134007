#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[i] represents the expected number of days to eat m apples starting with i apples
    // But we need to track how many apples have been eaten so far
    // Let's define dp[i][j] = expected days to eat j more apples when we have i apples currently
    
    // Since we need to eat exactly m apples, and we start with n apples
    // We'll use dp[i][j] where i is current apple count, j is remaining apples to eat
    
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));
    
    // Base case: if we need to eat 0 more apples, we need 0 days
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0.0;
    }
    
    // Fill the DP table
    // We need to be careful about the order of iteration
    // For each number of apples to eat (from 1 to m)
    for (int eat = 1; eat <= m; eat++) {
        // For each current apple count (from eat to n)
        // We can't have fewer apples than we need to eat
        for (int curr = eat; curr <= n; curr++) {
            double expected = 0.0;
            // On this day, we can eat k apples (1 <= k <= curr)
            // But we can't eat more than 'eat' apples since we only need to eat 'eat' more
            int max_eat_today = min(curr, eat);
            
            for (int k = 1; k <= max_eat_today; k++) {
                // After eating k apples, we have curr-k apples left
                // And we still need to eat eat-k more apples
                expected += (1.0 / curr) * (1 + dp[curr - k][eat - k]);
            }
            
            // If we can eat more than we need today, we have additional cases
            // where we eat more than needed, but we only count the days until we've eaten exactly 'eat' apples
            // Actually, we should stop once we've eaten the required amount
            // So if curr > eat, we can also eat more than 'eat' in one day
            if (curr > eat) {
                // We can eat any amount from eat+1 to curr
                // In these cases, we eat enough to reach our target in one day
                for (int k = eat + 1; k <= curr; k++) {
                    expected += (1.0 / curr) * 1.0; // Just 1 day, since we eat enough
                }
            }
            
            dp[curr][eat] = expected;
        }
    }
    
    // We start with n apples and need to eat m apples
    cout << fixed << setprecision(2) << dp[n][m] << endl;
    
    return 0;
}