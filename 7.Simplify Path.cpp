class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string item;
        vector<string> path_parts;
        string res;
        
        while(getline(ss,item,'/')){
            if(item.size() == 0 || item == ".")
                continue;
            else if(item != "..")
                path_parts.push_back(item);
            else{
                if(!path_parts.empty())
                    path_parts.pop_back();
            }
        }
        
        for(int i = 0; i < path_parts.size(); i++)
            res = res + "/" + path_parts[i];
        
        if(res.size() == 0)
            res += "/";
            
        return res;
    }
};
