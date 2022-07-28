vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        	 vector<vector<int>> res;
    	if(root==NULL){
    	    return res;
    	}
    	queue<TreeNode*> q;
    	q.push(root);
    	bool l=true;
    	while(!q.empty()){
    	    int s=q.size();
    	    vector<int> ans(s);
    	    for(int i=0;i<s;i++){
    	        TreeNode* f=q.front();
    	        q.pop();
    	        int in=l? i: s-i-1;
    	        ans[in]=f->val;
    	        if(f->left){
    	            q.push(f->left);
    	        }
    	        if(f->right){
    	            q.push(f->right);
    	        }
    	    }
    	    l=!l;
    	    res.push_back(ans);
    	}
    	return res;
    }