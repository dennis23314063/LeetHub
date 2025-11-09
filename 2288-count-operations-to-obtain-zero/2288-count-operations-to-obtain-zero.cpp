class Solution {
public:
    int countOperations(int num1, int num2) {
        return times(num1,num2);
    }
private:
    int times(int x,int y){
        if(x==0||y==0)return 0;
        if(x<y)swap(x,y);
        return x/y+times(y,x%y);
    }
};