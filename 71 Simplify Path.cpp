class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = segmentDirs(path);
        vector<string> strippedDirs;
        
        for(auto iter = dirs.begin(); iter < dirs.end(); iter ++){
            if(*iter == "" || *iter == ".") continue;
            if(*iter == "..") {
                if(strippedDirs.size() != 0){ 
                    strippedDirs.pop_back();
                }
                continue;
            }
            strippedDirs.push_back(*iter);
        }
        
        return mergeDirs(strippedDirs);
    }
    
    vector<string> segmentDirs(string path){
        stringstream pathStream(path);
        string segment;
        vector<string> dirs;
        while(getline(pathStream, segment, '/')){
            dirs.push_back(segment);
        }
        return dirs;
    }
    
    string mergeDirs(vector<string> dirs){
        string result;
        if(dirs.size() == 0) return "/";
        for(auto iter = dirs.begin(); iter < dirs.end(); iter ++){
            result = result + "/" + *iter;
        }
        return result;
    }
};