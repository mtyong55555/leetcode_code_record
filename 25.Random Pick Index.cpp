class Solution {
public:
    vector<pair<int,int>> indexs;
    
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        return a.first < b.first;
    }
    
    Solution(vector<int> nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++){
            indexs.push_back(make_pair(nums[i],i));
        }
        sort(indexs.begin(),indexs.end(),compare);
    }
    
    int pick(int target) {
        int start = -1, end = -1;
        int size = indexs.size();
        for(int i = 0; i < size; i++){
            int temp = indexs[i].first;
            if(temp < target) continue;
            else if(temp == target){
                if(start == -1) start = i;
                if(i == size - 1 || indexs[i + 1].first > target){
                    end = i;
                    break;
                }
            }
        }
        if(end == start) return indexs[start].second;
        return indexs[start + rand() % (end - start + 1)].second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
