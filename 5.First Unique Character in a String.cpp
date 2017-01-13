class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if(size <= 0) return -1;
        if(size == 1) return 0;
        
        int chars[26];
        for(int i = 0; i < 26; i++)
            chars[i] = -1;
        
        for(int i = 0; i < size; i++){
            int index = (int)(s[i] - 'a');
            if(chars[index] == -1)
                chars[index] = i;
            else if(chars[index] != -2)
                chars[index] = -2;
        }
        
        int min_index = INT_MAX;
        for(int i = 0; i < 26; i++){
            if(chars[i] >= 0 && chars[i] < min_index)
                min_index = chars[i];
        }
        if(min_index > size)
            return -1;
        else 
            return min_index;
    }
};
