#include<bits/stdc++.h>
using namespace std;
int a[10000],n;
const int MOD=998244353;
int fun(int x,int maxn,int tot,bool b)
{
	int k=0;
	if(x>n)
	return 0;
	if(tot!=0 and maxn!=0 and !b)
	if(tot>maxn*2)
	return (fun(x+1,maxn,tot,1)+1+fun(x+1,max(maxn,a[x]),tot+a[x],0))%MOD;
	if(x==n)
	return 0;
	return (fun(x+1,maxn,tot,1)+fun(x+1,max(maxn,a[x]),tot+a[x],0))%MOD;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<fun(0,0,0,0);
	return 0;
}
