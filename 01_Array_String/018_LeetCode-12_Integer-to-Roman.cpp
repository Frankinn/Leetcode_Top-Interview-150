/*
 * Top Interview 150 - 018 / 150
 * Problem: 12. Integer to Roman
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Recursive-style Logic
 * - Version 2: Position-based Mapping
 * - Version 3: Greedy Matching with Predefined Symbols
 *   Ver3 is too easy so write other version for practice.
 */
class Solution {
public:
    string intToRoman(int num) {
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i = 0; i < 13 && num > 0; ++i){
            while(num >= values[i]){
                num -= values[i];
                ans += syms[i];
            }
        }
        return ans;
        /* //ver2
        string syms = "IVXLCDM";
        string ans;
        int factor = 1000;
        for(int i = 6; i >= 0; i -= 2){
            int digit = num / factor;
            num %= factor;
            factor /= 10;
            if(digit == 0) continue;
            if(digit == 9){
                ans += syms[i];
                ans += syms[i+2];
            }
            else if(digit >= 5){
                ans += syms[i+1];
                ans.append(digit-5, syms[i]);
            }
            else if(digit == 4){
                ans += syms[i];
                ans += syms[i+1];
            }
            else{
                ans.append(digit, syms[i]);
            }
        }
        return ans;
        */
        /* //ver1
        auto getRoman = [](int n){
            switch(n){
                case 1: return 'I';
                case 5: return 'V';
                case 10: return 'X';
                case 50: return 'L';
                case 100: return 'C';
                case 500: return 'D';
                case 1000: return 'M';
                default: return '\0';
            }
        };
        auto getFirst = [](int n){
            n = std::abs(n);
            int degree = 0;
            while(n >= 10){
                n /= 10;
                ++degree;
            }
            return n*10 + degree;
        };
        int values[7] = {1, 5, 10, 50, 100, 500, 1000};
        string ans;
        while(num > 0){
            int first = getFirst(num);
            int degree = first % 10;
            first /= 10;
            if(first == 4 || first == 9){
                int plus = std::pow(10, degree);
                ans += getRoman(plus);
                num += plus;
            }
            else{
                int trans;
                for(int i = 6; i >= 0; --i){
                    if(num >= values[i]){
                        trans = values[i];
                        break;
                    }
                }
                ans += getRoman(trans);
                num -= trans;
            }
        }
        return ans;
        */
    }
};