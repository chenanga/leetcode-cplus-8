#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {

//         col = vector<bool>(n, false);
//         dia1 = vector<bool>(2*(n-1) + 1, false); //��2 *��n-1�� + 1���Խ���
//         dia2 = vector<bool>(2*(n-1) + 1, false); 
//         vector<string> p;
//         __solveNQueens(n, 0, p);
//         return res;
//     }

// private:
//     //ʹ��3���������飺1�����鿴�����������Ƿ��������ʺ�ʣ�����������ҶԽ����Ƿ��������ʺ�
//     vector<bool> col;  //���Ƿ�ռ��
//     vector<bool> dia1; //��i���ҶԽ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ���,����Ϊ���������
//     vector<bool> dia2; //��i����Խ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ��ߣ�����Ϊ������-������ + ��n-1��

//     vector<vector<string>> res;
//     string generateStr(int n, int pos){
//         //����һ������Ϊn��posλ��Ϊq���ַ���
//         return string(pos,'.') + "Q" + string(n-pos-1,'.');

//     }
//     //�����index�еĻʺ�λ�ã��ѽ������p��
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
//�Ż����ݹ�ʱ��push_back�������꣬��Ϊ�ǹ̶����д�0��ʼ����ô��Ӧ��������������飬���ȷ���������Чʱ����ת��Ϊstring����
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * (n - 1) + 1, false); //��2 *��n-1�� + 1���Խ���
        dia2 = vector<bool>(2 * (n - 1) + 1, false);
        vector<int> row;
        __solveNQueens(n, 0, row);
        return res;
    }

private:
    //ʹ��3���������飺1�����鿴�����������Ƿ��������ʺ�ʣ�����������ҶԽ����Ƿ��������ʺ�
    vector<bool> col;  //���Ƿ�ռ��
    vector<bool> dia1; //��i���ҶԽ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ���,����Ϊ���������
    vector<bool> dia2; //��i����Խ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ��ߣ�����Ϊ������-������ + ��n-1��

    vector<vector<string>> res;
    //��һ�������飬ת��Ϊ��ĿҪ��ĸ�ʽ
    vector<string> generateBoard(int n, vector<int> row) {
        // vector<string> vec;
        // for(int i = 0; i < n; i ++)
        //     vec.push_back(string(row[i],'.') + "Q" + string(n-row[i]-1,'.'));
        // return vec;
        //�������ַ�����ʡ�ռ�
        vector<string> vec(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            vec[i][row[i]] = 'Q';
        return vec;
    }
    //�����index�еĻʺ�λ�ã��ѽ������row��
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