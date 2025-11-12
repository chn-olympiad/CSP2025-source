#include <bits/stdc++.h>
using namespace std;

int N, Q;
int L1, L2;
string s[200005][3];
int keypos[200005][3];

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    cin >> N >> Q;
    bool flagB = true;
    for(int i = 1; i <= N; ++ i)
    {
        cin >> s[i][1] >> s[i][2];
        L1 += (s[i][1].length() + s[i][2].length());
        for(int k = 0; k < s[i][1].length(); ++ k)
            if(s[i][1][k] != 'a' && s[i][1][k] != 'b') flagB = false;
        for(int k = 0; k < s[i][2].length(); ++ k)
            if(s[i][2][k] != 'a' && s[i][2][k] != 'b') flagB = false;
    }

    
    if((N <= 10000 && Q <= 10000 && L1 <= 2000) || Q == 1) // Brute Force
    {
        while (Q --)
        {
            string t1, t2;
            cin >> t1 >> t2;
            int ans = 0;
            for(int i = 1; i <= N; ++ i)
            {
                int pos = 0;
                while(true)
                {
                    pos = t1.find(s[i][1], pos);
                    int t1len = t1.length(), s1len = s[i][1].length();
                    if(pos == string::npos) break;
                    if((t1.substr(0, pos) + s[i][2] + t1.substr(pos + s1len, t1len - (pos + s1len))) == t2) ++ ans;
                    else break;
                    ++pos;
                }
            }

            cout << ans << endl;
        }
    } else if(flagB) {
        for(int i = 1; i <= N; ++ i)
        {
            keypos[i][1] = s[i][1].find("b");
            keypos[i][2] = s[i][2].find("b");
        }
        while (Q --)
        {
            int ans = 0;
            string t1, t2;
            cin >> t1 >> t2;
            int t1keypos = t1.find("b");
            int t2keypos = t2.find("b");
            for(int i = 1; i <= N; ++ i)
            {
                int s1beforekeypos = keypos[i][1], s1afterkeypos = s[i][1].length() - keypos[i][1] - 1;
                int s2beforekeypos = keypos[i][2], s2afterkeypos = s[i][2].length() - keypos[i][2] - 1;
                int t1beforekeypos = t1keypos, t1afterkeypos = t1.length() - t1keypos - 1;
                int t2beforekeypos = t2keypos, t2afterkeypos = t2.length() - t2keypos - 1;
                if(t2beforekeypos - t1beforekeypos == s2beforekeypos - s1beforekeypos && t2afterkeypos - t1afterkeypos == s2afterkeypos - s1afterkeypos)
                {
                    ++ ans;
                }
            }

            cout << ans << endl;
        }
    }
        
    return 0;
}

/*
aaaa b aa
aaa b a

a b aa
b a
 */