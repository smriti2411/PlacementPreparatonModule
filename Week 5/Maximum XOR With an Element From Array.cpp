 int min_num = INT_MAX;
    Node* child[2];
    Node(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Trie{
  private:
    Node* root;
  public:
    void construct(vector<int>& nums)
    {
        root = new Node();
        for(auto& num: nums)
        {
            Node* cur = root;
            cur->min_num = min(cur->min_num,num);
            for(int k = 31;k>=0;k--)
            {
                int x = (num>>k)&1;
                if(cur->child[x] == NULL)
                    cur->child[x] = new Node();
                cur = cur->child[x];
                cur->min_num = min(cur->min_num,num);
            }
        }
    }
    int query(vector<int>& q)
    {
        int num = q[0], m = q[1];
        Node* cur = root;
        bool small = 0;
        int ans = 0;
        if(cur->min_num > m) return -1;
        for(int k = 31;k>=0;k--)
        {
            int x = (num>>k)&1;
            int y = (m>>k)&1;
            int target = 1-x;
            if(y == 1 || small)
            {
                if(cur->child[target] != NULL && cur->child[target]->min_num <= m)
                {
                    cur = cur->child[target];
                    ans = (ans<<1) + 1;
                    if(target == 0) small = 1;
                }
                else
                {
                    cur = cur->child[1-target];
                    ans = (ans<<1);
                    if(target == 1) small = 1;
                }
            }
            else
            {
                if(cur->child[0] != NULL && cur->child[0]->min_num <= m)
                {
                    cur = cur->child[0];
                    ans = (ans<<1) + (target == 0);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        trie.construct(nums);
        int idx = 0;
        vector<int> out(queries.size());
        for(auto& q: queries)
        {
            out[idx++] = trie.query(q);
        }
        return out;
    }