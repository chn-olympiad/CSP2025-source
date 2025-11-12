#include<bits/stdc++.h>
using namespace std;

const int N=5010;
int n,sum,maxi;
int a[N];

bool check(int he,int maxi)
{
	if(he>2*maxi)  return true;
	else return false;
}

void dfs(int u,int v,int he,int maxi)
{
	if(v>n&&u>=3){
	    if(check(he,maxi))  sum=sum%998244353+1;
	    return ;
	}
	for(int i=v;i<=n;i++)
	{
		int m=maxi;
		maxi=max(m,a[i]);
		dfs(u+1,v+1,he+a[i],maxi);
		maxi=min(m,a[i]);
	}
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0,0);
	cout<<sum;
	return 0;
}
