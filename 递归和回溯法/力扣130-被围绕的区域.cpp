#include<iostream>
#include<vector>

using namespace std;


// //dfs������58/59 ��ʱ����취��֦
// class Solution {
// public:
// //����Ϊ�������⣬��OΪ���죬����������O���Ӻ��Ƿ����ڱ߽�ģ����û�У���˵����Χ�ƣ�ȫ��Ϊx
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 used = vector<vector<bool>>(m, vector<bool>(n, false));
//                 curAreainLine = false;
//                 if(board[i][j] == 'O' && !visited[i][j]){
//                     dfs(board, i, j);
//                     if(!curAreainLine){
//                         for(int _i = 0; _i < m; _i ++){
//                             for(int _j = 0; _j < n; _j ++){
//                                 if(used[_i][_j])
//                                     board[_i][_j] = 'X';
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return;
//     }
// private:
//     int m,n;
//     vector<vector<bool>> visited;
//     vector<vector<bool>> used; //ÿ��ѭ��֮ǰ������գ�Ȼ���¼����ѭ���Ĺ켣��������ֶ���x��Χ����ôѭ�������켣����o��x���
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //��ǰ�����Ƿ������ű߽��
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //�жϸ��������Ƿ��ڱ߽���
//         if(x == 0 || x == m-1 || y == 0 || y == n-1)
//             return true;
//         else
//             return false;
//     }
//     void dfs(vector<vector<char>>& board, int startx, int starty ){
//         visited[startx][starty] = true;
//         used[startx][starty] = true;

//         if(isLine(startx, starty))
//             curAreainLine = true;

//         for(int i = 0; i < 4; i ++){
//             int newx = startx + d[i][0];
//             int newy = starty + d[i][1];
//             if(isArea(newx,newy) && !visited[newx][newy] && board[newx][newy] == 'O')
//                 dfs(board, newx, newy);
//         }
//         return ;

//     }
// };
// //�Ż������ù�����ֱ�Ӹ�ֵ�����ǻ���Щû�л��ݣ����ǻ���ǰһ����ʱ�򣬻�û���ҵ��߽�㣬��ʱcurAreainLineΪfalse��
// //��ʱ�������ַ���
// class Solution {
// public:
// //����Ϊ�������⣬��OΪ���죬����������O���Ӻ��Ƿ����ڱ߽�ģ����û�У���˵����Χ�ƣ�ȫ��Ϊx

//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 used = vector<vector<bool>>(m, vector<bool>(n, false));
//                 curAreainLine = false;
//                 if(board[i][j] == 'O' && !visited[i][j]){
//                     cout<<"��ǰ��x= "<<i<<", y="<<j<<"����ʼ--------------"<<endl;
//                     dfs(board, i, j);

//                 }


//             }
//         }
//         return;
//     }
// private:
//     int m,n;
//     vector<vector<bool>> visited;
//     vector<vector<bool>> used; //ÿ��ѭ��֮ǰ������գ�Ȼ���¼����ѭ���Ĺ켣��������ֶ���x��Χ����ôѭ�������켣����o��x���
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //��ǰ�����Ƿ������ű߽��
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //�жϸ��������Ƿ��ڱ߽���
//         if(x == 0 || x == m-1 || y == 0 || y == n-1)
//             return true;
//         else
//             return false;
//     }
//     void dfs(vector<vector<char>>& board, int startx, int starty ){
//         visited[startx][starty] = true;
//         used[startx][starty] = true;
//         board[startx][starty] = 'X';
//         if(isLine(startx, starty))
//             curAreainLine = true;

//         for(int i = 0; i < 4; i ++){
//             int newx = startx + d[i][0];
//             int newy = starty + d[i][1];


//             if(isArea(newx,newy) && !visited[newx][newy] && board[newx][newy] == 'O'){
//                 cout<<"��ǰ��newx= "<<newx<<", newy="<<newy<<" ��--------------"<<endl;
//                 dfs(board, newx, newy);

//             }
//         }
//         //
//         cout<<"��ǰ��startx= "<<startx<<", starty="<<starty<<" ����ʼ����-"<<endl;
//         if(curAreainLine){ //��ǰ�����а��ű߽�ĵط������в���ҪתΪx���������Ϊo
//             board[startx][starty] = 'O';
//             cout<<"��ǰ��startx= "<<startx<<", starty="<<starty<<" �����ݣ�����x-"<<endl;
//         }
//         return ;

//     }
// };


