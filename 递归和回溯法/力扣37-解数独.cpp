#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         row = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: 代表第i行是否能出现数字j
//         col = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: 代表第i列是否能出现数字j
//         grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));//grid[i][j][num] 表示i行j列的小方格，是否出现数字num
//         int count = findAllPos(board);
//         __solveSudoku(board, count);
//         return;
//     }
// private:
//     //设立3个辅助数组,每个数组长度设置为10，是因为数字1-9可以直接索引到，无需减一

//     vector < vector<bool >> row ; //row[i][j]: 代表第i行是否能出现数字j
//     vector < vector<bool >> col ; //col[i][j]: 代表第i列是否能出现数字j
//     //难点在于如何确保该坐标所在的方格，是否有数字num
//     //使用一个三维数组表示，使用一个坐标转换函数，横纵坐标整除以3即可，最后一个维度表示数字1-9
//     vector<vector<vector<bool>>> grid ; //grid[i][j][num] 表示i行j列的小方格，是否出现数字num

//     int findAllPos(vector<vector<char>>& board){
//         int count = 0;
//         //给定一个二维数组，返回需要填空的个数，顺便把有数子位置的标识符初始化
//         for (int i = 0; i < 9; i++) 
//             for (int j = 0; j < 9; j++) 
//                 if(board[i][j] == '.')
//                     count ++;
//                 else{
//                     //把有数字的地方对应的bool变量标注
//                     int num = board[i][j] - '0';
//                     row[i][num] = true;
//                     col[j][num] = true;
//                     grid[i/3][j/3][num] = true;
//                 }
//         return count;
//     }
//     bool __solveSudoku(vector<vector<char>>& board, const int& count) {
//         if(count == 0 )
//             return true;

//         for (int i = 0; i < 9; i++) 
//             for (int j = 0; j < 9; j++) 
//                 if (board[i][j] == '.') {
//                     //说明这里需要填写数字
//                     for (int num = 1; num <= 9; num++){
//                         int newi = i / 3; //把区间0-8变化到0-2
//                         int newj = j / 3; 
//                         if (!row[i][num] && !col[j][num] && !grid[newi][newj][num]) {
//                             board[i][j] = '0' + num;
//                             row[i][num] = true;
//                             col[j][num] = true;
//                             grid[newi][newj][num] = true;
//                             // cout<<"位置："<<i<<","<<j<<" 尝试数字"<<num<<endl;
//                             if (__solveSudoku(board, count - 1))
//                                 return true;//如果找到答案，直接返回，不再进行下面回溯，防止修改原数组
//                             board[i][j] = '.';
//                             row[i][num] = false;
//                             col[j][num] = false;
//                             grid[newi][newj][num] = false;

//                         }
//                     }
//                     return false; //此处如果数字1--9都不满足，那么直接return上一层
//                 }

//         return false;
//     }
// };

//根据官方思路优化，把空白位置保存下来，直接循环这一部分,可以节省一些时间
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: 代表第i行是否能出现数字j
        col = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: 代表第i列是否能出现数字j
        grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));//grid[i][j][num] 表示i行j列的小方格，是否出现数字num
        findAllPos(board);
        __solveSudoku(board, 0);
        return;
    }
private:
    //设立3个辅助数组,每个数组长度设置为10，是因为数字1-9可以直接索引到，无需减一

    vector < vector<bool >> row; //row[i][j]: 代表第i行是否能出现数字j
    vector < vector<bool >> col; //col[i][j]: 代表第i列是否能出现数字j
    //难点在于如何确保该坐标所在的方格，是否有数字num
    //使用一个三维数组表示，使用一个坐标转换函数，横纵坐标整除以3即可，最后一个维度表示数字1-9
    vector<vector<vector<bool>>> grid; //grid[i][j][num] 表示i行j列的小方格，是否出现数字num
    vector < pair<int, int>> spaces;
    void findAllPos(vector<vector<char>>& board) {

        //给定一个二维数组，返回需要填空的个数，顺便把有数子位置的标识符初始化
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    spaces.push_back(make_pair(i, j));
                else {
                    //把有数字的地方对应的bool变量标注
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    grid[i / 3][j / 3][num] = true;
                }
        return;
    }
    bool __solveSudoku(vector<vector<char>>& board, const int& pos) {
        if (pos == spaces.size())
            return true;

        auto [i, j] = spaces[pos];
        if (board[i][j] == '.') {
            //说明这里需要填写数字
            for (int num = 1; num <= 9; num++) {
                int newi = i / 3; //把区间0-8变化到0-2
                int newj = j / 3;
                if (!row[i][num] && !col[j][num] && !grid[newi][newj][num]) {
                    board[i][j] = '0' + num;
                    row[i][num] = true;
                    col[j][num] = true;
                    grid[newi][newj][num] = true;
                    // cout<<"位置："<<i<<","<<j<<" 尝试数字"<<num<<endl;
                    if (__solveSudoku(board, pos + 1))
                        return true;//如果找到答案，直接返回，不再进行下面回溯，防止修改原数组
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    grid[newi][newj][num] = false;

                }
            }
            return false; //此处如果数字1--9都不满足，那么直接return上一层
        }

        return false;
    }
};
int main() {

	system("pause");
	return 0;
}