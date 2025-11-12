#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
long long a[1000001];
int ck(int x)
{
	long long sum=0;
	while(x)
	{
		sum=sum*10+x%10;
		x=x/10;
	}
}
int ch(int x,int y)
{
	int q=a[x];
	for(int i=x+1;i<=y;i++)
	{
		q=q^a[i];
	}
	if(q==k)
	{
		return 1;
	}
	return 0;
}
void dfs(int l,int r)
{
	if(ch(l,r)==1)
	{
		ans++;
	}
	for(int i=l;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dfs(i,j);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=ck(x);
	}
	dfs(0,0);
	return 0;
}
