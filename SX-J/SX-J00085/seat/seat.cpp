#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
long long n,m,a[N],s=0,s1=1,s2=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
	    cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[1]<a[i])
		{
			s++;
		}
	}
	for(int i=1;i<=s;i++)
	{
		if(s2!=m)
		{
			s2++;
		}
        else if(s2!=1)
		{
			s1++;
			s2--;
			if(s2==1)
			{
				s1++;
				s2++;
			}
		}
	}
	if(s==0)
	{
		cout<<1<<" "<<1;
	}
	else
	{
		cout<<s1<<" "<<s2;
	}
	return 0;
}