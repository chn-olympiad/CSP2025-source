#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn,cnt=0;
	cin>>n;
	int a[5000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
	}
	maxn=a[n]*2;
	if(cnt>maxn)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
