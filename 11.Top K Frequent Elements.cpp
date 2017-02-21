class Solution {
public:
    struct less_feq{
        bool operator()(const pair<int,int>& pair1, const pair<int,int>& pair2){
            return pair1.second < pair2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less_feq> q_feq;
        unordered_map<int,int> map_feq;
        int size = nums.size();
        if(size == 0) return result;
            for(int i = 0; i < size; i++){
            if(map_feq.find(nums[i]) == map_feq.end()){
                map_feq.insert(make_pair(nums[i],1));
            }
            else{
                map_feq[nums[i]]++;
            }
        }
        unordered_map<int,int>::iterator it;
        for(it = map_feq.begin(); it != map_feq.end(); ++it){
            q_feq.push(*it);
        }
        for(int i = 0; i < k && (!q_feq.empty()); i++){
            result.push_back(q_feq.top().first);
            q_feq.pop();
        }
        return result;
    }
};
