class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        return helper(s, index, 0, 1, false);
    }

private:
    int helper(string& s, int index, long long currentNumber, int sign, bool numberStarted) {
        if (index >= s.length()) {
            return currentNumber * sign;
        }
        if (!numberStarted && s[index] == ' ') {
            index++;
            return helper(s, index, currentNumber, sign, numberStarted);
        }
        if (!numberStarted && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
            if (index < s.length() && (s[index] == '-' || s[index] == '+' || s[index]==' ')) {
                return 0;
            }
            return helper(s, index, currentNumber, sign, numberStarted);
        }
        if (isdigit(s[index])) {
            numberStarted = true;
            currentNumber = currentNumber * 10 + (s[index] - '0');
            index++;
            if (sign == 1 && currentNumber > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -currentNumber < INT_MIN) {
                return INT_MIN;
            }
            return helper(s, index, currentNumber, sign, numberStarted);
        }
        return currentNumber * sign;
    }
};
