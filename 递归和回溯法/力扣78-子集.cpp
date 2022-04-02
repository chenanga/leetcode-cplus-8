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

        res.push_back(p); //��Ϊ��Ҫ������ϣ�ÿ�ν�����pushһ��
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
// printf��ӡ�汾������ֱ��
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

//         res.push_back(p); //��Ϊ��Ҫ������ϣ�ÿ�ν�����pushһ��
//         cout<<"��ǰget����pΪ ";
//         printVector(p);
//         cout <<endl;
//         if(start == nums.size())
//             return;
//         for(int i = start; i < nums.size(); i ++){
//             cout<<"��ǰp���У�";
//             printVector(p);
//             cout<<"����p���룺"<<nums[i]<<endl;
//             p.push_back(nums[i]);
//             generateSubsets(nums, p, i + 1);
//             cout<<"��ǰp���У�";
//             printVector(p);
//             cout<<"����Ҫ��p�γ���"<<nums[i]<<endl;
//             p.pop_back();

//         }
//         cout<<"��ǰp���У�";
//         printVector(p);
//         cout<<"��Ҫreturn"<<endl;
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
��������Ϊ[1,2,3]ʱ�򣬿��ƴ�ӡ����

��ǰget����pΪ
��ǰp���У�����p���룺1
��ǰget����pΪ 1
��ǰp���У�1 ����p���룺2
��ǰget����pΪ 1 2
��ǰp���У�1 2 ����p���룺3
��ǰget����pΪ 1 2 3
��ǰp���У�1 2 3 ����Ҫ��p�γ���3
��ǰp���У�1 2 ��Ҫreturn
��ǰp���У�1 2 ����Ҫ��p�γ���2
��ǰp���У�1 ����p���룺3
��ǰget����pΪ 1 3
��ǰp���У�1 3 ����Ҫ��p�γ���3
��ǰp���У�1 ��Ҫreturn
��ǰp���У�1 ����Ҫ��p�γ���1
��ǰp���У�����p���룺2
��ǰget����pΪ 2
��ǰp���У�2 ����p���룺3
��ǰget����pΪ 2 3
��ǰp���У�2 3 ����Ҫ��p�γ���3
��ǰp���У�2 ��Ҫreturn
��ǰp���У�2 ����Ҫ��p�γ���2
��ǰp���У�����p���룺3
��ǰget����pΪ 3
��ǰp���У�3 ����Ҫ��p�γ���3
��ǰp���У���Ҫreturn


*/