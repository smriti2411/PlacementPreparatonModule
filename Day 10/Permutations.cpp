void solve(vector<int> nums,int i,vector<vector<int>> &ans){
       
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            solve(nums,i+1,ans);
            //backtrack
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;
        solve(nums,i,ans);
        return ans;
    }