class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordStart = 0;
        int count = 0;

        for (int i = 0; i <= sentence.length(); i++) {
            if (i == sentence.length() || sentence[i] == ' ') {
                count++;
                if (sentence.substr(wordStart, searchWord.length()) == searchWord) {
                    return count;
                }
                wordStart = i + 1;
            }
        }
        return -1;
    }
};
