#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<int>p;
//         generateCombinationSum(candidates, target, 0, p, 0);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     //strat:当前开始的位置
//     void generateCombinationSum(vector<int>& candidates, int target, int curSum, vector<int>& p, int start){
//         if(curSum == target){
//             res.push_back(p);
//             return ;
//         }
//         else if( curSum > target)
//             return ;

//         for(int i = start; i < candidates.size(); i ++){
//             p.push_back(candidates[i]);
//             generateCombinationSum(candidates, target, curSum + candidates[i], p, i);
//             p.pop_back();
//         }
//         return ;
//     }
// };

//优化1：剪枝
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>p;
        generateCombinationSum(candidates, target, 0, p, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    //strat:当前开始的位置，此前位置不考虑，避免重复
    void generateCombinationSum(vector<int>& candidates, int target, int curSum, vector<int>& p, int start) {
        if (curSum == target) {
            res.push_back(p);
            return;
        }
        else if (curSum > target)
            return;

        for (int i = start; i < candidates.size(); i++) {
            if (curSum + candidates[i] > target)
                return; //如果当前值已经超过target，后续一定超过，直接break或者return，此处两者效果一样，因为break后也就执行下面的return了
            p.push_back(candidates[i]);
            generateCombinationSum(candidates, target, curSum + candidates[i], p, i);
            p.pop_back();
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}