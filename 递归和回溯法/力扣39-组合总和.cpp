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
//     //strat:��ǰ��ʼ��λ��
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

//�Ż�1����֦
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
    //strat:��ǰ��ʼ��λ�ã���ǰλ�ò����ǣ������ظ�
    void generateCombinationSum(vector<int>& candidates, int target, int curSum, vector<int>& p, int start) {
        if (curSum == target) {
            res.push_back(p);
            return;
        }
        else if (curSum > target)
            return;

        for (int i = start; i < candidates.size(); i++) {
            if (curSum + candidates[i] > target)
                return; //�����ǰֵ�Ѿ�����target������һ��������ֱ��break����return���˴�����Ч��һ������Ϊbreak��Ҳ��ִ�������return��
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