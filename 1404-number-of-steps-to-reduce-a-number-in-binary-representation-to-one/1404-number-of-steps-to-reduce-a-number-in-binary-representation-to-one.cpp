class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                ans++;
            }
            else{
                if(i==0)return ans;
                for(int j=i-1;j>=0;j--){
                    if(s[j]=='0'){
                        s[j]='1';
                        ans+=i-j+1;
                        i=j+1;
                        break;
                    }
                    else if(j==0&&s[j]=='1'){
                        ans+=i+2;
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};