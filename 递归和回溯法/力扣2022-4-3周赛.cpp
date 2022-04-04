#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int convertTime(string current, string correct) {
        int hour1 = atoi((current.substr(0, 2)).c_str());
        int minute1 = atoi((current.substr(3, 2)).c_str());

        int hour2 = atoi((correct.substr(0, 2)).c_str());
        int minute2 = atoi((correct.substr(3, 2)).c_str());

        dfs(hour1, minute1, hour2, minute2, 0);
        return res;
    }
private:

    int d[4] = { 1,5,15,60 };
    int res = INT_MAX;
    void dfs(int hour1, int minute1, int hour2, int minute2, int count) {

        if ((hour1 == hour2 && minute1 > minute2) || (hour1 > hour2))
            return;
        if (hour1 == hour2 && minute1 == minute2) {
            res = min(res, count);
            return;
        }

        for (int i = 0; i < 4; i++) {
            cout << "开始时间为 的尝试" << hour1 << ":" << minute1 << endl;
            int flag = 0;
            minute1 += d[i];
            if (minute1 > 59) {
                flag = 1;
                minute1 -= 60;
                hour1 += 1;
            }
            cout << "增加后的时间为 的尝试" << hour1 << ":" << minute1 << endl;

            dfs(hour1, minute1, hour2, minute2, count + 1);
            if (flag == 0)
                minute1 -= d[i];
            else {
                hour1 -= 1;
                minute1 = minute1 + 60 - d[i];
            }
        }
        return;

    }
};

int main() {
    Solution().convertTime("02:30", "04:35");
    vector<int> res;
    res.push_back(1);
    res.push_back(3);
    res.push_back(4);
    res.push_back(2);

    sort(res.begin(), res.end(), less<int>());
	system("pause");
	return 0;
}