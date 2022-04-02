#include<iostream>
#include<vector>

using namespace std;

// //暴力解法
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         __partition(s, 0, 0);
//         return resStrs;
//     }

// private:
//     vector<vector<string>> resStrs;
//     vector<string> singleRes; //每次需要清零
//     void __partition(string s, int index, int count){
//         //s：字符串， index：当前该处理到的位置，count：当前字符串的数量，数量为0时候清空singleRes
//         //递归到底
//         if(index == s.size()){
//             resStrs.push_back(singleRes);
//             return;
//         }

//         for(int i = index; i < s.size(); i++){
//             if(count == 0)
//                 singleRes.clear();//每次清空
//                 string str = s.substr(index, i - index + 1);
//             if(judgeStr(str)){
//                 singleRes.push_back(str);
//                 __partition(s, i + 1, count + 1);
//                 singleRes.pop_back(); //每次需要把当前元素pop掉，因为要进去下一轮的递归，
//                                       // 回溯过程，弹出本次已经填在的子串
//             }
//         }

//     }
//     bool judgeStr(string s){
//         //判断是否是回文串
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

// 优化，判断字符串那里使用动态规划，但是时间没有提升太多
class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        record.assign(len, vector<int>(len, true));
        //f(i,j) = True, i>=j ,此时为单字符串或者空
        //f(i,j) = f(i+1,j-1) && s[i]==s[j], i<j
        //由于i位置和i+1位置有关系，所有i从大到小
        //由于j位置和j-1有关系，j从小到大
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {//此处直接选择j从i+1开始是因为前面都为t，已经赋值完毕了
                record[i][j] = record[i + 1][j - 1] && s[i] == s[j];
            }
        }

        __partition(s, 0);

        return resStrs;
    }

private:
    vector<vector<string>> resStrs; //最终返回的数组
    vector<string> singleRes; //每次需要清零
    vector<vector<int>> record; //record[i][j]代表s[i,j]是否为回文
    int len; //字符串长度
    void __partition(string s, int index) {
        //s：字符串， index：当前该处理到的位置，
        //递归到底
        if (index == len) {
            resStrs.push_back(singleRes);
            return;
        }

        for (int i = index; i < len; i++) {

            if (record[index][i]) {
                singleRes.push_back(s.substr(index, i - index + 1));
                __partition(s, i + 1);
                singleRes.pop_back(); //每次需要把当前元素pop掉，因为要进去下一轮的递归，
                                      // 回溯过程，弹出本次已经填在的子串
            }
        }

    }

};




int main() {

	system("pause");
	return 0;
}