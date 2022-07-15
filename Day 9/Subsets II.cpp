vector<vector<int>> result;
    set<vector<int>>s;
    void solve(vector<int>nums, vector<int> temp){
        if(nums.size()==0){
            s.insert(temp);
            return;
        }
        vector<int>op1;
        vector<int>op2;
        op1 = temp;
        op2 = temp;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums, op1);
        solve(nums, op2);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp);
        for(auto i:s){
            result.push_back(i);
        }
        return result;  
    }