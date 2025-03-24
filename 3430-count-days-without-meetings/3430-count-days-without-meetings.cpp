class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings by start time
        sort(meetings.begin(), meetings.end());

        long long busyDays = 0;
        int currentStart = -1, currentEnd = -1;

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            if (start > currentEnd) {
                // Add the previous interval's length if it exists
                if (currentStart != -1) {
                    busyDays += (long long)(currentEnd - currentStart + 1);
                }
                // Start a new interval
                currentStart = start;
                currentEnd = end;
            } else {
                // Extend the current interval
                currentEnd = max(currentEnd, end);
            }
        }

        // Add the last interval
        if (currentStart != -1) {
            busyDays += (long long)(currentEnd - currentStart + 1);
        }

        return days - busyDays;
    }
};
