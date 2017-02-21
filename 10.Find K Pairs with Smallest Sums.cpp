class Solution {
public:
    struct greater_pair{
        bool operator()(const pair<int,int>& pair1, const pair<int,int>& pair2){
            return (pair1.first + pair1.second > pair2.first + pair2.second);
        }
    };
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater_pair> pair_queue;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 == 0 || size2 == 0) return result;
        for(int i = 0; i < size1; i++){
            for(int j = 0; j < size2; j++){
                pair<int,int> temp_pair = make_pair(nums1[i],nums2[j]);
                pair_queue.push(temp_pair);
            }
        }
        for(int i = 0; i < k && i < size1 * size2; i++){
            result.push_back(pair_queue.top());
            pair_queue.pop();
        }
        return result;
    }
};
