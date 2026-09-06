class Solution {
public:
   int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

        return solve(s, t, 0, 0, memo);
    }

private:
    int solve(const std::string& s, const std::string& t, int i, int j, std::vector<std::vector<int>>& memo) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s[i] == t[j]) {
            long long pick = solve(s, t, i + 1, j + 1, memo);
            long long skip = solve(s, t, i + 1, j, memo);

            return memo[i][j] = static_cast<int>(pick + skip);
        }

        long long skip = solve(s, t, i + 1, j, memo);

        return memo[i][j] = static_cast<int>(skip);
    }
};