class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> part = nums;
        permuteHelper(0,part,result);
        return result;
    }
    
    void permuteHelper(int i,vector<int> &part, vector<vector<int>> &result){
        if(i == part.size()){
            result.push_back(part);
            return;
        }
        for(int j = i; j < part.size(); j++){
            swap(part[i],part[j]);
            permuteHelper(i+1,part,result);
            swap(part[i],part[j]);
        }
    }
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};
