class Solution {
public:
    string toHex(int num) {
        char ans[16];
        sprintf(ans,"%x",num);
        return ans;
    }
};