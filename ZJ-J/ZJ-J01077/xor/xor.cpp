#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==0)
	{
		cout<<0;
	}
	if(n==1)
	{
		if(a[1]==k)cout<<1;
		else cout<<0;
	}
	if(n==2)
	{
		int x=(a[1]^a[2]);
		if(a[1]==k && a[2]==k)
		{
			cout<<2;
			return 0;
		}
		if(a[1]==k || a[2]==k || a[3]==k)
		{
			cout<<1;
		}
	}
	return 0;
}
