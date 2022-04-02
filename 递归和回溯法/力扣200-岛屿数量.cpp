#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    findLands(grid, i, j);
                    count++;
                }

            }
        }
        return count;
    }
private:
    int m, n;
    vector<vector<bool>> visited;
    int d[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    //以grid[i][j]开始的地方是否能找到一个岛屿
    bool inArea(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }
    void findLands(vector<vector<char>>& grid, int startX, int startY) {


        visited[startX][startY] = true;
        //从一个方向向四个方向遍历
        for (int i = 0; i < 4; i++) {
            int newX = startX + d[i][0];
            int newY = startY + d[i][1];
            if (inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') { //inArea必须在前，先判断是否在范围内，才能使用visited函数，防止visited越界
                findLands(grid, newX, newY);
            }
        }

        return;
    }
};

int main() {

    system("pause");
    return 0;
}