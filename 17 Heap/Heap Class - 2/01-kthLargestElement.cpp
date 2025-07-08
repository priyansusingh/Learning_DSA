class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
    
            // using max-heap
            priority_queue<int> pq;
    
            for(int i=0; i<nums.size(); i++){
                int val = nums[i];
                pq.push(val);
            }
            int ans = -1;
            while(k != 0){
            ans = pq.top();
            pq.pop();
            k--;
            }
            return ans;
    
            // // priority queue creation
            // priority_queue<int,vector<int>,greater<int>> pq;
    
            // // min heap / pq mein first k element push kr denge
            // for(int i=0; i<k; i++){
            //     pq.push(nums[i]);
            // }
    
            // for(int i=k; i<nums.size(); i++){
            //     int element = nums[i];
            //     if(element > pq.top()){
            //         pq.pop();
            //         pq.push(element);
            //     }
            // }
            // int ans = pq.top();
    
            // return ans;
        }
    };