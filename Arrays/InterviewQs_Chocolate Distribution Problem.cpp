class Solution{
public:
    int findMinDIff(int A[], int n, int m){
        sort(A, A+n);
        int min = INT_MAX;
        for(int i=0; i+m-1<n; i++){
            int d = A[i+m-1] - A[i];
            if(d < min){
                min = d;
            }
        }
        return min;
    }
};
