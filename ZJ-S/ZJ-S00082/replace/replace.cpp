#include <bits/stdc++.h>
using namespace std;
struct node
{
	string x,y;
}a[500005];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		int cnt=0;
		cin>>s1>>s2;
		int len=s1.size();
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k+a[j].x.size()-1<len;k++)
			{
				string x,y,z;
				if(k==0) x="";
				else x=s1.substr(0,k);
				y=s1.substr(k,a[j].x.size());
				if(k+a[j].x.size()==len) z="";
				else z=s1.substr(k+a[j].x.size()); 
				if(y==a[j].x && x+a[j].y+z==s2)
				{
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}