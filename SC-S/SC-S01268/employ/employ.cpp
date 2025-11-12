#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],m,man[100010],ch,e[4];
int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ch=n/2;
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=3;y++)
			{
				cin>>a[x][y];
				man[x]=max(man[x],a[x][y])； 
			}
		}
		if(n==1)
		{
			cout<<man[1];
		}
	}
	return 0;
} 