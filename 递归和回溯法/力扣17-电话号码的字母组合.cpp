#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//        if (digits == "")
//            return res;
//        findCombination(digits, 0, "");
//
//        return res;
//
//    }
//private:
//    const string letterMap[8] = {
//        "abc",  //2
//        "def",  //3
//        "ghi",  //4
//        "jkl",  //5
//        "mno",  //6
//        "pqrs", //7
//        "tuv",  //8
//        "wxyz"  //9
//    };
//    vector<string> res;
//    // s�б����˴�ʱ��digits[0...index-1]����õ���һ����ĸ�ַ���
//    // Ѱ�Һ�digits[index]ƥ�����ĸ, ���digits[0...index]����õ��Ľ�
//    void findCombination(const string& digits, int index, const string& s) {
//        if (index == digits.size()) {
//            res.push_back(s);
//            return;
//        }
//        char ch = digits[index];
//        string letters = letterMap[ch - '2'];
//        for (int i = 0; i < letters.size(); i++) {
//            findCombination(digits, index + 1, s + letters[i]);
//        }
//
//    }
//};
//�ݹ�ʱ����Դ�ӡ������ԣ��ȽϷ���
class Solution {

private:
    const string letterMap[10] = {
            " ",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
    };

    vector<string> res;

    // s�б����˴�ʱ��digits[0...index-1]����õ���һ����ĸ�ַ���
    // Ѱ�Һ�digits[index]ƥ�����ĸ, ���digits[0...index]����õ��Ľ�
    void findCombination(const string& digits, int index, const string& s) {

        cout << index << " : " << s << endl;
        if (index == digits.size()) {
            res.push_back(s);
            cout << "get " << s << " , return" << endl;
            return;
        }

        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            cout << "digits[" << index << "] = " << c << " , use " << letters[i] << endl;
            findCombination(digits, index + 1, s + letters[i]);
        }

        cout << "digits[" << index << "] = " << c << " complete, return" << endl;
        int index = 4;
        min(index, 3);
        return;
    }

public:
    vector<string> letterCombinations(string digits) {

        res.clear();
        if (digits == "")
            return res;

        findCombination(digits, 0, "");

        return res;
    }
};

int main() {
    //vector<string> res = Solution().letterCombinations("234");
    //for (int i = 0; i < res.size(); i++)
    //    cout << res[i] << endl;
    string str1 = "01234";
    int num1 = atoi(str1.c_str());
    cout << num1 << endl;
	system("pause");
	return 0;
}