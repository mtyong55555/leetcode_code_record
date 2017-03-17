class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int size = S.size();
        string result;
        int count = 0;
        reverse(S.begin(),S.end());
        for(int i = 0; i < size; i++){
            if(S[i] != '-'){
                if(!isdigit(S[i])){
                    if(S[i] - 'a' >= 0){
                        S[i] = S[i] - 'a' + 'A';
                    }
                }
                result += S[i];
                count++;
            if(count < size && (count)%K == 0)
                result += '-';
            }
        }
        size = result.size();
        if(result[size - 1] == '-')
            result.erase(result.begin() + size - 1);
        reverse(result.begin(),result.end());
        return result;
    }
};
