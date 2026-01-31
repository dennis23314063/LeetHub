class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size();
        int mid;
        char ans=letters[0];
        while(l<r){
            mid = l+(r-l)/2;
            if(letters[mid]>target){
                r = mid;
                ans = letters[mid];
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};