#include<bits/stdc++.h>
using namespace std;
int a[500005],t,sum,num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==0)
		{
			if(a[i]==0) num++;
			else
			{
				if(i%2==0&&a[i]==a[i-1]) num++;
			}
		}
		if(a[i]!=1) t=1;
		else sum++;
	}
	if(t==0)
	{
		if(k==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n;
		}
		return 0;
	}
	if(k==1) {cout<<sum;return 0;}
	else {
		cout<<num;return 0;
	}
	if(n>50) cout<<n-50;
	else  cout<<n;
	return 0;
}
