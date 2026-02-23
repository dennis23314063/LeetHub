class Solution {
public:
    string toHex(int num) {
        char ans[9];
        sprintf(ans,"%x",num);
        return ans;
        
    }
};