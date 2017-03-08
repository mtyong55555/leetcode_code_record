class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        partitionHelper(0,s,result,part);
        return result;
    }
    
    void partitionHelper(int offset,string s,vector<vector<string>> &result,vector<string> &part){
        if(offset == s.size()){
            result.push_back(part);
            return;
        }
        for(int i = offset + 1; i <= s.size(); i++){
            string prefix = s.substr(offset,i - offset);
            if(isPalindrome(prefix)){
                part.push_back(prefix);
                partitionHelper(i,s,result,part);
                part.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        int size = s.size();
        for(int i = 0; i < size; i++){
            if(s[i] != s[size - 1 - i])
                return false;
        }
        return true;
    }
};
