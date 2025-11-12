#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],b[N],h;
void dfs(int p,int l,int s,int y,bool g)
{

	if(l>y)
	{
		return;
	}
	if(p>a[y]&&s>=3&&g==1)
	{
		h++;
	}
	dfs(p+a[l],l+1,s+1,y,1);
	dfs(p,l+1,s,y,0);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<n;i++)
	{
		dfs(0,0,1,i,1);
	}
	cout<<h%998244353;
	return 0;
}