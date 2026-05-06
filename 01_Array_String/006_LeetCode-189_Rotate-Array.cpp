/*
 * Top Interview 150 - 006 / 150
 * Problem: 189. Rotate Array
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Cyclic Replacement (gcd)
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        int gcd = std::gcd(k, size);
        int circle = size / gcd;
        int temp[2];
        for(int i = 0, t = 0; i < gcd; ++i){
            t = i;
            temp[0] = nums[t];
            for(int j = 0; j < circle; ++j){
                int shift = (t+k)%size;
                temp[1] = nums[shift];
                nums[shift] = temp[0];
                temp[0] = temp[1];
                t += k;
                t %= size;
            }
        }
        
    }
};