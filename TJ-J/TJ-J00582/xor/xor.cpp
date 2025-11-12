#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int a[500005];
int f[500005];
int tong[1050000];
int sum(int l,int r)
{
	return f[r]^f[l-1];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	int last=0;
	int cnt=0;
	memset(tong,-1,sizeof(tong));
	tong[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(tong[f[i]^k]>=last)
		{
			last=i;
			cnt++;
		}
		tong[f[i]]=i;
	}
	cout<<cnt;
	return 0;
}
