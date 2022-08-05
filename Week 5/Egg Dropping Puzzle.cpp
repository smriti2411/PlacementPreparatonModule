int dp[201][201];
   int solve(int n, int k){
       if (n==1){
           return k;
       }
       if (k==0){
           return 0;
       }
       if (dp[n][k]!=-1){
           return dp[n][k];
       }
       int ans=INT_MAX;
       for (int i=1; i<=k; i++){
           int broken=solve(n-1, i-1);
           int notbroken=solve(n, k-i);
           int maxi=max(broken, notbroken);
           ans=min(ans, maxi+1);
       }
       return dp[n][k]=ans;
   }
   //Function to find minimum number of attempts needed in 
   //order to find the critical floor.
   int eggDrop(int n, int k) 
   {
       // your code here
       for (int i=0; i<201; i++){
           for (int j=0; j<201; j++){
               dp[i][j]=-1;
           }
       }
       return solve(n, k);
   }