#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {

//         col = vector<bool>(n, false);
//         dia1 = vector<bool>(2*(n-1) + 1, false); //有2 *（n-1） + 1条对角线
//         dia2 = vector<bool>(2*(n-1) + 1, false); 
//         vector<string> p;
//         __solveNQueens(n, 0, p);
//         return res;
//     }

// private:
//     //使用3个辅助数组：1个数组看该坐标列上是否有其他皇后，剩下两个看左右对角线是否有其他皇后
//     vector<bool> col;  //列是否被占用
//     vector<bool> dia1; //第i条右对角线是否被占用，有2 *（n-1） + 1条对角线,索引为横纵坐标和
//     vector<bool> dia2; //第i条左对角线是否被占用，有2 *（n-1） + 1条对角线，索引为横坐标-纵坐标 + （n-1）

//     vector<vector<string>> res;
//     string generateStr(int n, int pos){
//         //产生一个长度为n，pos位置为q的字符串
//         return string(pos,'.') + "Q" + string(n-pos-1,'.');

//     }
//     //处理第index行的皇后位置，把结果放入p中
//     void __solveNQueens(int n, int startx, vector<string>& p){
//         if(startx == n){
//             res.push_back(p);
//             return;
//         }
//         for(int i = 0; i < n; i ++){
//             if(!col[i] && !dia1[startx+i] && !dia2[startx-i+n-1]){
//                 col[i] = true;
//                 dia1[startx+i] = true;
//                 dia2[startx-i+n-1] = true;
//                 p.push_back(generateStr(n, i));
//                 __solveNQueens(n, startx + 1, p);
//                 p.pop_back();
//                 col[i] = false;
//                 dia1[startx+i] = false;
//                 dia2[startx-i+n-1] = false;
//             }
//         }
//         return ;

//     }

// };
//优化，递归时候push_back存解的坐标，因为是固定了行从0开始，那么对应的列坐标存入数组，最后确定这个解有效时候，再转换为string类型
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * (n - 1) + 1, false); //有2 *（n-1） + 1条对角线
        dia2 = vector<bool>(2 * (n - 1) + 1, false);
        vector<int> row;
        __solveNQueens(n, 0, row);
        return res;
    }

private:
    //使用3个辅助数组：1个数组看该坐标列上是否有其他皇后，剩下两个看左右对角线是否有其他皇后
    vector<bool> col;  //列是否被占用
    vector<bool> dia1; //第i条右对角线是否被占用，有2 *（n-1） + 1条对角线,索引为横纵坐标和
    vector<bool> dia2; //第i条左对角线是否被占用，有2 *（n-1） + 1条对角线，索引为横坐标-纵坐标 + （n-1）

    vector<vector<string>> res;
    //把一个解数组，转换为题目要求的格式
    vector<string> generateBoard(int n, vector<int> row) {
        // vector<string> vec;
        // for(int i = 0; i < n; i ++)
        //     vec.push_back(string(row[i],'.') + "Q" + string(n-row[i]-1,'.'));
        // return vec;
        //下面这种方案节省空间
        vector<string> vec(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            vec[i][row[i]] = 'Q';
        return vec;
    }
    //处理第index行的皇后位置，把结果放入row中
    void __solveNQueens(int n, int startx, vector<int>& row) {
        if (startx == n) {
            res.push_back(generateBoard(n, row));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[startx + i] && !dia2[startx - i + n - 1]) {
                col[i] = true;
                dia1[startx + i] = true;
                dia2[startx - i + n - 1] = true;
                row.push_back(i);
                __solveNQueens(n, startx + 1, row);
                row.pop_back();
                col[i] = false;
                dia1[startx + i] = false;
                dia2[startx - i + n - 1] = false;
            }
        }
        return;

    }

};

int main() {

	system("pause");
	return 0;
}