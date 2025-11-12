#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,a[N],sum[N],v[N];
int dfs(int x)
{
	if(v[x]!=-1) return v[x];
	int mx=0;
	for(int i=x+1;i<=n;i++)
	{
		int c=dfs(i);
		if((sum[x]^sum[i])==k) c++;
		mx=max(mx,c);
	}
	return v[x]=mx;
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	v[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		v[i]=-1,sum[i]=(sum[i-1]^a[i]);
	}
	int mx=0;
	for(int i=0;i<n;i++) mx=max(mx,dfs(i));
	cout << mx;
	
	return 0;
}