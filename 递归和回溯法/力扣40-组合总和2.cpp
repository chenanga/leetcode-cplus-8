#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<int> p;
//         generateCombinationSum2(candidates, target, 0, p, 0);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     void generateCombinationSum2(vector<int>& candidates, int target, int curSum, vector<int>& p, int start){
//         if(curSum == target){
//             res.push_back(p);
//             return;
//         }
//         else if(curSum > target)
//             return;
//         vector<bool> used(51, false);
//         for(int i = start; i < candidates.size(); i ++){
//             if(!used[candidates[i]]){
//                 p.push_back(candidates[i]);
//                 used[candidates[i]] = true;
//                 generateCombinationSum2(candidates, target, curSum + candidates[i], p, i + 1);
//                 p.pop_back();
//             }
//         }
//         return ;
//     }
// };

//ÓÅ»¯£¬¼ôÖ¦
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> p;
        generateCombinationSum2(candidates, target, 0, p, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void generateCombinationSum2(vector<int>& candidates, int target, int curSum, vector<int>& p, int start) {
        if (curSum == target) {
            res.push_back(p);
            return;
        }
        else if (curSum > target)
            return;
        vector<bool> used(51, false);
        for (int i = start; i < candidates.size(); i++) {
            if (curSum + candidates[i] > target)//¼ôÖ¦
                return;
            if (!used[candidates[i]]) {
                p.push_back(candidates[i]);
                used[candidates[i]] = true;
                generateCombinationSum2(candidates, target, curSum + candidates[i], p, i + 1);
                p.pop_back();
            }
        }
        return;
    }
};

int main() {

    system("pause");
    return 0;
}