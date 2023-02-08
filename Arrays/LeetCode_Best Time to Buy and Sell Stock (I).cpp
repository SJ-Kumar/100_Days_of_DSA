class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Maxprofit=0,mincost=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mincost){
                mincost=prices[i];
            }
            else if((prices[i]-mincost)>Maxprofit){
                Maxprofit=prices[i]-mincost;
            }
        }
        return Maxprofit;
    }
};
