class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		vector<int>result;
		for(int i=0;i<N;i++){
		    int row=0,col=i;
		    while(row<N && col>=0){
		        result.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		}
		
		for(int i=1;i<N;i++){
		    int row=i,col=N-1;
		    while(row<N && col>=0){
		        result.push_back(A[row][col]);
		        row++;
		        col--;
		        
		    }
		}
		return result;
	}

};