// 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m = m-1;
        n = n-1;
        int end = m + n + 1;
        
        while (m >=0  && n >=0) {
            if (nums1[m] >= nums2[n]) {
                nums1[end] = nums1[m];
                m--;
            } else {
                nums1[end] = nums2[n];
                n--;
            }
            end--;
        }
        
        while (n >= 0) {
            nums1[end] = nums2[n]; 
            n--; end--;
        }
        
    }
};