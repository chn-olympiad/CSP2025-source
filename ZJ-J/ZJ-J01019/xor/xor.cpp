#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5 * 1e5 + 5;
int n, k, a[N], ans, cnt[N], s[N];
vector<int> edge[N];
inline int read()
{
	int x=0, f=1; char ch = getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch = getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch = getchar();}
	return x * f;
}
void dfs(int u, int s)
{
	if (!edge[u].size()||cnt[u]!=-1) return;
	ans = max(ans, s);
	cnt[u] = 1;
	for (auto v:edge[u])
	{
		dfs(v, s+1);
		cnt[u]=max(cnt[v]+1, cnt[u]);
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(); k=read();
	bool ok = true;
	int ta=0, tb=0;
	for (int i=1; i<=n; i++)
	{
		a[i] = read();
		if (a[i] ==0) ta++;
		else if (a[i] == 1) tb++;
		else ok = false;
	}
	if (ok)
	{
		if (ta&&tb)
		{
			if (k==1)
			{
				printf("%lld", tb);
			}
			else if (k==0)
			{
				bool ok = false;
				for (int i=1; i<=n; i++)
				{
					if (a[i] == 0) ans++;
					else if (a[i]==1){
						if (ok) 
						{
							ans ++;
							ok = false;
						}
						else
						{
							ok = true;
						}
					}
				}
				printf("%lld", ans);
			}
//			else{
//				printf("%d", 0);
//			}
		}
		else if (tb&&!ta)
		{
			if (k==1) 
			{
				printf("%lld", tb);
			}
			else if (k==0)
			{
				printf("%lld", tb/2);
			}
			else {
				printf("%d", 0);
			}
		}
		return 0;
	}
//	else
//	{
//		dfs(1, 0, 0);
//		printf("%d", ans);
		vector<int> sum(n+5, 0);
		for (int i=1; i<=n; i++){
			sum[i] = sum[i-1]^a[i];
//			cout << sum[i] << ' ';
		} 
//		cout << endl;
		for (int i=1; i<=n; i++)
		{
			cnt[i] = -1;
//			s[i] = -1;
			for (int j=i; j<=n; j++)
			{
				int tmp =sum[j]^sum[i-1]; 
				if (tmp== k) {
					edge[i].push_back(j+1);
//					s[i] = j+1;
//					break;
				}
			}
		}
//		int ans2 = 0;
//		for (int i=1; i<=n; i++)
//		{
//			if (edge[i].size())
//			{
//				dfs(i);
//				ans2 = max(ans2, cnt[i]);
//			}
//		}
//		for (int i=0; i<=n; i++)
//		{
//			for (auto j:edge[i])
//			{
//				printf("%d ", j);
//			}
//			printf("\n");
//		}
//		for (int i=1; i<=n; i++) cout << s[i] << ' ';
//		cout << endl;
		for (int i=1; i<=n; i++)
		{
//			int sum = 1, left=s[i];
//			while (left!=-1&&left<=n)
//			{
////				cout << left << endl;
//				sum++;
//				left = s[left];
//			}
			dfs(i,1);
//			ans = max(ans, sum);
		}
		for (int i=1; i<=n; i++)
		{
			ans = max(ans, cnt[i]);
		}
		printf("%lld", ans);
		
//	}	
	return 0;
}
