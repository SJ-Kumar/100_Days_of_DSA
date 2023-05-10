class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        for(int i=1;i<=S.size()-1;i++){
            if(S[i]==S[i-1]){
                S.erase(i,1);
            }
            else{
                i++;
            }
        }
        return S;
    }
};
