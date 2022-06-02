class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(( mid-1 < 0 or arr[mid]>arr[mid-1]) and (mid+1 >=n or arr[mid]>arr[mid+1]))
                return mid;
            else if(arr[mid]<arr[mid+1])
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
};