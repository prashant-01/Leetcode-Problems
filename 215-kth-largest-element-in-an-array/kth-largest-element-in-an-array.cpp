class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k + 1;
        priority_queue<int>maxHeap;
        for(int i=0 ; i<index ; i++)maxHeap.push(nums[i]);
        for(int i=index ; i<nums.size() ; i++){
            if(nums[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
        }
        return maxHeap.top();
    }
};