#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans=0;
struct node
{
	string a,b;
}a[501000];
struct nobe
{
	string a,b,c;
}b[500100];
struct noee
{
	string a,b,c;
}c[5001000];
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	string r,l;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	for(int k=1;k<=q;k++)
	{
		cin>>r>>l;
		int len=r.size();
		int lan=l.size();
		for(int i=0;i<len;i++)
		{
			string t;
			for(int j=0;j<=i;j++)
			{
				ans++;
				b[ans].a=a[k].a.substr(0,i);
				b[ans].b=a[k].a.substr(i,j-i+1);
				b[ans].c=a[k].a.substr(j-i+1,len-1-j+i-1);
				c[ans].a=b[k].a.substr(0,i);
				c[ans].b=b[k].a.substr(i,j-i+1);
				c[ans].c=b[k].a.substr(j-i+1,len-1-j+i-1);
				cout<<b[ans].a<<' '<<b[ans].b<<' '<<b[ans].c;
				cout<<' '<<c[ans].a<<' '<<c[ans].b<<' '<<c[ans].c<<endl;
			}
		}
}

	return 0;
}
