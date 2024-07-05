class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        multiset<int> a;
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (r - l > indexDiff) {
                a.erase(a.find(nums[l]));
                l++;
            }
            auto it = a.lower_bound(nums[r] - valueDiff);
            if (it != a.end() && abs(*it - nums[r]) <= valueDiff)
                return true;
            a.insert(nums[r]);

            r++;
        }
        return false;

        return false;
    }
};