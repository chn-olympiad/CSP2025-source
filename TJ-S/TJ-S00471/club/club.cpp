#include<bits/stdc++.h>
using namespace std;
int t,n,a[5],maxx,s,p;
long long b[20001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=3;x++)
			{
				cin>>a[x];
			}
			if(a[2]==0 and a[3]==0)
			{
				b[j]=a[1];
				p++;
			}
		}	
		if(p==n)
		{
			sort(b+1,b+n+1);
			for(int z=1;z<=n;z++)
			{
				s+=b[z];
			}
			cout<<s;
		}
		
	} 
	return 0;
}
