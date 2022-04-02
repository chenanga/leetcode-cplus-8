#include<iostream>
#include<vector>

using namespace std;

// //相比46题，使用了set容器，去重，但是耗费时间多
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
//                 //重要，一定要回退
//                 p.pop_back();
//                 used[i] = false;
//             }
//         }
//         return;

//     }
// };

//使用辅助数字去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        isUsed = vector<bool>(nums.size(), false);
        vector<int>p;
        generatePermutation(nums, 0, p);

        return res;
    }
private:
    vector<bool> isUsed; //代表数组中每个数学当前之前是否被使用
    vector<vector<int>> res;
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p) {

        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        vector<bool>used(21, false); //代表当前循环中，某个数字是否被使用 由于-10 <= nums[i] <= 10
        for (int i = 0; i < nums.size(); i++) {

            if (!used[nums[i] + 10] && !isUsed[i]) {//确保该数字在这一轮循环中没有使用过，并且递归过程也没有用过
                p.push_back(nums[i]);
                isUsed[i] = true;
                used[nums[i] + 10] = true;
                generatePermutation(nums, index + 1, p);
                //重要，一定要回退
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