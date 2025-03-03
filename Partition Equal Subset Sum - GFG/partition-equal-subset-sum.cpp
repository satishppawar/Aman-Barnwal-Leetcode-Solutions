//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
        
    int knapsack(int a[], int n, int target) {
    
        // Using DP
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    
    
        // Base Condition
        for(int i=0; i<=n; i++)                     dp[i][0] = 1;
        for(int j=1; j<=target; j++)                dp[0][j] = 0;
    
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=target; j++) {
    
                if(a[i-1] <= j)                     dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
                else                                dp[i][j] = dp[i-1][j];
            }
        }
    
    
        return dp[n][target];
    }

    int equalPartition(int n, int a[]) {
        
        int sum = 0;
        
        for(int i=0; i<n; i++)                      sum += a[i];

        if(sum % 2 != 0)                            return 0;
        
        return knapsack(a, n, sum / 2);
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends