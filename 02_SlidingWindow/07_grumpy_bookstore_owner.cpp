// URL: https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       
        int n = customers.size();
        int totalSatisfiedCustomers = 0;
        for(int i = 0 ; i < n ; i++) {
            if(grumpy[i] == 0) {
                totalSatisfiedCustomers += customers[i];
            }
        }
         
        int i = 0;
        int j = 0;
        int windowSize = minutes;
        int currNotSatisfiedCustomers = 0;
        int maxNotSatisfiedCustomers = 0;
        
        while(j < n) {

            grumpy[j] == 1 ? currNotSatisfiedCustomers += customers[j] : 0;

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                maxNotSatisfiedCustomers = max(maxNotSatisfiedCustomers, currNotSatisfiedCustomers);
                grumpy[i] == 1 ? currNotSatisfiedCustomers -= customers[i] : 0;
                i += 1;
                j += 1;
            }
        }

        return totalSatisfiedCustomers + maxNotSatisfiedCustomers;
    }
};
