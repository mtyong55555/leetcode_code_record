class Solution {
public:
    struct com_sum{
        vector<int> com;
        int sum;
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int size = candidates.size();
        vector<int> blank;
        if(size == 0) return result;
        sort(candidates.begin(),candidates.end());
        queue<com_sum> com_que; 
        com_sum begin_com;
        begin_com.com = blank;
        begin_com.sum = 0;
        com_que.push(begin_com);
        while(!com_que.empty()){
            for(int i = 0; i < size; i++){
                com_sum temp = com_que.front();
                int size_t = temp.com.size();
                if(size_t > 0 && temp.com[size_t - 1] > candidates[i]){
                    continue;
                }
                else{
                    if(temp.sum + candidates[i] == target){
                        temp.com.push_back(candidates[i]);
                        result.push_back(temp.com);
                        break;
                    }
                    else if(temp.sum + candidates[i] < target){
                        temp.sum += candidates[i];
                        temp.com.push_back(candidates[i]);
                        com_que.push(temp);
                    }
                    else{
                        break;
                    }
                }
            }
            com_que.pop();
        }
        return result;
    }
};
