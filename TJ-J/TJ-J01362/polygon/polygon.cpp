#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1||n==2)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<n-2;
	}
	return 0;
}
