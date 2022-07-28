 TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        return help(nums, 0, (int)nums.size() - 1, root);
    }
    TreeNode* help(vector<int> nums, int L, int R, TreeNode* root) {
        if (L > R) return nullptr;
        int mid = L + (R - L) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = help(nums, L, mid - 1, node);
        node->right = help(nums, mid + 1, R, node);
        return node;
    }