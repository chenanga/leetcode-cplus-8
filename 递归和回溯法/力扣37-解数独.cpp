#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         row = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: �����i���Ƿ��ܳ�������j
//         col = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: �����i���Ƿ��ܳ�������j
//         grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));//grid[i][j][num] ��ʾi��j�е�С�����Ƿ��������num
//         int count = findAllPos(board);
//         __solveSudoku(board, count);
//         return;
//     }
// private:
//     //����3����������,ÿ�����鳤������Ϊ10������Ϊ����1-9����ֱ���������������һ

//     vector < vector<bool >> row ; //row[i][j]: �����i���Ƿ��ܳ�������j
//     vector < vector<bool >> col ; //col[i][j]: �����i���Ƿ��ܳ�������j
//     //�ѵ��������ȷ�����������ڵķ����Ƿ�������num
//     //ʹ��һ����ά�����ʾ��ʹ��һ������ת����������������������3���ɣ����һ��ά�ȱ�ʾ����1-9
//     vector<vector<vector<bool>>> grid ; //grid[i][j][num] ��ʾi��j�е�С�����Ƿ��������num

//     int findAllPos(vector<vector<char>>& board){
//         int count = 0;
//         //����һ����ά���飬������Ҫ��յĸ�����˳���������λ�õı�ʶ����ʼ��
//         for (int i = 0; i < 9; i++) 
//             for (int j = 0; j < 9; j++) 
//                 if(board[i][j] == '.')
//                     count ++;
//                 else{
//                     //�������ֵĵط���Ӧ��bool������ע
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
//                     //˵��������Ҫ��д����
//                     for (int num = 1; num <= 9; num++){
//                         int newi = i / 3; //������0-8�仯��0-2
//                         int newj = j / 3; 
//                         if (!row[i][num] && !col[j][num] && !grid[newi][newj][num]) {
//                             board[i][j] = '0' + num;
//                             row[i][num] = true;
//                             col[j][num] = true;
//                             grid[newi][newj][num] = true;
//                             // cout<<"λ�ã�"<<i<<","<<j<<" ��������"<<num<<endl;
//                             if (__solveSudoku(board, count - 1))
//                                 return true;//����ҵ��𰸣�ֱ�ӷ��أ����ٽ���������ݣ���ֹ�޸�ԭ����
//                             board[i][j] = '.';
//                             row[i][num] = false;
//                             col[j][num] = false;
//                             grid[newi][newj][num] = false;

//                         }
//                     }
//                     return false; //�˴��������1--9�������㣬��ôֱ��return��һ��
//                 }

//         return false;
//     }
// };

//���ݹٷ�˼·�Ż����ѿհ�λ�ñ���������ֱ��ѭ����һ����,���Խ�ʡһЩʱ��
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: �����i���Ƿ��ܳ�������j
        col = vector < vector<bool >>(9, vector<bool>(10, false)); //row[i][j]: �����i���Ƿ��ܳ�������j
        grid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));//grid[i][j][num] ��ʾi��j�е�С�����Ƿ��������num
        findAllPos(board);
        __solveSudoku(board, 0);
        return;
    }
private:
    //����3����������,ÿ�����鳤������Ϊ10������Ϊ����1-9����ֱ���������������һ

    vector < vector<bool >> row; //row[i][j]: �����i���Ƿ��ܳ�������j
    vector < vector<bool >> col; //col[i][j]: �����i���Ƿ��ܳ�������j
    //�ѵ��������ȷ�����������ڵķ����Ƿ�������num
    //ʹ��һ����ά�����ʾ��ʹ��һ������ת����������������������3���ɣ����һ��ά�ȱ�ʾ����1-9
    vector<vector<vector<bool>>> grid; //grid[i][j][num] ��ʾi��j�е�С�����Ƿ��������num
    vector < pair<int, int>> spaces;
    void findAllPos(vector<vector<char>>& board) {

        //����һ����ά���飬������Ҫ��յĸ�����˳���������λ�õı�ʶ����ʼ��
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    spaces.push_back(make_pair(i, j));
                else {
                    //�������ֵĵط���Ӧ��bool������ע
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
            //˵��������Ҫ��д����
            for (int num = 1; num <= 9; num++) {
                int newi = i / 3; //������0-8�仯��0-2
                int newj = j / 3;
                if (!row[i][num] && !col[j][num] && !grid[newi][newj][num]) {
                    board[i][j] = '0' + num;
                    row[i][num] = true;
                    col[j][num] = true;
                    grid[newi][newj][num] = true;
                    // cout<<"λ�ã�"<<i<<","<<j<<" ��������"<<num<<endl;
                    if (__solveSudoku(board, pos + 1))
                        return true;//����ҵ��𰸣�ֱ�ӷ��أ����ٽ���������ݣ���ֹ�޸�ԭ����
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    grid[newi][newj][num] = false;

                }
            }
            return false; //�˴��������1--9�������㣬��ôֱ��return��һ��
        }

        return false;
    }
};
int main() {

	system("pause");
	return 0;
}