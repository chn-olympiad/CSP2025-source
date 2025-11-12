#include<bits/stdc++.h>
using namespace std;
string shou,wei;
int a[200005],cc,cw,dw;
string c,d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>c>>d;
		cc=c.length();
		for(int j=0;j<cc;j++)
		{
			if(c[j]=='b')
			{
				cw=j;
				break;
			}
		}
		for(int j=0;j<cc;j++)
		{
			if(d[j]=='b')
			{
				dw=j;
				break;
			}
		}
		a[i]=cw-dw;
	}
	sort(a,a+n);
	int Genshin=0,Duckov=0,sgs=0;
	for(int i=0;i<q;i++)
	{
		cin>>shou>>wei;
		cc=shou.length();
		for(int j=0;j<cc;j++)
		{
			if(shou[j]=='b')
			{
				cw=j;
				break;
			}
		}
		for(int j=0;j<cc;j++)
		{
			if(wei[j]=='b')
			{
				dw=j;
				break;
			}
		}
		Genshin=cw-dw;
		Duckov=0;
		sgs=0;
		for(int j=0;j<n;j++)
		{
			if(!Duckov && a[j]==Genshin)
			{
				Duckov=j;
			}
			if(Duckov && a[j]!=Genshin)
			{
				sgs=j;
				break;
			}
		}
		cout<<sgs-Duckov<<endl;
	}
}
//不是今年怎么这么难 

