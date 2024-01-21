#include <iostream>
#include <vector>
using namespace std;
class bruteforce
{


public:
   void containsDuplicate(vector<int>& nums){
      
      vector<bool> mark(nums.size(),false);
      for (int i:nums)
      {
         cout << i << endl;
      }
       for (bool i:mark)
      {
         cout << i << endl;
      }
    }
};


int main()
{
    bruteforce bf; 
    vector<int> nums = {1, 2, 3, 4, 5, 1};
       bf.containsDuplicate(nums);

}
