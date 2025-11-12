#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans=0;
int f[(1<<20)+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,now=0;
	for(int i=1;i<=n;i++)
	{
		now^=a[i];
		int xy=k^now;
		if(now==k)
		{
			ans++;
			l=i+1;
			now=0;
			continue;
		}
		if(f[xy]==l) 
		{
			ans++;
			l=i+1;
			now=0;
			continue;
		}
		f[now]=l;
	}
	cout<<ans<<endl;
	return 0;
}
