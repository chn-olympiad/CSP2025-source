#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,i,j,a[500001],s,st,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	s=0;
	st=0;
	for(i=1;i<=n;i++)
	{
		for(j=st;j<i;j++)
		{
			x=a[i]^a[j];
			if(x==k)
			{
				st=i;
				s++;
				break;
			}
		}
	}
	cout<<s<<"\n";
	return 0;
}
/*
10 5
1 2 3 1 2 2 2 3 1 2
0 1 1 1 1 1 1 1 0 0
*/
