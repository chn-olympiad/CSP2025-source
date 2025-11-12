#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005],b[500005],f[500005];
map<pair<int,int>,bool>vis;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	a[1]=b[1];
	for(int i=2;i<=n;i++)
		a[i]=a[i-1]^b[i];
	for(int i=n;i>=1;i--)
	{
		int r=-1;
		for(int j=i;j>=1;j--)
			if(!vis[make_pair(i,j)]&&(a[i]^a[j-1])==k&&f[i]<f[i+1]+(a[i]^a[j-1]))
				f[i]=f[i+1]+k,r=j;
		if(r!=-1)
		{
			for(int j=i;j>=1;j--)
				vis[make_pair(i,j)]=true;
			for(int j=r;j<=n;j++)
				vis[make_pair(r,j)]=true;
		}
		else
			f[i]=f[i+1];
	}
	printf("%d",f[1]);
	return 0;
}

