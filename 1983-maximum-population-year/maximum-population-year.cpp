class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> yearChanges; // To store population changes for each year

        // Populate the map with population changes
        for (auto v : logs) {
            yearChanges[v[0]]++;     // Increase population at birth year
            yearChanges[v[1]]--;     // Decrease population at death year
        }

        int maxPopulation = 0;
        int currPopulation = 0;
        int earliestYear = 0;

        // Traverse the map (years are sorted) to calculate the population year by year
        for (auto it : yearChanges) {
            currPopulation += it.second; // Update population for the current year
            if (currPopulation > maxPopulation) {
                maxPopulation = currPopulation;
                earliestYear = it.first; // Update the earliest year with max population
            }
        }

        return earliestYear;
    }
};
