#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, q;
string s1[N];
string s2[N];
int fds[N]; // fds[i]表示s1[i]和s2[i]第一个不同的地方 
int dns[N]; // dns[i]表示s1[i]和s2[i]不同的字符数 
string t1, t2;

int main()
{
	freopen("replace.in",  "r", stdin);
	freopen("replace.out", "w", stdout);
    cin.tie(nullptr); cout.tie(nullptr); cout.sync_with_stdio(false);
	cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        auto &s1i = s1[i], &s2i = s2[i];
        cin >> s1i >> s2i;
        int s1isize = s1i.size();
        for (int j = 0; j < s1isize; j++)
        {
        	if (s1i[j] != s2i[j])
        	{
        		fds[i] = j;
				break;
			}
		}
		for (int j = fds[i]; j < s1isize; j++)
		{
			if (s1i[j] != s2i[j])
			{
				dns[i]++;
			}
		}
    }
    while (q--)
    {
        int ans = 0;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << "0\n";
            continue;
        }
        int firstdifference = 0, differencesnumber = 0, t1size = t1.size();
        for (int i = 0; i < t1size; i++)
        {
        	if (t1[i] != t2[i])
        	{
        		firstdifference = i;
        		break;
			}
		}
        for (int i = firstdifference; i < t1size; i++)
        {
        	if (t1[i] != t2[i])
        	{
        		differencesnumber++;
			}
		}
        for (int i = 1; i <= n; i++)
        {
            auto &s1i = s1[i], &s2i = s2[i];
            int s1isize = s1i.size();
            int cha = firstdifference - fds[i];
            if (t1size < s1isize) continue;
            if (differencesnumber != dns[i]) // 替换者和被替换者不同处个数不同不可能完成替换 
                continue;
            if (fds[i] > firstdifference) // 被替换者出现不同的位置早于替换者不可能完成替换 
                continue;
            if (cha > t1size - s1isize) // 被替换者出现不同的位置太晚了不可能完成替换 
                continue;
            for (int j = 0; j < s1isize; j++) // j -> f-fds[i]
            {
            	if (s1i[j] != t1[j+cha] || s2i[j] != t2[j+cha])
                {
                    goto nonono; // 替换的不一样不可能完成替换 
                }
			}
            ans++;
        nonono:
            continue;
        }
        cout << ans << endl;
    }
	return 0;
}
