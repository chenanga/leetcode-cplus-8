#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //0-255���Ҳ��ܺ���ǰ���㣬����������㣬�����ϸ�����û����,�����ǵ���һ��0

        findCombination(s, 0, "", 0);
        return resStrs;
    }
private:
    vector<string> resStrs;
    void findCombination(const string& s, int index, const string& res, int count) {
        if (count <= 3 && index == s.size())
            return; //�����ĸ��Ӵ�����������
        if (index == s.size()) {
            resStrs.push_back(res);
            return;
        }
        if (count == 4) return; //���ĸ��Ӵ������ҳ��Ȳ�����s������

        for (int j = index; j < min(index + 3, static_cast<int> (s.size())); j++) {
            // if(j + 1 >= s.size()) return; //ʣ���ַ������Ȳ���
            string str = s.substr(index, j - index + 1);
            int numS = atoi(str.c_str());
            //ǰ׺0��Ҫ�ų�
            if (index != j && s[index] == '0') //i������j˵����ǰ��������Ϊ2���ҵ�һ���ַ�Ϊ0
                continue;
            if (numS >= 0 && numS <= 255) {
                if (count == 3)
                    findCombination(s, j + 1, res + str, count + 1); //���һ�β���.
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