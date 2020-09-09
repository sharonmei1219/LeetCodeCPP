class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;

        vector<int> lps = buildLps(needle);
        int i = 0, j = 0;
        while(i!=haystack.length()){
            if(haystack[i] != needle[j]){
                j = lps[j];
                if(j == 0 && haystack[i] != needle[j]) i++;
            }
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            if(j == needle.length()) return i - needle.length();
        }
        return -1;
    }

    // name lps indicates longest proper prefix which is also suffix.. 
    // A proper prefix is prefix with whole string not allowed. 
    // For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. 
    // Proper prefixes are “”, “A” and “AB”. 
    // Suffixes of the string are “”, “C”, “BC” and “ABC”.
    vector<int> buildLps(string needle){
        vector<int> result(needle.length(), 0);
        result[0]=0;
        int len = 0, i = 0;
        while (i < needle.length()){
            if(needle[i] == needle[len] && i!=len){
                len++;
                if(i + 1 < needle.length()){
                    result[i + 1] = len;
                }
                i ++;
            }
            if(needle[i] != needle[len] || i == 0){
                if(len > 0){
                    len --;
                }else{
                    if(i + 1 < needle.length()){
                        result[i + 1] = len;
                    }
                    len = 0;
                    i++;
                }
            }
        }
        return result;
    }
};