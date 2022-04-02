#include<iostream>
#include<vector>

using namespace std;

// //�����ⷨ
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         __partition(s, 0, 0);
//         return resStrs;
//     }

// private:
//     vector<vector<string>> resStrs;
//     vector<string> singleRes; //ÿ����Ҫ����
//     void __partition(string s, int index, int count){
//         //s���ַ����� index����ǰ�ô�����λ�ã�count����ǰ�ַ���������������Ϊ0ʱ�����singleRes
//         //�ݹ鵽��
//         if(index == s.size()){
//             resStrs.push_back(singleRes);
//             return;
//         }

//         for(int i = index; i < s.size(); i++){
//             if(count == 0)
//                 singleRes.clear();//ÿ�����
//                 string str = s.substr(index, i - index + 1);
//             if(judgeStr(str)){
//                 singleRes.push_back(str);
//                 __partition(s, i + 1, count + 1);
//                 singleRes.pop_back(); //ÿ����Ҫ�ѵ�ǰԪ��pop������ΪҪ��ȥ��һ�ֵĵݹ飬
//                                       // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
//             }
//         }

//     }
//     bool judgeStr(string s){
//         //�ж��Ƿ��ǻ��Ĵ�
//         int left = 0;
//         int right = s.size() - 1;
//         while(left < right){
//             if(s[left] != s[right])
//                 return false;
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

// �Ż����ж��ַ�������ʹ�ö�̬�滮������ʱ��û������̫��
class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        record.assign(len, vector<int>(len, true));
        //f(i,j) = True, i>=j ,��ʱΪ���ַ������߿�
        //f(i,j) = f(i+1,j-1) && s[i]==s[j], i<j
        //����iλ�ú�i+1λ���й�ϵ������i�Ӵ�С
        //����jλ�ú�j-1�й�ϵ��j��С����
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {//�˴�ֱ��ѡ��j��i+1��ʼ����Ϊǰ�涼Ϊt���Ѿ���ֵ�����
                record[i][j] = record[i + 1][j - 1] && s[i] == s[j];
            }
        }

        __partition(s, 0);

        return resStrs;
    }

private:
    vector<vector<string>> resStrs; //���շ��ص�����
    vector<string> singleRes; //ÿ����Ҫ����
    vector<vector<int>> record; //record[i][j]����s[i,j]�Ƿ�Ϊ����
    int len; //�ַ�������
    void __partition(string s, int index) {
        //s���ַ����� index����ǰ�ô�����λ�ã�
        //�ݹ鵽��
        if (index == len) {
            resStrs.push_back(singleRes);
            return;
        }

        for (int i = index; i < len; i++) {

            if (record[index][i]) {
                singleRes.push_back(s.substr(index, i - index + 1));
                __partition(s, i + 1);
                singleRes.pop_back(); //ÿ����Ҫ�ѵ�ǰԪ��pop������ΪҪ��ȥ��һ�ֵĵݹ飬
                                      // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
            }
        }

    }

};




int main() {

	system("pause");
	return 0;
}