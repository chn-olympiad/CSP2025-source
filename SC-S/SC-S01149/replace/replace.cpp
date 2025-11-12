#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4e5+10;
struct node
{
	string a,b;
}ss[maxn];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>ss[i].a>>ss[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		string oldstr,newstr;
		int len,sum=0;
		cin>>oldstr>>newstr;
		len=oldstr.length();
		for(int j=1;j<=n;j++)
		{
			string strf,strs;
			strf=ss[j].a;
			strs=ss[j].b;
			int lenx;
			lenx=strf.length();
			if(len<lenx)
			{
				continue;
			}
			for(int k=0;k<=len-lenx;k++)
			{
				int num=0;
				string doldstr,dnewstr;
				doldstr=oldstr;
				dnewstr=newstr;
				for(int m=k;m<=k+lenx-1;m++)
				{
					doldstr[m]=strs[num];
					num++;
				}
				if(doldstr==dnewstr)
				{
					sum++;
					break;
				}
			}
		}
		cout<<sum<<"\n";
	}
 	return 0;
}
