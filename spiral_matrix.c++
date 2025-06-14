class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = 0;
        int top = 0, down = m - 1;
        int left = 0, right = n - 1;
        vector<int> result;
        while (top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) 
                    result.push_back(matrix[top][i]);
                top++;
            } 
            else if (dir == 1) {
                for (int i = top; i <= down; i++) 
                    result.push_back(matrix[i][right]);
                right--;
            } 
            else if (dir == 2) {
                for (int i = right; i >= left; i--) 
                    result.push_back(matrix[down][i]);
                down--;
            } 
            else if (dir == 3) {
                for (int i = down; i >= top; i--) 
                    result.push_back(matrix[i][left]);
                left++;
            }
            dir = (dir + 1) % 4;
        }  
        return result;
    }
};
