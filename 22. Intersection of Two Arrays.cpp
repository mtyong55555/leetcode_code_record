class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 == 0 || size2 == 0) return result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        while(i < size1 && j < size2){
            while(i != size1 - 1 && nums1[i] == nums1[i+1])
                i++;
            while(j != size2 - 1 && nums2[j] == nums2[j+1])
                j++;
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return result;
    }
};
