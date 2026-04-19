// problem: https://leetcode.com/problems/reverse-words-in-a-string/description/

// brute : split the string into words, reverse the vector of words and join them back together
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string> words;
        string word = "";

        for (int i=0; i<n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            }

            else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string ans = "";

        for (int i=0; i<words.size(); i++) {
            ans += words[i];

            // if the word is not the last word, add a space after each word
            if (i < words.size()-1) {
                ans += ' ';
            }
        }

        return ans;
    }
};
// tc: O(n), sc: O(n)

// optimal : traverse the string from the end and build the answer string on the go
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string ans = "";

        int i = n-1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            if (i < 0) {
                break;
            }

            int end = i;

            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            string word = s.substr(i+1, end-i);

            if (!ans.empty()) {
                ans += " ";
            }

            ans += word;
        }

        return ans;
    }
};
// tc: O(n), sc: O(1)