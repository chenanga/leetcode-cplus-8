#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        m = board.size(); //��
        n = board[0].size(); //��
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<char> curWord;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "�����ַ�Ϊ: " << board[i][j] << "��ʼ����-------" << endl;
                if (findWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    int m, n; //m �� ��n��
    int d[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} }; //��ά���� ��  ��   ��

    vector<vector<bool>> visited;
    bool inArea(int newX, int newY) { //�ж�newX,newY �Ƿ���board��
        if (newX >= 0 && newX < m && newY >= 0 && newY < n)
            return true;
        else
            return false;
    }

    //��board[stratX,startY]��word[index]
    bool findWord(const vector<vector<char>>& board, const string& word, int index, int startX, int startY) {
        if (index == word.size() - 1) {
            //�����һ��Ԫ��
            if (board[startX][startY] == word[index])
                return true;
            else
                return false;
        }

        if (board[startX][startY] == word[index]) {
            visited[startX][startY] = true;
            //���ĸ�����Ѱ����һ����ʹ�ø�������
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