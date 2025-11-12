#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010];
int res[1010][1010];
int resa[1010],resb[1010];
int finres[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=0;
	for(int i=1;i<=n;i++)
	{
		res[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			res[i][j]=res[i][j-1] xor a[j];
			if(res[i][j]==k)	resa[++p]=i,resb[p]=j;
		}
	}
	for(int i=p;i>=1;i--)
	{
		bool fl=0;
		for(int j=i+1;j<=p;j++)
		{
			if(resb[i]>resa[j])
				finres[i]+=finres[j],fl=1;
		}
		if(!fl)
			finres[i]=1;
		ans=max(ans,finres[i]);
		
	}
	cout<<ans;
	return 0;
}

