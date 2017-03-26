class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> tempCount;
        stack<string> tempRes;
        int size = s.size();
        if(size == 0) return res;
        int idx = 0, count = 0;
        while(idx < size){
            while(isdigit(s[idx])){
                count = count * 10 + (s[idx] - '0');
                idx++;
            }
            if(s[idx] == '['){
                tempCount.push(count);
                count = 0;
                tempRes.push(res);
                res = "";
                idx++;
            }
            else if(s[idx] == ']'){
                int curCount = tempCount.top();
                tempCount.pop();
                string curRes = tempRes.top();
                tempRes.pop();
                for(int i = 0; i < curCount; i++)
                    curRes += res;
                res = curRes;
                idx++;
            }
            else{
                res += s[idx];
                idx++;
            }
        }
        return res;
    }
};
