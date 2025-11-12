#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
struct idxx
{
	long long lf,rt;
}idx[maxn];
long long n,k;
long long a[maxn],qz[maxn],f[maxn],tp=0,num=0,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	memset(idx,-1,sizeof(idx));
	qz[0]=0;
	for(int i=1;i<=n;i++)
	{
		qz[i]=a[i] xor qz[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>tp;j--)
		{
			if((qz[i] xor qz[j-1])==k)
			{
				num++;
				tp=j;
				idx[num].lf=j;
				idx[num].rt=i;
			}
		}
	}
	for(int i=1;i<=num;i++)
	{
		f[i]=1;
		for(int j=i-1;j>=1;j--)
		{
			if(idx[j].rt<idx[i].lf)
			{
				f[i]=f[j]+1;
				break;
			}
		}
		ans=max(ans,f[i]);
	}
	cout << ans << "\n";
	return 0;
}

