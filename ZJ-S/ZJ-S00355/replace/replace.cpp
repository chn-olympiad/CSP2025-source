#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, q;
string t1[N], t2[N];
string s1[N], s2[N];

int nxt1[N], nxt2[N];

int ans[N];

void getnxt(string t, int *nxt)
{
    nxt[0] = -1;
    for(int i=1;i < N;i++)
    {
        nxt[i] = 0;
    }

    int i = 0, j = -1;
    while(i < (int)t.size())
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}

int kmpo[N], cnt = 0;

// This KMP is not able to find T in S with the index of 0???
// So, you should add a '@' before S!!!
void kmp(string s, string t, int *nxt)
{
    cnt = 0;

    int i = 0, j = -1;
    while(i < (int)s.size() && j < (int)t.size())
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j];
        }

        if(j == (int)t.size())
        {
            // i-j+1;
            kmpo[++cnt] = i - j + 1;
            j--;
        }
    }
    if(j == (int)t.size())
    {
        kmpo[++cnt] = i - j + 1;
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i=1;i <= n;i++)
    {
        cin >> t1[i] >> t2[i];
    }

    for(int i=1;i <= q;i++)
    {
        cin >> s1[i] >> s2[i];
    }

    for(int i=1;i <= n;i++)
    {
        getnxt(t1[i], nxt1);
        getnxt(t2[i], nxt2);
        unordered_set<int> st;
        for(int j=1;j <= q;j++)
        {
            kmp('@'+s1[j], t1[i], nxt1);
            while(cnt)
            {
                st.insert(kmpo[cnt--]);
            }
            kmp('@'+s2[j], t2[i], nxt2);
            for(int k=1;k <= cnt;k++)
            {
                if(st.count(kmpo[k]))
                {
                    ans[j]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i <= q;i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}