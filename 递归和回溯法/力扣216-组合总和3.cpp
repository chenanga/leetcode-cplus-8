#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //  ������1+2+...+9 = 45
    //�������⣬���ֻ�ܱ�ʾ1---45,Ҳ����n�����÷�Χ���޽�
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < 1 || n > 45)
            return res;
        vector<int> p;
        generateCombinationSum3(k, n, p, 0, 1);
        return res;
    }
private:
    vector<vector<int>> res;
    //start: ��ǰ������start��ʼ�� curSum:��ǰ֮ǰ���ܺ�
    void generateCombinationSum3(int k, int n, vector<int>& p, int curSum, int start) {
        if (p.size() == k && curSum == n) {
            res.push_back(p);
            return;
        }


        //i ����ʹ�õ�����
        for (int i = start; i <= 9; i++) {
            if (curSum + i > n)//��֦
                return;
            p.push_back(i);
            generateCombinationSum3(k, n, p, curSum + i, i + 1);
            p.pop_back();
        }
        return;
    }
};


int main() {

    system("pause");
    return 0;
}