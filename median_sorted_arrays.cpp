class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      auto num1It = nums1.begin();
      auto num2It = nums2.begin();
      std::vector<int> temp;

      for(int i = 0; i < nums1.size() + nums2.size(); ++i) {
        if(num1It == nums1.end()) {
          temp.insert(temp.end(), num2It, nums2.end());
        } else if(num2It == nums2.end()){
          temp.insert(temp.end(), num1It, nums1.end());
        } else {
          if(*num1It < *num2It) {
            temp.push_back(*num1It);
            ++num1It;
          } else {
            temp.push_back(*num2It);
            ++num2It;
          }
        }
      }

      std::for_each(temp.begin(), temp.end(), [](int &aElem) { std::cout << aElem << " "; });
      std::cout << std::endl;

      if(temp.size() % 2 == 1)
        return temp[temp.size() / 2 ];
      else
        return (temp[temp.size() / 2] + temp[temp.size() / 2 + 1]) / 2;
    }
};
