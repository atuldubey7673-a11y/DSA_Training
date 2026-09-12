class Solution {
public:

    struct State {
        long long score;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {

        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending time
        sort(a.begin(), a.end(),
            [](const auto& x, const auto& y) {

                if (x[1] != y[1])
                    return x[1] < y[1];

                return x[0] < y[0];
            }
        );

        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        // prev[i] = last interval before i
        // whose end < current start
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            int pos = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();

            prev[i] = pos - 1;
        }

        /*
            dp[i][k] =
            best answer using first i intervals
            and selecting at most k intervals
        */
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5, {0, {}})
        );

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take interval i-1
                State skip = dp[i - 1][k];

                // Option 2: take interval i-1
                int p = prev[i - 1] + 1;

                State take = dp[p][k - 1];

                take.score += a[i - 1][2];

                take.ids.push_back(a[i - 1][3]);

                sort(take.ids.begin(), take.ids.end());

                // Choose maximum score.
                // If tied, choose lexicographically smaller indices.
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[n][4].ids;
    }
};