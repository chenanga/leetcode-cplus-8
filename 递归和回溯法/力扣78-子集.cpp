#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>p;
        generateSubsets(nums, p, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void generateSubsets(vector<int>& nums, vector<int>& p, int start) {

        res.push_back(p); //因为需要所有组合，每次进来都push一下
        if (start == nums.size())
            return;
        for (int i = start; i < nums.size(); i++) {

            p.push_back(nums[i]);
            generateSubsets(nums, p, i + 1);
            p.pop_back();

        }

        return;
    }


};
// printf打印版本。方便直观
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int>p;
//         generateSubsets(nums, p, 0);

//         return res;

//     }
// private:
//     vector<vector<int>> res;
//     void generateSubsets(vector<int>& nums, vector<int>& p, int start){

//         res.push_back(p); //因为需要所有组合，每次进来都push一下
//         cout<<"当前get到，p为 ";
//         printVector(p);
//         cout <<endl;
//         if(start == nums.size())
//             return;
//         for(int i = start; i < nums.size(); i ++){
//             cout<<"当前p中有：";
//             printVector(p);
//             cout<<"，往p插入："<<nums[i]<<endl;
//             p.push_back(nums[i]);
//             generateSubsets(nums, p, i + 1);
//             cout<<"当前p中有：";
//             printVector(p);
//             cout<<"，需要从p拔出："<<nums[i]<<endl;
//             p.pop_back();

//         }
//         cout<<"当前p中有：";
//         printVector(p);
//         cout<<"需要return"<<endl;
//         return ;
//     }

//     void printVector(vector<int>& v){
//         for(int i = 0; i < v.size(); i ++){
//             cout<<v[i]<<" ";
//         }

//     }
// };

int main() {

    system("pause");
    return 0;
}

/*
测试用例为[1,2,3]时候，控制打印过程

当前get到，p为
当前p中有：，往p插入：1
当前get到，p为 1
当前p中有：1 ，往p插入：2
当前get到，p为 1 2
当前p中有：1 2 ，往p插入：3
当前get到，p为 1 2 3
当前p中有：1 2 3 ，需要从p拔出：3
当前p中有：1 2 需要return
当前p中有：1 2 ，需要从p拔出：2
当前p中有：1 ，往p插入：3
当前get到，p为 1 3
当前p中有：1 3 ，需要从p拔出：3
当前p中有：1 需要return
当前p中有：1 ，需要从p拔出：1
当前p中有：，往p插入：2
当前get到，p为 2
当前p中有：2 ，往p插入：3
当前get到，p为 2 3
当前p中有：2 3 ，需要从p拔出：3
当前p中有：2 需要return
当前p中有：2 ，需要从p拔出：2
当前p中有：，往p插入：3
当前get到，p为 3
当前p中有：3 ，需要从p拔出：3
当前p中有：需要return


*/