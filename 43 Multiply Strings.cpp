class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> num1BigInt = toBigInt(num1);
        vector<int> num2BigInt = toBigInt(num2);
        vector<int> product = bigIntMultiply(num1BigInt, num2BigInt);
        return toString(product);
    }

    vector<int> bigIntMultiply(vector<int> num1, vector<int> num2){
        int i = 0;
        vector<int> result(num1.size() + num2.size(), 0);
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                result[i+j] += num1[i] * num2[j];
                result[i+j+1] += result[i+j]/10;
                result[i+j] = result[i+j]%10;
            }
        }
        int leadingZeros = 0;
        auto iter = result.end();
        while(iter > next(result.begin())){
            iter --;
            if(*iter != 0) break;
            leadingZeros ++;
        }
        result.resize(result.size() - leadingZeros);
        return result;
    }
    
    string toString(vector<int> num){
        string result = "";
        for(auto iter = num.begin(); iter < num.end(); iter++){
            char digit = *iter + '0';
            result = digit + result;
        }
        return result;
    }
    
    vector<int> toBigInt(string num){
        vector<int> result;
        for(int i = num.length() - 1; i >= 0; i--){
            result.push_back(num[i] - '0');
        }
        return result;
    }
};