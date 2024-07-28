//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
 
class Solution
{
public:
    string setToString(const set<char> &s)
    {
        string result;
        for (const auto &element : s)
        {
            result.insert(result.begin(), element);
        }

        return result;
    }

    string removeDupsScratch(string str)
    {
        array<bool, 26> alpharr = {false};
        int  index =0;

        for (int i = 0; i < str.length(); i++)
        {
            int pv = str[i] - 'a'; 
            if (!alpharr[pv])
            {
                alpharr[pv] = true;
                str[index++] = str[i];
            }
           
            
        }
        return str.substr(0,index);
    }

    string removeDups(string str)
    {

        std::unordered_set<char> seen;
        std::string result;
        for (char c : str)
        {

            if (seen.find(c) == seen.end())
            {
                seen.insert(c);
                result += c;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDupsScratch(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends