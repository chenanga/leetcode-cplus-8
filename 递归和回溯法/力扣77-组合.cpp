#include<iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//
//        vector<int> p;
//        __combine(p, n, k, 1);
//        return res;
//    }
//private:
//
//    vector<vector<int>> res;
//
//    //求解c(n,k),当前找的的组合存储在c中，需要从start开始搜索新的元素
//    void __combine(vector<int>& p, int n, int k, int start) {
//        //index 当前待处理的数字索引
//        if (p.size() == k) {
//            res.push_back(p);
//            return;
//        }
//        for (int i = start; i <= n; i++) {
//
//            p.push_back(i);
//            __combine(p, n, k, i + 1);
//            p.pop_back();
//        }
//        return;
//
//    }
//};
//剪枝后，速度更快
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> p;
        __combine(p, n, k, 1);
        return res;
    }
private:

    vector<vector<int>> res;

    //求解c(n,k),当前找的的组合存储在c中，需要从start开始搜索新的元素
    void __combine(vector<int>& p, int n, int k, int start) {
        //index 当前待处理的数字索引
        if (p.size() == k) {
            res.push_back(p);
            return;
        }
        //还有k-p.size()个空位，所以[i,...,n]中至少有k-p.size()个元素
        //i 最多为 n -(k - p.size()) + 1
        for (int i = start; i <= n - (k - p.size()) + 1; i++) {

            p.push_back(i);
            __combine(p, n, k, i + 1);
            p.pop_back();
        }
        return;

    }
};
int main() {

	system("pause");
	return 0;
}