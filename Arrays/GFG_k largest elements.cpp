class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> result;
        sort(arr, arr + n, greater<int>());
        int max1 = arr[0];
        for (int i = 1; i <= k; i++) {
            result.push_back(max1);
            max1 = arr[i];
        }
        return result;
	}

};
