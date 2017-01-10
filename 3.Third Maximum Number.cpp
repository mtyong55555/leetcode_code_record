class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int first = LONG_MIN,second = LONG_MIN,third = LONG_MIN;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(nums[i] == first || nums[i] == second || nums[i] == third)
                continue;
            else if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second){
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third){
                third = nums[i];
            }
        }
        if(third != LONG_MIN)
            return (int)(third);
        else
            return (int)(first); 
    }
};
