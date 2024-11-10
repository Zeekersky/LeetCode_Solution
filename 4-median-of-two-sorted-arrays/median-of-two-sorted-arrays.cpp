class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }
        int low = 0, high = m;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;
            int r1 = INT_MAX, r2 = INT_MAX, l1 = INT_MIN, l2 = INT_MIN;

            if (mid1 < m)
                r1 = nums1[mid1];
            if (mid2 < n)
                r2 = nums2[mid2];

            if (mid1 > 0)
                l1 = nums1[mid1 - 1];
            if (mid2 > 0)
                l2 = nums2[mid2 - 1];

            if (l1 > r2)
                high = mid1 - 1;
            else if (l2 > r1)
                low = mid1 + 1;
            else
            {
                int maxLeft = max(l1, l2);
                int minRight = min(r1, r2);
                if ((m + n) % 2 == 0)
                    return (double)(maxLeft + minRight) / 2.0;
                else
                    return maxLeft;
            }
        }
        return 0.0;
    }
};