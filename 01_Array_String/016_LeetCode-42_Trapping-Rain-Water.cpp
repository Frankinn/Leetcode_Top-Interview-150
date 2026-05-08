/*
 * Top Interview 150 - 016 / 150
 * Problem: 42. Trapping Rain Water
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Two-Pass DP (O(n) Space)
 * - Version 2: Two Pointers (O(1) Space)
 * - Practice : Monotonic Stack (O(n) Space)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <= 2) return 0;

        int i = 0, j = size-1, ans = 0;
        int ci = height[0], cj = height[size-1];
        while(i < j){
            if(ci <= cj){
                ++i;
                if(height[i] > ci)
                    ci = height[i];
                else
                    ans += ci - height[i];
            }
            else{
                --j;
                if(height[j] > cj)
                    cj = height[j];
                else
                    ans += cj - height[j];
            }
        }
        return ans;
        /* //practice
        stack<int> st;
        int total = 0;
        for(int i = 0; i < height.size(); ++i){
            while(!st.empty() && height[i] > height[st.top()]){
                int bottomIndex = st.top();
                st.pop();
                if(st.empty()) break;
                int leftIndex = st.top();
                int width = i - leftIndex + 1;
                int minHeight = min(height[leftIndex], height[i]) - height[bottomIndex];
                total += width * minHeight;
            }
            st.push(i);
        }
        return total;
        */
        /*  //ver1
        vector<int> rain(size, 0);
        int current = 0;
        for(int i = 0; i < size; ++i){
            current = std::max(current, height[i]);
            rain[i] = current;
        }
        current = 0;
        for(int i = size-1; i > 0; --i){
            current = std::max(current, height[i]);
            rain[i] = std::min(rain[i], current);
        }
        int ans = 0;
        for(int i = 1; i < size-1; ++i){
            ans += rain[i] - height[i];
        }
        return ans;
        */
    }
};