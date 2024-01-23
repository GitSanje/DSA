#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{


public:
   bool containsDuplicate(vector<int>& nums){
      
      std::set<int> values;

      for (int i:nums)
      {  
         auto it = values.find(i);
         if (it != values.end()){
              return true;
         } 
         values.insert(i);
      }
      return false;
    }
};


int main()
{
    Solution bf; 
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    bool result = bf.containsDuplicate(nums);
       cout <<  result << endl;
       
   return 0;
}
