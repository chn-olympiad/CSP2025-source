#include<bits/stdc++.h>
using namespace std;
const int P=5006;
int n;
long long a[P],smax=0,ans=0;
void dfs(int picked,long long  sum,int flag)
{
	if(picked>n) return;
	smax=a[flag-1];
	if(picked>=3 && sum>2*smax) ans++;
	for(int i=flag;i<n;i++) dfs(picked+1,sum+a[i],i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
