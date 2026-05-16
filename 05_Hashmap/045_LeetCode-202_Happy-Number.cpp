/*
 * Top Interview 150 - 045 / 150
 * Problem: 202. Happy Number
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Hash Set Cycle Detection
 * - Version 2: Floyd's Cycle-Finding Algorithm (Fast & Slow Pointers)
 */
class Solution {
public:
    bool isHappy(int n) {
        auto toNext = [](int num){
            int m = 0;
            while(num){
                int x = num % 10;
                m += x * x;
                num /= 10;
            }
            return m;
        };
        int slow = n, fast = n;
        do{
            slow = toNext(slow);
            fast = toNext(toNext(fast));
        } while(slow != fast); //or n != 1 && n != 4
        
        return fast == 1;

        /*
        unordered_set<int> uset;
        while(n){
            int m = 0;
            while(n){
                int x = n % 10;
                m += x * x;
                n /= 10;
            }
            if(m == 1)
                return true;
            if(uset.count(m))
                return false;
            uset.insert(m);
            n = m;
        }
        return false;
        */
    }
};