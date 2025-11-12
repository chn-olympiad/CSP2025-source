#include<bits/stdc++.h>
using namespace std;
int n;
long long a[50005];
long long m,s,x;
void dfs(int k)
{
//	cout<<x<<" "<<a[k-1]<<"\n";
	if(x>a[k-1]*2)
	{
//		cout<<"\\\\";
		s=(s+1)%998244353;
	}
	for(int i=k;i<n;i++)
	{
		x+=a[i];
		dfs(i+1);
		x-=a[i];
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	m=0; s=0; x=0;
	dfs(0);
	cout<<s;
	return 0;
}