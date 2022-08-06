class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0 , high = n-1;
        while(low<= high)
        {
            int mid = (low+high)/2;
            
            //if our mid is first or previous element of mid less then mid and mid is last or next element of mid is greater then mid . then we return mid. 
            
            if((mid == 0 || arr[mid-1]<= arr[mid])&& (mid == n-1 || arr[mid+1] <=arr[mid]))
            {
                return mid ;
                
            }
            //if our prevous element of mid is greter than mid then peak element will present in left side otherwise we will move to right side . 
            
            if(mid>0 && arr[mid-1] >= arr[mid] )    
            {
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
        }
        return -1;
    }
};