class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        dfs(nums,S,0,result);
        return result;
    }
    
    void dfs(vector<int>& nums, int target, int index, int& result){
        if(index == nums.size()){
            if(target == 0)
                result++;
            return;
        }
        dfs(nums,target - nums[index],index + 1,result);
        dfs(nums,target + nums[index],index + 1,result);
    }
};
