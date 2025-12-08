class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=2;i*i<=n;i++){
            for(int j=1+(i&1);j<i;j+=2){
                if(gcd(i,j)==1)ans+=n/(i*i+j*j)*2;
            }
        }
        
        return ans;
    }
private:
    int gcd(int x,int y){
        if(y==0)return x;
        return gcd(y,x%y);
    }
};