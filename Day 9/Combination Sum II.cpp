 void helper(int i, vector<int> &candidates, int target, int sum, vector<int> &subset, vector<vector<int>> &ans){
        if(sum==target){
            ans.push_back(subset);
            return;
        }
        if(sum>target) return;
        if(i==candidates.size())return;
        
        sum+=candidates[i];
        subset.push_back(candidates[i]);
        helper(i+1, candidates, target, sum, subset, ans);
        subset.pop_back();
        sum-=candidates[i];
       
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        helper(i+1, candidates, target, sum, subset, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(0,candidates,target,0,subset,ans);
        return ans;
    }