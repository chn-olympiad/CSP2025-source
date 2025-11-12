#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a1[N],b1[N],c1[N],h,a,b,c,ls[N];
void solve()
{
 	h=0;
	a=0;
	b=0;
	c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a1[i]>>b1[i]>>c1[i];
		if(a1[i]>=max(b1[i],c1[i]))
		{
			a++;
			h+=a1[i];
			continue;
		}
		if(b1[i]>=max(a1[i],c1[i]))
		{
			b++;
			h+=b1[i];
			continue;
		}
		if(c1[i]>=max(b1[i],a1[i]))
		{
			c++;
			h+=c1[i];
			continue;
		}
	}
	if(a>n/2)
	{
		int m=0;
		for(int i=0;i<n;i++)
		{
			if(a1[i]>=max(b1[i],c1[i]))
			{
    		ls[i]=a1[i]-max(b1[i],c1[i]);
			}else{
				ls[i]=100000;
			}
		}
		sort(ls,ls+n);
		while(a>n/2)
		{
			a--;
			h-=ls[m++];
		}
	}
	if(b>n/2)
	{
		int m=0;
		for(int i=0;i<n;i++)
		{
			if(b1[i]>=max(a1[i],c1[i]))
			{
				ls[i]=b1[i]-max(a1[i],c1[i]);
			}else{
				ls[i]=100000;
			}
		}
		sort(ls,ls+n);
		while(b>n/2)
		{
			b--;
			h-=ls[m++];
		}
	}
	if(c>n/2)
	{
		int m=0;
		for(int i=0;i<n;i++)
		{
			if(c1[i]>=max(a1[i],b1[i]))
			{
				ls[i]=c1[i]-max(a1[i],b1[i]);
			}else{
				ls[i]=100000;
			}
		}
		sort(ls,ls+n);
		while(c>n/2)
		{
			c--;
			h-=ls[m++];
		}
	}
	cout<<h<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
  	solve();
	}
	return 0;
}