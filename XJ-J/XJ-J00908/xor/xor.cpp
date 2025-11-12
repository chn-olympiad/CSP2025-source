#include <bits/stdc++.h>

using namespace std;
int n,k,a[500010];
int s[500010],e[500010];
int f[500010];
int lse;
int cnt;
int ma;
void dfs(int);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int xx = 1;xx<=n;xx++)
	{
		for(int i = 1;i+xx-1<=n;i++)
		{
			int sum = a[i];
			for(int j = i+1;j<i+xx;j++)
			{
				sum = sum^a[j];
//				if(xx==3&&i==2) cout<<sum<<endl;
			}
			if(sum==k) s[++lse] = i,e[lse] = i+xx-1;
//			if(xx==3&&i==2) cout<<sum<<endl;
		}
		
	}
	for(int i = 1;i<=lse-1;i++)
	{
		for(int j = 1;j<=lse-i-1;j++)
		{
			if(e[j]>e[j+1])
			{
				swap(e[j],e[j+1]);
				swap(s[j],s[j+1]);
			}
		}
	}
//	cout<<lse<<endl;
//	for(int i = 1;i<=n;i++)
//	{
//		cout<<s[i]<<" "<<e[i]<<endl;
//	}
	cout<<ma;
	dfs(0);
	cout<<ma;
	return 0;
}
void dfs(int pp)
{
	if(pp==lse)
	{
		ma = max(ma,cnt);
		return;
	}
	for(int i = pp+1;i<=lse;i++)
	{
		if(f[i]==0&&s[i]>e[pp])
		{
			f[i] = 1;
			cnt++;
			dfs(i);
			cnt--;
			f[i] = 0;
		}
	}
	ma = max(ma,cnt);
	return;
}
