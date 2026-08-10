class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            map<pair<int, int>, int> slopeCount;

            int localMax = 0;

            for (int j = i + 1; j < n; j++) {

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                // Vertical line
                if (dx == 0) {
                    dy = 1;
                    dx = 0;
                }

                // Horizontal line
                else if (dy == 0) {
                    dy = 0;
                    dx = 1;
                }

                // Reduce fraction
                else {
                    int g = gcd(abs(dy), abs(dx));

                    dy /= g;
                    dx /= g;

                    // Keep dx positive
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }

                slopeCount[{dy, dx}]++;

                localMax = max(
                    localMax,
                    slopeCount[{dy, dx}]
                );
            }

            // +1 because anchor point is also on the line
            ans = max(ans, localMax + 1);
        }

        return ans;
    }
};