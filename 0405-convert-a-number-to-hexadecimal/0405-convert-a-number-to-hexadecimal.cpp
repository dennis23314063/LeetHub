class Solution {
public:
    string toHex(int num) {
        string ans;
        stringstream ss;
        ss<<std::hex<<num;
        ss>>ans;
        return ans;
    }
};