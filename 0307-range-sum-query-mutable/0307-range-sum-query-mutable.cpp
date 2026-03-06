#define Lson(x) ((x<<1)+1)
#define Rson(x) ((x<<1)+2)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        tree.resize(nums.size()*4);
        build(0,nums.size()-1,nums,0);
    }
    void build(int l,int r,vector<int> &nums,int x){
        tree[x].left = l;
        tree[x].right = r;
        if(l==r){
            tree[x].val = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(l,mid,nums,Lson(x));
        build(mid+1,r,nums,Rson(x));
        tree[x].val = tree[Lson(x)].val+tree[Rson(x)].val;
    }
    void update(int index, int val, int x = 0) {
        if (tree[x].left == tree[x].right) {
            tree[x].val = val;
            return;
        }
        int mid = tree[x].left + (tree[x].right - tree[x].left) / 2;
        if (index <= mid) update(index, val, Lson(x));
        else update(index, val, Rson(x));
        
        // 更新完子節點後，回溯更新當前節點的和
        tree[x].val = tree[Lson(x)].val + tree[Rson(x)].val;
    }
    int sumRange(int l, int r,int x=0) {
        int mid = tree[x].left+(tree[x].right-tree[x].left)/2;
        int ans=0;
        if(tree[x].left>=l&&tree[x].right<=r)
            return tree[x].val;
        if(l<=mid)
            ans+=sumRange(l,r,Lson(x));
        if(r>mid)
            ans+=sumRange(l,r,Rson(x));
        return ans;
    }
private:
    struct Node{
        int left;
        int right;
        int val;
    };
    vector<Node> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */