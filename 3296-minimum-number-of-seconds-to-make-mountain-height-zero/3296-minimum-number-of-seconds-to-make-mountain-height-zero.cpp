class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    /*
    x*(x+1)/2 * height[i] = s
    x^2+x- s/height[i]*2 = 0;

    -1+sqrt(1+8*s/height[i])/2
    */
        long long l=1,r=1e18;
        long long mid=0;
        while(l<r){
            mid = l+(r-l)/2;
            long long sum = sumup(mid,workerTimes);
            if(sum>=mountainHeight){
               r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
private:
    long long sec(long long s,int time){
        return (sqrt(1+8.0*s/time)-1)/2.0;
    }
    long long sumup(long long s,vector<int> &workerTime){
        long long sum=0;
        for(auto &i:workerTime){
            sum+=sec(s,i);
        }
        return sum;
    }
};