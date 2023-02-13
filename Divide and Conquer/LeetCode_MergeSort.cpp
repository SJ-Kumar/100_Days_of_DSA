class Solution {
public:
    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int> &nums, int l, int mid, int r) {
        int i = l, j = mid + 1, k = 0;
        vector<int> temp(r - l + 1);
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= r) temp[k++] = nums[j++];
        for (int p = 0; p < r - l + 1; p++) {
            nums[l + p] = temp[p];
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
