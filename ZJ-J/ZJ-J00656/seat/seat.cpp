#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],ans,cnt,a1=1,a2=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1]) ans++;
	}
	while(1)
	{
		for(int i=2;i<=n;i++)
		{
			cnt++;
			a1++;
			if(cnt==ans) break;
		}
		if(cnt==ans) break;
		cnt++;
		a2++;
		if(cnt==ans) break;
		for(int i=n-1;i>=1;i--)
		{
			cnt++;
			a1--;
			if(cnt==ans) break;
		}
		if(cnt==ans) break;
		cnt++;
		a2++;
		if(cnt==ans) break;
	}
	cout<<a2<<" "<<a1;
	return 0;
}
