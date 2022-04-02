#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //  分析：1+2+...+9 = 45
    //根据题意，最多只能表示1---45,也就是n超过该范围，无解
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < 1 || n > 45)
            return res;
        vector<int> p;
        generateCombinationSum3(k, n, p, 0, 1);
        return res;
    }
private:
    vector<vector<int>> res;
    //start: 当前从数字start开始， curSum:当前之前的总和
    void generateCombinationSum3(int k, int n, vector<int>& p, int curSum, int start) {
        if (p.size() == k && curSum == n) {
            res.push_back(p);
            return;
        }


        //i 代表使用的数字
        for (int i = start; i <= 9; i++) {
            if (curSum + i > n)//剪枝
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