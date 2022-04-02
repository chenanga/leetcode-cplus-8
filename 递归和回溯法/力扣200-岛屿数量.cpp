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
    //��grid[i][j]��ʼ�ĵط��Ƿ����ҵ�һ������
    bool inArea(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }
    void findLands(vector<vector<char>>& grid, int startX, int startY) {


        visited[startX][startY] = true;
        //��һ���������ĸ��������
        for (int i = 0; i < 4; i++) {
            int newX = startX + d[i][0];
            int newY = startY + d[i][1];
            if (inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') { //inArea������ǰ�����ж��Ƿ��ڷ�Χ�ڣ�����ʹ��visited��������ֹvisitedԽ��
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