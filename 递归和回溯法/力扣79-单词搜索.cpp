#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        m = board.size(); //行
        n = board[0].size(); //列
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<char> curWord;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "从首字符为: " << board[i][j] << "开始尝试-------" << endl;
                if (findWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    int m, n; //m 行 ，n列
    int d[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} }; //二维的上 右  下   左

    vector<vector<bool>> visited;
    bool inArea(int newX, int newY) { //判断newX,newY 是否在board内
        if (newX >= 0 && newX < m && newY >= 0 && newY < n)
            return true;
        else
            return false;
    }

    //在board[stratX,startY]找word[index]
    bool findWord(const vector<vector<char>>& board, const string& word, int index, int startX, int startY) {
        if (index == word.size() - 1) {
            //找最后一个元素
            if (board[startX][startY] == word[index])
                return true;
            else
                return false;
        }

        if (board[startX][startY] == word[index]) {
            visited[startX][startY] = true;
            //向四个方向寻找下一个，使用辅助数组
            for (int i = 0; i < 4; i++) {
                int newX = startX + d[i][0];
                int newY = startY + d[i][1];

                if (inArea(newX, newY) && !visited[newX][newY]) {
                    if (findWord(board, word, index + 1, newX, newY))
                        return true;

                }
            }
            visited[startX][startY] = false;
        }

        return false;
    }
};

int main() {

	system("pause");
	return 0;
}