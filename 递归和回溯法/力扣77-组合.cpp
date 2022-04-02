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
//    //���c(n,k),��ǰ�ҵĵ���ϴ洢��c�У���Ҫ��start��ʼ�����µ�Ԫ��
//    void __combine(vector<int>& p, int n, int k, int start) {
//        //index ��ǰ���������������
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
//��֦���ٶȸ���
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> p;
        __combine(p, n, k, 1);
        return res;
    }
private:

    vector<vector<int>> res;

    //���c(n,k),��ǰ�ҵĵ���ϴ洢��c�У���Ҫ��start��ʼ�����µ�Ԫ��
    void __combine(vector<int>& p, int n, int k, int start) {
        //index ��ǰ���������������
        if (p.size() == k) {
            res.push_back(p);
            return;
        }
        //����k-p.size()����λ������[i,...,n]��������k-p.size()��Ԫ��
        //i ���Ϊ n -(k - p.size()) + 1
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