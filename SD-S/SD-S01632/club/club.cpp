#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 1e5+55;
long long t, n, tot1, tot2, tot3, ans, maxa;
long long a1[MAXN], a2[MAXN], a3[MAXN], cha[MAXN];
vector<long long> c1, c2, c3;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--)
	{
		tot1 = 0, tot2 = 0, tot3 = 0, ans = 0;
		c1.clear();
		c2.clear();
		c3.clear();
		scanf("%lld", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld%lld%lld", &a1[i], &a2[i], &a3[i]);
			maxa = max(a1[i], max(a2[i], a3[i]));
			if(a1[i] == maxa) tot1++, c1.push_back(i);
			else if(a2[i] == maxa) tot2++, c2.push_back(i);
			else if(a3[i] == maxa) tot3++, c3.push_back(i);
			ans += maxa;
		}
//		printf("%d\n", ans);
		if(tot1 > n/2)
		{
//			printf("1\n");
			for(int i = 0;i < c1.size();i++) cha[i] = min(a1[c1[i]] - a2[c1[i]], a1[c1[i]] - a3[c1[i]]);
			sort(cha, cha+c1.size());
			for(int i = 0;i < tot1 - n/2;i++) ans -= cha[i];
		}
		else if(tot2 > n/2)
		{
//			printf("2\n");
			for(int i = 0;i < c2.size();i++) cha[i] = min(a2[c2[i]] - a1[c2[i]], a2[c2[i]] - a3[c2[i]]);
			sort(cha, cha+c2.size());
			for(int i = 0;i < tot2 - n/2;i++) ans -= cha[i];
		}
		else if(tot3 > n/2)
		{
//			printf("3\n");
			for(int i = 0;i < c3.size();i++) cha[i] = min(a3[c3[i]] - a2[c3[i]], a3[c3[i]] - a1[c3[i]]);
			sort(cha, cha+c3.size());
			for(int i = 0;i < tot3 - n/2;i++) ans -= cha[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
10
2020 14533 18961 3
2423 15344 16322 3
1910 6224 16178 3
2038 9963 19722 3
8375 10557 5444 2
3518 14615 17976 3
6188 13424 16615 3
8769 509 4394 1
958 3195 9953 3
16441 5313 10926 1

*/
