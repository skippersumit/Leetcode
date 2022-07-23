class Solution {
public:
     void merge(int left,int right,int mid,vector<pair<int,int>>&v,vector<int>&count){
        vector<pair<int,int>>temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            else{
                count[v[i].second]+=right-j+1;
                temp[k++]=v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=v[i++];
        }
        
        while(j<=right){
            temp[k++]=v[j++];
        }
        
        for(int it=left;it<=right;it++){
            v[it]=temp[it-left];
        }
    }
    
    void mergeSort(int left,int right,vector<pair<int,int>>&v,vector<int>&count){
        if(left<right){
            int mid=(left+right)/2;
            mergeSort(left,mid,v,count);
            mergeSort(mid+1,right,v,count);
            merge(left,right,mid,v,count);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        
        vector<int>count(n,0);
        mergeSort(0,n-1,v,count);
        return count;
    }
};