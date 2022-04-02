#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //0-255，且不能含有前导零，所有如果有零，就是上个数字没结束,或者是单独一个0

        findCombination(s, 0, "", 0);
        return resStrs;
    }
private:
    vector<string> resStrs;
    void findCombination(const string& s, int index, const string& res, int count) {
        if (count <= 3 && index == s.size())
            return; //不到四个子串，长度满了
        if (index == s.size()) {
            resStrs.push_back(res);
            return;
        }
        if (count == 4) return; //有四个子串，，且长度不等于s，返回

        for (int j = index; j < min(index + 3, static_cast<int> (s.size())); j++) {
            // if(j + 1 >= s.size()) return; //剩余字符串长度不够
            string str = s.substr(index, j - index + 1);
            int numS = atoi(str.c_str());
            //前缀0需要排除
            if (index != j && s[index] == '0') //i不等于j说明当前长度至少为2，且第一个字符为0
                continue;
            if (numS >= 0 && numS <= 255) {
                if (count == 3)
                    findCombination(s, j + 1, res + str, count + 1); //最后一次不加.
                else
                    findCombination(s, j + 1, res + str + ".", count + 1);
            }
        }

        return;
    }

};

int main() {

	system("pause");
	return 0;
}