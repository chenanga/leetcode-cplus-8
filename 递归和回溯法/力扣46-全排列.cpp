#include<iostream>
#include<vector>

using namespace std;

// //���46�⣬ʹ����set������ȥ�أ����Ǻķ�ʱ���
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         used = vector<bool>(nums.size(), false);
//         vector<int>p;
//         generatePermutation(nums, 0, p);

//         vector<vector<int>> myres(res.begin(),res.end());
//         return myres;
//     }
// private:
//     vector<bool>used;
//     set<vector<int>> res;
//     void generatePermutation(const vector<int>& nums, int index, vector<int>& p){

//         if(index == nums.size()){
//             res.insert(p);
//             return;
//         }
//         for(int i = 0; i < nums.size(); i ++){
//             if(!used[i]){
//                 p.push_back(nums[i]);
//                 used[i] = true;
//                 generatePermutation(nums, index + 1, p);
//                 //��Ҫ��һ��Ҫ����
//                 p.pop_back();
//                 used[i] = false;
//             }
//         }
//         return;

//     }
// };

//ʹ�ø�������ȥ��
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        isUsed = vector<bool>(nums.size(), false);
        vector<int>p;
        generatePermutation(nums, 0, p);

        return res;
    }
private:
    vector<bool> isUsed; //����������ÿ����ѧ��ǰ֮ǰ�Ƿ�ʹ��
    vector<vector<int>> res;
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p) {

        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        vector<bool>used(21, false); //����ǰѭ���У�ĳ�������Ƿ�ʹ�� ����-10 <= nums[i] <= 10
        for (int i = 0; i < nums.size(); i++) {

            if (!used[nums[i] + 10] && !isUsed[i]) {//ȷ������������һ��ѭ����û��ʹ�ù������ҵݹ����Ҳû���ù�
                p.push_back(nums[i]);
                isUsed[i] = true;
                used[nums[i] + 10] = true;
                generatePermutation(nums, index + 1, p);
                //��Ҫ��һ��Ҫ����
                p.pop_back();
                isUsed[i] = false;
            }
        }
        return;

    }
};

int main() {

	system("pause");
	return 0;
}