class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(digits.rbegin(),digits.rend());
        bool carry=0;
        ans[0]++;
        for(int i=0;i<n;i++){
            ans[i]+=carry;
            if(ans[i]==10){
                ans[i]-=10;
                carry=1;
            }
            else{
                carry = 0;
                break;
            }
        }
        if(carry)ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};