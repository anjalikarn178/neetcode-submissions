class CountSquares {
private:
    int freq[1001][1001] = {};

public:
    CountSquares() {
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        freq[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (int y2 = 0; y2 <= 1000; y2++) {

            if (freq[x][y2] == 0) {
                continue;
            }

            if (y2 == y) {
                continue;
            }

            int side = abs(y2 - y);

            if (x + side <= 1000) {
                ans += freq[x][y2]
                     * freq[x + side][y]
                     * freq[x + side][y2];
            }

            if (x - side >= 0) {
                ans += freq[x][y2]
                     * freq[x - side][y]
                     * freq[x - side][y2];
            }
        }

        return ans;
    }
};