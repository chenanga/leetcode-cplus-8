#include<iostream>
#include<vector>

using namespace std;


// //dfs，过了58/59 超时，想办法剪枝
// class Solution {
// public:
// //想象为岛屿问题，设O为岛屿，看看相连的O连接后是否有在边界的，如果没有，则说明被围绕，全置为x
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
//     vector<vector<bool>> used; //每轮循环之前都会清空，然后记录本轮循环的轨迹，如果本轮都被x包围，那么循环遍历轨迹，把o用x填充
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //当前区域是否有临着边界的
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //判断给定坐标是否在边界上
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
// //优化，设置过程中直接赋值，但是会有些没有回溯，或是回溯前一部分时候，还没有找到边界点，此时curAreainLine为false。
// //暂时放弃此种方法
// class Solution {
// public:
// //想象为岛屿问题，设O为岛屿，看看相连的O连接后是否有在边界的，如果没有，则说明被围绕，全置为x

//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 used = vector<vector<bool>>(m, vector<bool>(n, false));
//                 curAreainLine = false;
//                 if(board[i][j] == 'O' && !visited[i][j]){
//                     cout<<"当前从x= "<<i<<", y="<<j<<"，开始--------------"<<endl;
//                     dfs(board, i, j);

//                 }


//             }
//         }
//         return;
//     }
// private:
//     int m,n;
//     vector<vector<bool>> visited;
//     vector<vector<bool>> used; //每轮循环之前都会清空，然后记录本轮循环的轨迹，如果本轮都被x包围，那么循环遍历轨迹，把o用x填充
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //当前区域是否有临着边界的
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //判断给定坐标是否在边界上
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
//                 cout<<"当前到newx= "<<newx<<", newy="<<newy<<" 。--------------"<<endl;
//                 dfs(board, newx, newy);

//             }
//         }
//         //
//         cout<<"当前到startx= "<<startx<<", starty="<<starty<<" 。开始返回-"<<endl;
//         if(curAreainLine){ //当前区域有挨着边界的地方，所有不需要转为x，这里回溯为o
//             board[startx][starty] = 'O';
//             cout<<"当前到startx= "<<startx<<", starty="<<starty<<" 。回溯，设置x-"<<endl;
//         }
//         return ;

//     }
// };


// //优化1，之前如果本轮需要变为x，设置需要变的位置为true，遍历整个数组，如果为true，变为x
// //这里直接把需要变的位置使用vectior二维数组形式记录下来，减少遍历次数
// //此时能ac，但是击败双5%
// class Solution {
// public:
// //想象为岛屿问题，设O为岛屿，看看相连的O连接后是否有在边界的，如果没有，则说明被围绕，全置为x
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
//     vector<vector<int>> used; //每轮循环之前都会清空，然后记录本轮循环的轨迹的xy，、
//     //格式如 [ [x1,y1] ,,, [x2, y2]]
//     //如果本轮都被x包围，那么循环遍历轨迹，把o用x填充
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     bool curAreainLine = false; //当前区域是否有临着边界的
//     bool isArea(int x, int y){
//         if(x >= 0 && x < m && y >= 0 && y < n)
//             return true;
//         else
//             return false;
//     }
//     bool isLine(int x, int y){ //判断给定坐标是否在边界上
//         if(x == 0 || x == m-1 || y == 0 || y == n-1)
//             return true;
//         else
//             return false;
//     }
//     void dfs(vector<vector<char>>& board, int startx, int starty ){
//         visited[startx][starty] = true;
//         used.push_back({startx,starty});

//         if(curAreainLine == false && isLine(startx, starty))//当为curAreainLine为false时候，才需要看是否变，如果为true，则无需判断
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

//官方思路
/*
注意到题目解释中提到：任何边界上的 O 都不会被填充为 X。 我们可以想到，所有的不被包围的 O 都直接或间接与边界上的 O 相连。我们可以利用这个性质判断 O 是否在边界上，具体地说：

对于每一个边界上的 O，我们以它为起点，标记所有与它直接或间接相连的字母 O；
最后我们遍历这个矩阵，对于每一个字母：
如果该字母被标记过，则该字母为没有被字母 X 包围的字母 O，我们将其还原为字母 O；
如果该字母没有被标记过，则该字母为被字母 X 包围的字母 O，我们将其修改为字母 X。
*/

// //优化2，基于官方思路优化

// class Solution {
// public:
// //想象为岛屿问题，设O为岛屿，看看相连的O连接后是否有在边界的，如果没有，则说明被围绕，全置为x
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();

//         visited = vector<vector<bool>>(m, vector<bool>(n, false));

//         for(int i = 0; i < m; i ++){
//             for(int j = 0; j < n; j ++){
//                 //先确保为边界上的点，再找为0的点
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

//优化3，基于官方思路优化的改进
//把不需要变的记录下来，然后直接把board全变为x，再把不需要变得部分设置为o
class Solution {
public:
    //想象为岛屿问题，设O为岛屿，看看相连的O连接后是否有在边界的，如果没有，则说明被围绕，全置为x
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //先确保为边界上的点，再找为0的点
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