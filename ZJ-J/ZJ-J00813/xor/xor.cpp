#include <bits/stdc++.h>
using namespace std;

#define N    1000005
#define MAXK 1050000

int n, k;
int a[N];
int pre[N];
vector<int> Z[MAXK];
int nearest[N];
int ans;

int main()
{
    freopen("xor.in",  "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        pre[i] = pre[i-1] ^ a[i];
        Z[pre[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        auto fiiiind = Z[pre[i - 1] ^ k];
        auto res = lower_bound(fiiiind.begin(), fiiiind.end(), i);
        if (res == fiiiind.end()) nearest[i] = -1;
        else nearest[i] = fiiiind[res - fiiiind.begin()];
    }
    for (int i = 1; i <= n; i++)
    {
        if (nearest[i] == -1) continue;
        int now = nearest[i], start = i;
        for (i++; i < now; i++)
        {
        	if (nearest[i] == -1) continue;
            if (nearest[i] < now)
            {
                now = nearest[i];
                start = i;
            }
        }
//        printf("[%d,%d]\n", start, now);
        ans++;
		if (start == now) i--; // 这步想了1小时。。。 
    }
    printf("%d", ans);
    return 0;
}
