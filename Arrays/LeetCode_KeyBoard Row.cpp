class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m'};
        for(string word: words){
            bool row1_flag=true;
            bool row2_flag=true;
            bool row3_flag=true;
            for(char c: word){
                if(row1.find(tolower(c))==row1.end()){
                    row1_flag=false;
                }
                if(row2.find(tolower(c))==row2.end()){
                    row2_flag=false;
                }
                if(row3.find(tolower(c))==row3.end()){
                    row3_flag=false;
                }
            }
            if(row1_flag||row2_flag||row3_flag){
                result.push_back(word);
            } 
        }
        return result;
    
    }
    
};
