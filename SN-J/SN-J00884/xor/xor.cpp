#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],f[N],mx[N],pos[1<<20];
int sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(pos,-1,sizeof(pos));
	pos[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		if(pos[k^sum]!=-1) f[i]=mx[pos[k^sum]]+1;
		mx[i]=max(mx[i-1],f[i]);
		pos[sum]=i;
	}
	cout<<mx[n]<<'\n';
	return 0;
}
