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
    int hour = 0; //4λ 0-11
    int minute = 0; //6λ 0-59
    vector<string>res;
    void generateReadBinaryWatch(int turnedOn, int index, int count) {
        if (count == turnedOn) {
            if (minute < 10)
                res.push_back(to_string(hour) + ":" + "0" + to_string(minute)); //��ǰ�油0
            else
                res.push_back(to_string(hour) + ":" + to_string(minute));
            return;
        }
        //10������ ����1 2 4 8|1 2 4 8 16 32 ��ǰ��Ϊh�����Ϊmin
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
            if (!(hour > 11 || minute > 59)) //�������˵�������ϣ�ֱ����һ�֣�����֮���Բ���������Ϊ����h����11ʱ����һ��h���٣�Ȼ��minute���ӣ����ܾ͸պ������ˣ����в���ֱ��break����return
                generateReadBinaryWatch(turnedOn, i + 1, count + 1);

            if (i <= 4) //����
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