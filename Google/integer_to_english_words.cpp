class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> hundreds = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return inWords(num);
    }

    string inWords(int num) {
        if (num < 10) {
            return ones[num];
        }
        if (num < 20) {
            return tens[num - 10];
        }
        if (num < 100) {
            return hundreds[num / 10] + (num % 10 != 0 ? " " + inWords(num % 10) : "");
        }
        if (num < 1000) {
            return inWords(num / 100) + " Hundred" + (num % 100 != 0 ? " " + inWords(num % 100) : "");
        }
        if (num < 1000000) {
            return inWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + inWords(num % 1000) : "");
        }
        if (num < 1000000000) {
            return inWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + inWords(num % 1000000) : "");
        }
        return inWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + inWords(num % 1000000000) : "");
    }
};
