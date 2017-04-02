// without memoization
class Solution {
public:
    int climbStairs(int n) {
        if(n < 0) {
            return 0;
        }
        else if(n == 0) {
            return 1;
        }
        else {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }
};

// with memoization
class Solution {
public:
    int climbStairs(int n) {
        int memo[n+1];
        std::fill_n(memo, n+1, -1);
        return count(n, memo);
    }
    
    int count(int n, int memo[]){
        if(n < 0){
            return 0;
        }
        else if(n == 0){
            return 1;
        }
        else if(memo[n] > -1){
            return memo[n];
        } 
        else {
            memo[n] = count(n-1, memo) + count(n-2, memo);
            return memo[n];
        }
    }
};