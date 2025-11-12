#include <bits/stdc++.h> 
using namespace std;
struct ff{
	string s;
	string t;
	int l;
}d[200005];
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		cin>>d[i].s>>d[i].t;
		d[i].l=0;
	}
	while(q--)
	{
		int ans=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<n;j++)
			{
				string h,x,z;
				for(int k=0;k<j;k++)
				{
					x+=a[k];
				}
				for(int k=j;k<j+d[j].s.size();k++)
				{
					h+=a[k];
				}
				for(int k=j+d[j].s.size();k<a.size();k++)
				{
					z+=a[k];
				}
				if(h==d[j].s&&x+d[j].t+z==b&&d[j].l==0)
				{
					ans++;
					d[j].l=1;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
