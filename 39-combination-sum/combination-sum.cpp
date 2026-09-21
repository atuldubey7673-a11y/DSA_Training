class Solution {
public:

void solve(vector<int>&candidates,int target,int index,vector<int>&current,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(index>=candidates.size() || target<0){
        return ;
    }
    current.push_back(candidates[index]);
    solve(candidates,target-candidates[index],index,current,ans);
    current.pop_back();
    solve(candidates,target,index+1,current,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>current;
       vector<vector<int>>ans ;
       solve(candidates,target,0,current,ans);
       return ans;
    }
};