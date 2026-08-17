class Solution {
public:
    int findMaxGrid(vector<vector<int>>& mat, int n, int m, int col) {
        int maxElement = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxElement) {
                maxElement = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maax = findMaxGrid(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maax][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maax][mid + 1] : -1;
            if (mat[maax][mid] > left && mat[maax][mid] > right) {
                return {maax, mid};
            } else if (mat[maax][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};