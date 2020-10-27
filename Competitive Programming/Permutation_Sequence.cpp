// https://leetcode.com/problems/permutation-sequence/
// Dificullty Level - Hard
// Find complete discription of the problem on link provided above

// Logic to solution provided below
static int x = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    void permute(vector<int>& store,int n)
    {
        int i = 0, j = n-1,k;
        for(;j>0;--j)
        {
            if(store[j]>store[j-1])
            {
                int min = store[j-1], max = INT_MAX;
                for(i = j; i < n ; ++i)
                {
                    if(store[i]< max && store[i]>min)
                    {
                        max = store[i];
                        k = i;
                    }
                }
                store[k] = store[j-1];
                store[j-1] = max;
                sort(store.begin()+j,store.end());
                return;
            }
        }
    }
    
    string getPermutation(int n, int k) {
        vector <int> store(n);
        iota(store.begin(),store.end(),1);
        for(int i = 0 ; i < k-1 ; ++i)
        {
            permute(store,n);
        }
        stringstream s;
        copy(store.begin(),store.end(),ostream_iterator<int>(s, ""));
        string res = s.str();
        return res;
    }
};
