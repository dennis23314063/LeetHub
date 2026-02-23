class Solution {
public:
    string toHex(int num) {
        char ans[100];
        sprintf(ans,"%x",num);
        return ans;
    }
};