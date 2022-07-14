class Solution {
public:
    
    int partition(vector<int> &nums, int start, int end) {

         //1. take any element
        //picking up a random index as pivot to avoid TLE
        int ran = rand()%(end-start + 1) + start;
        swap(nums[start], nums[ran]);
        
          //2. count number of elements lesser than this
        int count = 0;
        for(int i=start+1;i<=end;i++) {
            if(nums[i]<nums[start]) count++;
        }
        int pivot = start+count;
         //3. swap this element with element at start + count
        swap(nums[start], nums[pivot]);
          
                //4. then run a while loop using two pointers that will sort the elements in both the partitions
        while(start<pivot && end>pivot) {
            while(nums[start]<nums[pivot]) {
                start++;
            }
            while(nums[end]>=nums[pivot]) {
                end--;
            } 
            
            if(start<pivot && end>pivot) {
                swap(nums[start], nums[end]);
                start++;end--;
            }
        }
        return pivot;
    }
    
    void quicksort(vector<int> &nums, int start, int end) {
        //base case
        if(start>=end) return;
           //pick a pivot
        int p = partition(nums, start, end);
        
         //sort the remaining left array and right array similarly(recursively)
        quicksort(nums, start, p-1);
        quicksort(nums, p+1, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        //quick sort
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};