// //�Ż�1��֮ǰ���������Ҫ��Ϊx��������Ҫ���λ��Ϊtrue�������������飬���Ϊtrue����Ϊx
// //����ֱ�Ӱ���Ҫ���λ��ʹ��vectior��ά������ʽ��¼���������ٱ�������
// //��ʱ��ac�����ǻ���˫5%
// class Solution {
// public:
// //����Ϊ�������⣬��OΪ���죬����������O���Ӻ��Ƿ����ڱ߽�ģ����û�У���˵����Χ�ƣ�ȫ��Ϊx
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){

//                 if(board[i][j] == 'O' && !visited[i][j]){
//                     used.clear();
//                     curAreainLine = false;
//                     dfs(board, i, j);
//                     if(!curAreainLine){
//                         for(int count = 0; count < used.size(); count++)
//                             board[used[count][0]][used[count][1]] = 'X';
//                     }
//                 }
//             }
//         }
//         return;
//     }
// private:
//     int m,n;
//     vector<vector<bool>> visited;
//     vector<vector<int>> used; //ÿ��ѭ��֮ǰ������գ�Ȼ���¼����ѭ���Ĺ켣��xy����
//     //��ʽ�� [ [x1,y1] ,,, [x2, y2]]
//     //������ֶ���x��Χ����ôѭ�������켣����o��x���
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //��ǰ�����Ƿ������ű߽��
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //�жϸ��������Ƿ��ڱ߽���
//         if(x == 0 || x == m-1 || y == 0 || y == n-1)
//             return true;
//         else
//             return false;
//     }
//     void dfs(vector<vector<char>>& board, int startx, int starty ){
//         visited[startx][starty] = true;
//         used.push_back({startx,starty});

//         if(curAreainLine == false && isLine(startx, starty))//��ΪcurAreainLineΪfalseʱ�򣬲���Ҫ���Ƿ�䣬���Ϊtrue���������ж�
//             curAreainLine = true;

//         for(int i = 0; i < 4; i ++){
//             int newx = startx + d[i][0];
//             int newy = starty + d[i][1];
//             if(isArea(newx,newy) && !visited[newx][newy] && board[newx][newy] == 'O')
//                 dfs(board, newx, newy);
//         }
//         return ;

//     }
// };

//�ٷ�˼·
/*
ע�⵽��Ŀ�������ᵽ���κα߽��ϵ� O �����ᱻ���Ϊ X�� ���ǿ����뵽�����еĲ�����Χ�� O ��ֱ�ӻ�����߽��ϵ� O ���������ǿ���������������ж� O �Ƿ��ڱ߽��ϣ������˵��

����ÿһ���߽��ϵ� O����������Ϊ��㣬�����������ֱ�ӻ�����������ĸ O��
������Ǳ���������󣬶���ÿһ����ĸ��
�������ĸ����ǹ��������ĸΪû�б���ĸ X ��Χ����ĸ O�����ǽ��仹ԭΪ��ĸ O��
�������ĸû�б���ǹ��������ĸΪ����ĸ X ��Χ����ĸ O�����ǽ����޸�Ϊ��ĸ X��
*/

// //�Ż�2�����ڹٷ�˼·�Ż�

// class Solution {
// public:
// //����Ϊ�������⣬��OΪ���죬����������O���Ӻ��Ƿ����ڱ߽�ģ����û�У���˵����Χ�ƣ�ȫ��Ϊx
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 //��ȷ��Ϊ�߽��ϵĵ㣬����Ϊ0�ĵ�
//                 if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O' && !visited[i][j]){

//                     dfs(board, i, j);
//                     // if(!curAreainLine){
//                     //     for(int count = 0; count < used.size(); count++)
//                     //         board[used[count][0]][used[count][1]] = 'X';
//                     // }
//                 }
//             }
//         }
//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 if(visited[i][j] == false)
//                     board[i][j] = 'X';
//             }
//         }
//         return;
//     }
// private:
//     int m,n;
//     vector<vector<bool>> visited;

//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }

//     void dfs(vector<vector<char>>& board, int startx, int starty ){
//         visited[startx][starty] = true;

//         for(int i = 0; i < 4; i ++){
//             int newx = startx + d[i][0];
//             int newy = starty + d[i][1];
//             if(isArea(newx,newy) && !visited[newx][newy] && board[newx][newy] == 'O')
//                 dfs(board, newx, newy);
//         }
//         return ;

//     }
// };

//�Ż�3�����ڹٷ�˼·�Ż��ĸĽ�
//�Ѳ���Ҫ��ļ�¼������Ȼ��ֱ�Ӱ�boardȫ��Ϊx���ٰѲ���Ҫ��ò�������Ϊo
class Solution {
public:
    //����Ϊ�������⣬��OΪ���죬����������O���Ӻ��Ƿ����ڱ߽�ģ����û�У���˵����Χ�ƣ�ȫ��Ϊx
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //��ȷ��Ϊ�߽��ϵĵ㣬����Ϊ0�ĵ�
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O' && !visited[i][j])
                    dfs(board, i, j);
            }
        }
        board = vector<vector<char>>(m, vector<char>(n, 'X'));
        for (int count = 0; count < used.size(); count++) {
            board[used[count][0]][used[count][1]] = 'O';
        }
        return;
    }
private:
    int m, n;
    vector<vector<int>> used;
    vector<vector<bool>> visited;
    int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

    bool isArea(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }

    void dfs(vector<vector<char>>& board, int startx, int starty) {
        visited[startx][starty] = true;
        used.push_back({ startx,starty });
        for (int i = 0; i < 4; i++) {
            int newx = startx + d[i][0];
            int newy = starty + d[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && board[newx][newy] == 'O')
                dfs(board, newx, newy);
        }
        return;

    }
};


int main() {

	system("pause");
	return 0;
}