/*
 * Top Interview 150 - 027 / 150
 * Problem: 167. Two Sum II - Input Array Is Sorted
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Two Pointers
 * - Practice : Binary Search
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0, j = numbers.size()-1; i < j; ){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                return {i+1, j+1};
            }
            else if(sum < target){
                ++i;
                //i = lower_bound(numbers.begin() + i + 1, numbers.begin() + j, target - numbers[j]) - numbers.begin();
            }
            else{ //sum > target
                --j;
                //j = upper_bound(numbers.begin() + i, numbers.begin() + j, target - numbers[i]) - numbers.begin() - 1;
            }
        }
        return {};
    }
};