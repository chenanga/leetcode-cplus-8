#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {

        generateReadBinaryWatch(turnedOn, 1, 0);
        return res;
    }
private:
    int hour = 0; //4位 0-11
    int minute = 0; //6位 0-59
    vector<string>res;
    void generateReadBinaryWatch(int turnedOn, int index, int count) {
        if (count == turnedOn) {
            if (minute < 10)
                res.push_back(to_string(hour) + ":" + "0" + to_string(minute)); //在前面补0
            else
                res.push_back(to_string(hour) + ":" + to_string(minute));
            return;
        }
        //10个数字 代表1 2 4 8|1 2 4 8 16 32 ，前边为h，后边为min
        for (int i = index; i <= 10; i++) {
            int add = 0;
            if (i <= 4) {
                add = pow(2, i - 1);
                hour += add;
            }
            else {
                add = pow(2, i - 5);
                minute += add;
            }
            if (!(hour > 11 || minute > 59)) //如果大于说明不符合，直接下一轮，这里之所以不跳过是因为，当h超过11时候，下一轮h减少，然后minute增加，可能就刚好满足了，所有不能直接break或者return
                generateReadBinaryWatch(turnedOn, i + 1, count + 1);

            if (i <= 4) //回溯
                hour -= add;
            else
                minute -= add;
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}