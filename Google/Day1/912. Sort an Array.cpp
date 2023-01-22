class Solution {
public:
//merge sort
    void mergeSort(vector<int>&nums, int i,int mid, int j){
    if (i >= j) return;
	int l = i, r = mid + 1, k = 0, size = j-i + 1;
	vector<int> v(size, 0);
	while (l <= mid and r <= j)
		v[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	while (l <= mid) 
	    v[k++] = nums[l++];
	while (r <= j) 
		v[k++] = nums[r++];
	for (k = 0; k < size; k++)
		nums[k + i] = v[k];
    }
    void merge(vector<int>&nums,int i,int j){
        if(i>=j)return;
        int mid=i+(j-i)/2;
        merge(nums,i,mid);
        merge(nums,mid+1,j);
        mergeSort(nums,i,mid,j);

    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size()-1;
        merge(nums,0,n); 
        return nums;  
    }
};