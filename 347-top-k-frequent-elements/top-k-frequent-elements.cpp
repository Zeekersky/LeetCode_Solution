class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        unordered_map<int , int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(pq.size()<k)
                pq.push({it.second, it.first});
            else{
                if(pq.top().first<it.second){
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};