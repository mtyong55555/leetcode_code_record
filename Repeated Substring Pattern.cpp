class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if(str.size() <= 1)
            return false;
        if(str.size() == 2){
            if(str[0] == str[1])
                return true;
            else
                return false;
        }
        
        bool result = false;
        
        int size = str.size();
        
        for(int i = 1; i <= size/2+1; i++){
            int left = size % i;
            if(left == 0){
                int amount = size / i;
                bool flag = true;
                for(int j = 0; j < amount; j++){
                    for(int k = 0; k < i; k++){
                        if(str[k] != str[i * j + k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false)
                        break;
                }
                if(flag == true)
                    return true;
            }
        }
        return false;
    }
};
