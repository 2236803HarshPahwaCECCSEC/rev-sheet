class Solution {
public:
            vector<int> countFrequencies(const string& str) {
    vector<int> freq(26, 0);
    for (char c : str) {
        freq[c - 'a']++;
    }
    return freq;
}

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    // Step 1: Determine the "maximum character requirement" from words2
    vector<int> maxFreq(26, 0);
    for (const string& b : words2) {
        vector<int> freq = countFrequencies(b);
        for (int i = 0; i < 26; ++i) {
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }

    // Step 2: Filter words1 to find universal strings
    vector<string> result;
    for (const string& a : words1) {
        vector<int> freqA = countFrequencies(a);
        bool isUniversal = true;
        for (int i = 0; i < 26; ++i) {
            if (freqA[i] < maxFreq[i]) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) {
            result.push_back(a);
        }
    }

    return result;}
};