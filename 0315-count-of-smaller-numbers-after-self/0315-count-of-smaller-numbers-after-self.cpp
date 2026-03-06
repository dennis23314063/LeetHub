#define Lson(x) ((x << 1) + 1)
#define Rson(x) ((x << 1) + 2)

class Solution {
    struct Node {
        int l, r, count;
    };
    vector<Node> tree;

    void build(int l, int r, int x) {
        tree[x] = {l, r, 0};
        if (l == r) return;
        int mid = l + (r - l) / 2;
        build(l, mid, Lson(x));
        build(mid + 1, r, Rson(x));
    }

    void update(int val, int x) {
        if (tree[x].l == tree[x].r) {
            tree[x].count++;
            return;
        }
        int mid = tree[x].l + (tree[x].r - tree[x].l) / 2;
        if (val <= mid) update(val, Lson(x));
        else update(val, Rson(x));
        tree[x].count = tree[Lson(x)].count + tree[Rson(x)].count;
    }

    int query(int l, int r, int x) {
        if (l > r) return 0;
        if (tree[x].l >= l && tree[x].r <= r) return tree[x].count;
        int mid = tree[x].l + (tree[x].r - tree[x].l) / 2;
        int res = 0;
        if (l <= mid) res += query(l, r, Lson(x));
        if (r > mid) res += query(l, r, Rson(x));
        return res;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());
        
        auto getRank = [&](int val) {
            return lower_bound(sorted_nums.begin(), sorted_nums.end(), val) - sorted_nums.begin() + 1;
        };

        int m = sorted_nums.size();
        tree.resize(m * 4 + 1);
        build(1, m, 0);

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int rank = getRank(nums[i]);
            ans[i] = query(1, rank - 1, 0);
            update(rank, 0);
        }
        return ans;
    }
};