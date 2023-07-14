class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int maxi = INT_MAX;
        for(int i = 0;i < n;i++){
            maxi = min(maxi,(int)strs[i].length());
        }
        cout << maxi << "\n";
        for(int j = 0;j < maxi;j++){
            bool check = true;
            char chkr = strs[0][j];
            for(int i = 0;i < n;i++){
                if(strs[i][j] != chkr){
                    check = false;
                    break;
                }
            }
            if(check == true) ans+=chkr;
            else break;
        }
        return ans;
    }
};