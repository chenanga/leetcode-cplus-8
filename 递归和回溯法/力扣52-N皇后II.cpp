#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {

        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * (n - 1) + 1, false); //��2 *��n-1�� + 1���Խ���
        dia2 = vector<bool>(2 * (n - 1) + 1, false);
        __solveNQueens(n, 0);
        return res;
    }

private:
    //ʹ��3���������飺1�����鿴�����������Ƿ��������ʺ�ʣ�����������ҶԽ����Ƿ��������ʺ�
    vector<bool> col;  //���Ƿ�ռ��
    vector<bool> dia1; //��i���ҶԽ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ���,����Ϊ���������
    vector<bool> dia2; //��i����Խ����Ƿ�ռ�ã���2 *��n-1�� + 1���Խ��ߣ�����Ϊ������-������ + ��n-1��

    int res = 0;

    //�����index�еĻʺ�λ�ã��ѽ������row��
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