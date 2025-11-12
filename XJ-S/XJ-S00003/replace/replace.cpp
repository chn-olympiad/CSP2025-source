#include<bits/stdc++.h>
using namespace std;
string a[20005],a1[20005],b[20005],b1[20005];
int find(string ax,string bx)
{
	for(int i=0;i<=ax.size()-bx.size();i++)
	{
		if(ax[i]==bx[0])
		{
			int t=0;
			while(ax[i+t]==bx[0+t])
			{
				t++;
			}
			if(t==bx.size())
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
		freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a1[i]>>b1[i];
	}
	for(int i=1;i<=q;i++)
	{
		int m=0;
		for(int j=1;j<=n;j++)
		{
			
			if(a[j].size()>a1[i].size()||b[j].size()>b1[i].size())
			{
				continue;
			}
			else if(find(a1[i],a[j])&&find(b1[i],b[j]))
			{
				m++;
			}
		}
		cout<<m<<endl;
	}
}
