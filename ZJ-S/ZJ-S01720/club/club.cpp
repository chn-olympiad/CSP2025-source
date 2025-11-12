#include <bits/stdc++.h>
using namespace std;

long long T,n,a[1000005][5],leng[5],maxl,nn;
long long ans,maxn=0;

void dfs()
{
	if (nn==n+1)
	{
		//cout << ans << endl;
		if (ans>maxn) maxn = ans;
		return;
	}
	for (int i = 1; i<=3;i++)
	{
		if (leng[i]<maxl)
		{
			leng[i]++;
			ans+=a[nn][i];
			nn++;
			dfs();
			nn--;
			ans-=a[nn][i];
			leng[i]--;
		}
	}
}

void dfsb()
{
	if (nn==n+1)
	{
		//cout << ans << endl;
		if (ans>maxn) maxn = ans;
		return;
	}
	for (int i = 1; i<=2;i++)
	{
		if (leng[i]<maxl)
		{
			leng[i]++;
			ans+=a[nn][i];
			nn++;
			dfs();
			nn--;
			ans-=a[nn][i];
			leng[i]--;
		}
	}
}


bool cmp1(int a,int b)
{
	if (a<b) return false;
	return true;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(leng,0,sizeof(leng));
		cin >> n;
		bool is_a = true;
		bool is_b = true;
		for (int i = 1; i<=n;i++)
			for (int j = 1; j<=3;j++)
			{
				cin >> a[i][j];
				if (i == 2 && a[i][j] != 0) is_a = false;
				if (i==3 && a[i][j]!=0)
				{
					is_a = false;
					is_b = false;
				}
			}
		
		
		if (is_a){
			int ttt[100005];
			for (int i = 1; i<=n; i++){
				ttt[i] = a[i][0];
			}
			sort(ttt+1,ttt+n+1,cmp1);
			int sum=0;
			for (int i = 1; i<=n/2;i++){
				sum+=ttt[i];
			}
			cout << sum<<endl;
			continue;
		}
		
		if (is_b){
			ans = 0;
			maxn =0;
			maxl = n>>1;
			nn = 1;
			dfsb();
			cout << maxn << endl;
			continue;
		}
		
		ans = 0;
		maxn =0;
		maxl = n>>1;
		nn = 1;
		dfs();
		cout << maxn << endl;
	}
	return 0;
}