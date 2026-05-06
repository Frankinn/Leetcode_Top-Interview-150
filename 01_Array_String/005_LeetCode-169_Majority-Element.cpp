/*
 * Top Interview 150 - 004 / 150
 * Problem: 169. Majority Element
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Sorting
 * - Version 2: Quick select (nth_element)
 * - Version 3: Boyer-Moore Voting
 * - Version 4: Optimized Boyer-Moore
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for(int num : nums){
            if(count == 0)
                candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
        /*  //ver3
        int n = nums.size();
        if(n==1) return nums[0];
        int num = 0;
        for(int i = 0, count = 0; i < n; ++i){
            if(!count){
                num = nums[i];
                ++count;
                continue;
            }
            if(num == nums[i])
                ++count;
            else
                --count;
        }
        return num;
        */
        /*  //ver1
        std::sort(nums.begin(), nums.end());
        return nums[n/2];
        */
        /*  //ver2
        int pivot = nums[0];
        int slow = 1;
        int count = 1;
        while(slow < n && pivot >= nums[slow]){
            if(pivot == nums[slow++])
                ++count;
        }
        for(int fast = slow + 1; fast < n; ++fast){
            if(pivot == nums[fast])
                ++count;
            if(pivot >= nums[fast]){
                std::swap(nums[fast], nums[slow++]);
            }
        }
        return (count > n/2 ? pivot : nums[n/2]);
        */
    }
};