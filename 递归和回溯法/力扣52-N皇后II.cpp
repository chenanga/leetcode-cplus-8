#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {

        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * (n - 1) + 1, false); //有2 *（n-1） + 1条对角线
        dia2 = vector<bool>(2 * (n - 1) + 1, false);
        __solveNQueens(n, 0);
        return res;
    }

private:
    //使用3个辅助数组：1个数组看该坐标列上是否有其他皇后，剩下两个看左右对角线是否有其他皇后
    vector<bool> col;  //列是否被占用
    vector<bool> dia1; //第i条右对角线是否被占用，有2 *（n-1） + 1条对角线,索引为横纵坐标和
    vector<bool> dia2; //第i条左对角线是否被占用，有2 *（n-1） + 1条对角线，索引为横坐标-纵坐标 + （n-1）

    int res = 0;

    //处理第index行的皇后位置，把结果放入row中
    void __solveNQueens(int n, int startx) {
        if (startx == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[startx + i] && !dia2[startx - i + n - 1]) {
                col[i] = true;
                dia1[startx + i] = true;
                dia2[startx - i + n - 1] = true;
                __solveNQueens(n, startx + 1);
                col[i] = false;
                dia1[startx + i] = false;
                dia2[startx - i + n - 1] = false;
            }
        }
        return;

    }

};

int main() {
    vector<vector<vector<int>>> grid;
	system("pause");
	return 0;
}