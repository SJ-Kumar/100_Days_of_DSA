class Solution{
  public:
    int minDiff(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int minDiff = INT_MAX;
        
        for (int i = 0; i + K- 1 < N; i++) {
            int currentDiff = arr[i + K - 1] - arr[i];
            minDiff = min(minDiff, currentDiff);
        }
        
        return minDiff;
    
    }
};
