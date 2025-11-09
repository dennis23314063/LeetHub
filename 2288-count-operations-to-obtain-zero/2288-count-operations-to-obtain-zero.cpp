class Solution {
public:
    int countOperations(int num1, int num2) {
        times = 0;
        op(num1,num2);
        return times;
    }
private:
    int times;
    void op(int x,int y){
        if(x==0||y==0)return;
        if(x<y)swap(x,y);
        times += x/y;
        op(y,x%y);
    }
};