#include<bits/stdc++.h>
using namespace std;
long long n,k,f[1001][1001],num=0,ans=0,t=0;
struct itoj
{
	int s,e;
} d[100001];
bool cmp(itoj a,itoj b)
{
	if(a.s==b.s) return a.e<b.e;
	else return a.s<b.s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[i][i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^f[j][j];
			if(f[i][j]==k) d[num++].s=i,d[num].e=j;
		}
	}
	sort(d+1,d+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		if(d[i].s<t)
		{
			ans++;
			t=d[i].e;
		}
	}
	cout<<ans;
	return 0;
}
