class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        vector<vector<int>>ans;
        sort(i.begin(),i.end());
        int start=i[0][0];
        int end=i[0][1];
        for(auto x:i){
            if(end>=x[0])end=max(end,x[1]);
            else{
                ans.push_back({start,end});
                start=x[0];
                end=x[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
