class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Add all elements to min heap
        for(int num : nums) {
            pq.push((long long)num);
        }
        
        // Continue operations until all elements are >= k
        while(pq.size() >= 2 && pq.top() < k) {
            // Get two smallest elements
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            
            // Calculate new value
            long long newVal = min(x, y) * 2 + max(x, y);
            
            // Add new value back to heap
            pq.push(newVal);
            operations++;
        }
        
        // Check if smallest element is still less than k
        if(pq.top() < k) {
            return -1;
        }
        
        return operations;
    }
};
