#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[200];
	int cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			cnt++;
		}
	}
	if(cnt%m==0)
	{
		if(cnt/m%2==0)
		{
			cout<<cnt/m<<' '<<1;
		}
		else
		{
			cout<<cnt/m<<' '<<n;
		}
	}
	else
	{
		int tmp=floor(cnt/m);
		if(tmp%2==1)
		{
			cout<<tmp+1<<' '<<(n-cnt%m);
		}
		else
		{
			cout<<tmp+1<<' '<<cnt%m;
		}
	}
	return 0;
}
