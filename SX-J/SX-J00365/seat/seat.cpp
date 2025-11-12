#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
bool px(long long a,long long b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,f,l=1,r=1,s=0;
	bool z=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	f=a[0];
    sort(a,a+n*m,px);
    for(int i=0;i<n*m;i++)
	{
		if(a[i]==f)
		{
			s=i+1;
			break;
		}
	}
	int i=1,j=0;
    for(i=1;i<=s;i++)
    {
		if(z==1) r++;
		if(z==0) r--;
		if(r>n) l++,z=0;
		if(r<1) r++,l++,z=1;
	}
	cout<<l<<" "<<r;
}