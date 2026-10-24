class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<=12;i++)month[i]+=month[i-1];
        int a = month[stoMonth(arriveAlice)-1]+stoday(arriveAlice);
        int b = month[stoMonth(leaveAlice)-1]+stoday(leaveAlice);
        int c = month[stoMonth(arriveBob)-1]+stoday(arriveBob);
        int d = month[stoMonth(leaveBob)-1]+stoday(leaveBob);
        if(b<c||d<a)return 0;
        return min(b,d)-max(a,c)+1;
    }
private:
    int stoMonth(string str){
        return (str[0]-'0')*10+(str[1]-'0');
    }
    int stoday(string str){
        return (str[3]-'0')*10+(str[4]-'0');
    }
};
