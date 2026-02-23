class Solution {
public:
    string toHex(unsigned num) {
        string ans;
        stringstream ss;
        ss<<std::hex<<num;
        ss>>ans;
        return ans;
    }
};