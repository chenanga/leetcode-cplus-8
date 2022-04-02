#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>p;
        generateSubsetsWithDup(nums, 0, p);
        return res;
    }
private:
    vector<vector<int>> res;
    void generateSubsetsWithDup(vector<int>& nums, int start, vector<int>& p) {
        res.push_back(p);
        sort(nums.begin(), nums.end()); //�����򣬱�������ظ�Ԫ��
        if (start == nums.size())
            return;

        vector<bool>used(21, false); //-10 --- 10  21������
        for (int i = start; i < nums.size(); i++) {
            if (!used[nums[i] + 10]) {
                p.push_back(nums[i]);
                used[nums[i] + 10] = true;
                generateSubsetsWithDup(nums, i + 1, p);
                p.pop_back(); //��Ҫ����һ��֮ǰҪ�ѵ�ǰ�����pop��
            }
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}