class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Maximize: replace the first non-9 digit with 9
        string maxS = s;
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char& c : maxS) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // Minimize: if first digit is not 1, replace it with 1
        // else replace first non-zero digit (not 1) with 0
        string minS = s;
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char& c : minS) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < minS.size(); ++i) {
                    if (minS[i] == toReplaceMin) minS[i] = '0';
                }
            }
        }

        int maxNum = stoi(maxS);
        int minNum = stoi(minS);
        return maxNum - minNum;
    }
};
