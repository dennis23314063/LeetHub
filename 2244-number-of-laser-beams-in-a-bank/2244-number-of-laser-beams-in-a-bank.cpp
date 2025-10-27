class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
        for(auto &i:bank){
            int temp=0;
            for(auto &j:i){
                if(j=='1')temp++;
            }
            if(temp>0)count.push_back(temp);
        }
        int ans=0;
        if(count.size()<2)return 0;
        for(int i=0;i<count.size()-1;i++){
            ans+=count[i]*count[i+1];
        }
        return ans;
    }
};