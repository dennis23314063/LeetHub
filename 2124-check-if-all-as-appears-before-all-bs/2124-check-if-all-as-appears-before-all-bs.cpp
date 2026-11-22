class Solution {
public:
    bool checkString(string s) {
        int b = s.find_first_of("b");
        int a = s.find_last_of("a");
        return (a==-1||b==-1||b>a);
    }
};