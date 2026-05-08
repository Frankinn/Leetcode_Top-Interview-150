/*
 * Top Interview 150 - 015 / 150
 * Problem: 135. Candy
 * ---------------------------------------------------------
 * Progress:
 * - Version 1~4: Initial One-Pass Simulation
 * - Version 5: Two-Pass Greedy (O(n) Time, O(n) Space)
 * - Version 6: Slope Method (O(n) Time, O(1) Space)
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size <= 1) return size;
        int total = 1;
        int up = 0, down = 0, peak = 0;
        for(int i = 1; i < size; ++i){
            if(ratings[i] > ratings[i-1]){
                down = 0;
                ++up;
                peak = up + 1;
                total += peak;
            }
            else if(ratings[i] == ratings[i-1]){
                up = down = peak = 0;
                ++total;
            }
            else{
                up = 0;
                ++down;
                total += down;
                if(down >= peak)
                    ++total;
            }
        }
        return total;
        
        /* //v5
        int size = ratings.size();
        if(size <= 1) return size;
        vector<int> candies(size, 1);
        for(int i = 1; i < size; ++i){
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        int total = candies[size-1];
        for(int i = size - 2; i >= 0; --i){
            if(ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1]+1);
            total += candies[i];
        }
        return total;
        */
        /*  //v4
        int size = ratings.size();
        if(size == 1) return 1;
        if(size == 2) return (ratings[0] == ratings[1] ? 2 : 3);
        //v4 do tomorrow
        //find non-const: 123"3"2, find 1, go back update non-const.
        int* degrees = new int[size];
        
        int nconst = -1;  //position
        degrees[0] = 1;
        if(ratings[0] > ratings[1])
            nconst = 0;
        int current = 1;
        for(int i = 1; i < size; ++i){
            if(nconst == size-1)
                break;
            if(nconst == size-2){
                if(ratings[nconst] <= ratings[size-1])
                    degrees[nconst] = max(degrees[nconst], 1);
                else
                    degrees[nconst] = max(degrees[nconst], 2);
                break;
            }
            if(nconst > -1){
                while(i < size){
                    if(i == size-1){
                        degrees[i] = 1;
                        current = 1;
                        break;
                    }
                    if(ratings[i] <= ratings[i+1]){
                        degrees[i] = 1;
                        current = 1;
                        break;
                    }
                    ++i;
                }
                for(int j = i-1; j > nconst; --j){
                    degrees[j] = ++current;
                }
                degrees[nconst] = std::max(degrees[nconst], ++current);
                nconst = -1;
                current = 1;
                if(i >= size-1)
                    break;
                continue;
            }
            if(i >= size-1) break;
            if(ratings[i] > ratings[i-1]){
                degrees[i] = ++current;
                if(ratings[i] > ratings[i+1]){  //12"3"2
                    current = 1;
                    nconst = i;
                }
            }
            else if(ratings[i] == ratings[i-1]){
                if(ratings[i] <= ratings[i+1]){  //123"3"4
                    degrees[i] = 1;
                    current = 1;
                }
                else{   //123"3"2
                    degrees[i] = 1;
                    current = 1;
                    nconst = i;
                }
            }
            else{  //rating[i] < rating[i-1]  //123"2"
                if(ratings[i] <= ratings[i+1]){
                    current = 1;
                    degrees[i] = 1;
                }
                else{
                    degrees[i] = 1;
                    nconst = --i;
                }
            }
        }
        degrees[size-1] = (ratings[size-1] <= ratings[size-2] ? 1 : degrees[size-2]+1);
        int candy = 0;
        for(int i = 0; i < size; ++i)
            candy += degrees[i];
        
        delete[] degrees;
        return candy;
        */
        /*  //v3
        int *degrees = new int[size];
        degrees[0] = (ratings[0] <= ratings[1] ? 1 : size);
        int current = degrees[0];
        int minus = 0;
        for(int i = 1; i < size-1; ++i){
            if(ratings[i] == ratings[i-1] && ratings[i] == ratings[i+1]){
                minus += current - 1;
            }
            else if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]){
               current = 1; 
            }
            else
                ++current;
            degrees[i] = current;
        }
        degrees[size-1] = (ratings[size-1] <= ratings[size-2] ? 1 : degrees[size-2]+1);
        current = degrees[size-1];
        for(int i = size-2; i > 0; --i){
            if(ratings[i] == ratings[i-1] && ratings[i] == ratings[i+1]){}
            else if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]){
               current = 1; 
            }
            else
                ++current;
            degrees[i] = std::min(degrees[i], current);
        }
        if(degrees[0] > degrees[1])
            degrees[0] = degrees[1]+1;
        int candy = 0;
        for(int i = 0; i < size; ++i)
            candy += degrees[i];

        delete[] degrees;
        return candy - minus;
        */
        /*  //v2
        int candy = 0, current = 1;
        for(int i = 1; i < size-1; ++i){
            if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]){
                current = 1;
            }
            else
                ++current;
            candy += current;
        }
        candy += ratings[0] <= ratings[1] ? 1 : 2;
        candy += ratings[size-1] <= ratings[size-2] ? 1 : 2;
        return candy;
        */
        /*  //v1
        int degree = 0, highest = 0, lowest = 0;
        int equal = 0;
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i-1] == ratings[i]){
                ++equal;
            }
            else if(rating[i-1] < ratings[i]){  //up
                ++degree;
                highest = std::max(highest, degree);
            }
            else{  //down
                --degree;

                lowest = std::max(lowest, degree);
            }
        }
        int level = highest - lowest;
        */
    }
};