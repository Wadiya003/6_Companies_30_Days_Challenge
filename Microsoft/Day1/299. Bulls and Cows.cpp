
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        string s = "";
        map<int, int> m1;
        map<int, int> m2;
        int n = secret.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                a++;
            else
            {
                m1[secret[i] - '0']++;
                m2[guess[i] - '0']++;
            }
        }
        for (auto it : m1)
        {
            if (m2.find(it.first) != m2.end())
                b += min(m2[it.first], it.second);
        }
        s = to_string(a) + "A" + to_string(b) + "B";
        return s;
    }
};