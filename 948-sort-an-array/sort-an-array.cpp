class Solution {
public:
    void mergeSort(vector<int>& nums, int l, int h, vector<int> &temp) {

        if (l == h)
            return;
        int mid = l + (h - l) / 2;
        mergeSort(nums, l, mid, temp);
        mergeSort(nums, mid + 1, h, temp);
        merge(nums, l, h, temp);
    }
    void merge(vector<int>& nums, int l, int h, vector<int>& temp) {
        int mid = l + (h - l) / 2;
        int i = l;
        int j = mid + 1;
        int k = l;
        while (i <= mid && j <= h) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= h) {
            temp[k++] = nums[j++];
        }
        for (int i = l; i <= h; i++) {
            nums[i] = temp[i];
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1,temp);
        return nums;
       
    }
};