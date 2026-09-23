// URL: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();
        vector <int> freeTimes;
        int firstFreeTime = startTime[0] - 0;
        int lastFreeTime = eventTime - endTime[n - 1];

        freeTimes.push_back(firstFreeTime);
        for(int i = 1 ; i < n ; i++) {
            int freeTime = startTime[i] - endTime[i-1];
            freeTimes.push_back(freeTime);
        }
        freeTimes.push_back(lastFreeTime);

        int i = 0;
        int j = 0;
        n = freeTimes.size();
        int windowSize = k + 1;
        int currFreeTime = 0;
        int maxFreeTime = 0;

        while(j < n) {

            currFreeTime += freeTimes[j];

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                maxFreeTime = max(maxFreeTime, currFreeTime);
                currFreeTime -= freeTimes[i];
                i += 1;
                j += 1;
            }
        }

        return maxFreeTime;
    }
};
