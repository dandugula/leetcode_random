class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> merged(nums1.size() + nums2.size());
    int i, j, k;
    i = j = k = 0;

    while(i < nums1.size() && j < nums2.size()) 
      if(nums1[i] < nums2[j])
        merged[k++] = nums1[i++];
      else
        merged[k++] = nums2[j++];

    if(i != nums1.size())
      for(;i < nums1.size(); ++i)
        merged[k++] = nums1[i];

    if(j != nums2.size())
      for(;j < nums2.size(); ++j)
        merged[k++] = nums2[j];

    if(merged.size() % 2 == 1)
      return merged[merged.size() / 2];
    else 
      return double((merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) / 2.0);
  }
};
