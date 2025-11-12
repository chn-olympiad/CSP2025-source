/*
StarLight_Yuran_ovo
ha ro ni ha
ad astra per aspera
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
int a[N][10];
int b[10];
int ans;
void dfs(int x,int num)
{
	if(x>n)
	{
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i]<n/2)
		{
			b[i]++;
			dfs(x+1,num+a[x][i]);
			b[i]--;
		}
	}
}
void solve()
{
	ans=0;
	cin>>n;
	if(n<=200)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	else
	{
		vector<int>b;
		for(int i=1;i<=n;i++)
		{
			b.push_back(a[i][1]);
		}
		sort(b.begin(),b.end());
		for(int i=n/2+1;i<=n;i++)
		{
			ans+=b[i-1];
		}
		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//某谷 1.1k 犇犇网红笑传之我是奶龙我只会写 dfs 没救了！
