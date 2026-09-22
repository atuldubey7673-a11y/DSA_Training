class Solution {
public:
    int solve(string& tiles, string& current, vector<bool>& used) {

        int count = 0;
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i])
                continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            current.push_back(tiles[i]);
            count += 1;
            count += solve(tiles, current, used);
            current.pop_back();
            used[i] = false;
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size(), false);
        string current;
        sort(tiles.begin(), tiles.end());

        return solve(tiles, current, used);
    }
};