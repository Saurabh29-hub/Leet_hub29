class Solution {
public:
    bool canRepairAll(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += (long long)sqrt(time / rank);
            if (totalCars >= cars) return true;
        }
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14, result = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairAll(ranks, cars, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
