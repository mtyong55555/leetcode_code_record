class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        if(num1.size() == 0 || num2.size() == 0)
            return result;
        if(num1 == "0" || num2 == "0")
            return "0";
        
        int length1 = num1.size();
        int length2 = num2.size();
        
        vector<int> vec(length1),res(length1 + length2);
        
        for(int i = 0; i < length1; i++){
            vec[i] = ((int)(num1[length1 - 1 - i] - '0'));
        }
        
        int start = 0;
        
        for(int i = length2 - 1; i >= 0; i--){
            int mul = (int)(num2[i] - '0');
            int carry = 0;
            int res_temp = 0;
            int pos_carry = 0;
            int j = 0;
            for(j = 0; j < length1; j++){
                res_temp = vec[j] * mul + pos_carry + res[start + j];
                res[start + j] = res_temp % 10;
                pos_carry =  res_temp / 10;
            }
            while(pos_carry > 0){
                res[start + j] = pos_carry % 10;
                pos_carry = pos_carry / 10;
                j++;
            }
            start++;
        }
        
        int end = res.size() - 1;
        while(res[end] == 0) 
            end--;
        
        for(int i = end; i >= 0; i--){
            result += (char)(res[i] + '0');
        }
        
        return result;
    }
};
