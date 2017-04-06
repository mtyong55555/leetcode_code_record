class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size <= 1) return false;
        unordered_map<int,int> mods;
        int sum = 0;
        int mod = 0;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            if(i > 0 && sum == 0 && k == 0) 
                return true; 
            else if(k != 0){
                mod = sum % k;
                if(i > 0 && mod == 0) 
                    return true;
                else if(mods.find(mod) == mods.end())
                    mods.insert(make_pair(mod,i));
                else{
                    if(i - mods[mod] >= 2)
                        return true;
                }
            }
        }
        return false;
    }
};
