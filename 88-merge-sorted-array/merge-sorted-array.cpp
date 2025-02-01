class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_pntr = 0, nums2_pntr = 0;
        vector<int> nums_tmp;
        while ((nums1_pntr < m) & (nums2_pntr < n))
        {
            if (nums1[nums1_pntr] <= nums2[nums2_pntr])
            {
                nums_tmp.push_back(nums1[nums1_pntr]);
                nums1_pntr += 1;
            }
            else
            {
                nums_tmp.push_back(nums2[nums2_pntr]);
                nums2_pntr += 1;
            }
        }
        while (nums1_pntr < m)
        {
            nums_tmp.push_back(nums1[nums1_pntr]);
            nums1_pntr += 1;
        }
        while (nums2_pntr < n)
        {
            nums_tmp.push_back(nums2[nums2_pntr]);
            nums2_pntr += 1;
        }
        for (int i = 0; i < nums_tmp.size(); i++)
            nums1[i] = nums_tmp[i];
    }
};