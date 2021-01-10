/*

Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

The number of elements currently in nums that are strictly less than instructions[i].
The number of elements currently in nums that are strictly greater than instructions[i].
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7

*/


class Solution {
public:
    
    vector<int> arr;
    int high;
    
    void add(int x){
        while(x <= high){
            arr[x]++;
            x += x & (-x);
        }
    }
    int query(int x){
        if(x == 0)
            return x;
        int res = 0;
        while(x){
            res += arr[x];
            x -= x & (-x);
        }
        return res;
    }
    
    int createSortedArray(vector<int>& instructions) {
        high = 1e5;
        arr.resize(high+1);
        int N = instructions.size();
        int sum = 0;
        int mod = 1e9 + 7;
        for (int i=0; i<N; i++) {
            add(instructions[i]);
            int left = query(instructions[i]-1);
            int right = i + 1 - query(instructions[i]);
            sum = (sum + min(left, right) % mod) % mod;
        }
        return sum;
    }
};



