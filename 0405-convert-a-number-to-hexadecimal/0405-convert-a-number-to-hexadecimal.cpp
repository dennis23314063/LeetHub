class Solution {
public:
    string toHex(int num) {
        char ans[15];
        sprintf(ans,"%x",num);
        return ans;
    }
};