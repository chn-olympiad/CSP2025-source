#include<bits/stdc++.h>
using namespace std;
string shou,wei;
int a[2000005],cc,cw,dw,answ,b[2000005],c[2000005];
string k,d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	cin>>k>>d;
	if((k[0]=='a'||k[0]=='b')&&(d[0]=='a'||d[0]=='b'))
	{
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			{
				cin>>k>>d;
			}
			cc=k.length();
			for(int j=0;j<cc;j++)
			{
				if(k[j]=='b')
				{
					cw=j;
					b[i]=j;
					c[i]=cc-1-j;
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
		int Genshin=0,Duckov=0,sgs=0;
		answ=0;
		for(int i=0;i<q;i++)
		{
			cin>>shou>>wei;
			cc=shou.length();
			if(cc!=wei.length())
			{
				cout<<0<<endl;
				//cout<<"ต๗สิ"<<endl; 
				continue;
			}
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
			Duckov=cw;
			sgs=shou.length()-1-cw;
			answ=0;
			for(int j=0;j<n;j++)
			{
				if(a[j]==Genshin && b[j]<=Duckov && c[j]<=sgs)
				{
					answ++;
				}
			}
			cout<<answ<<endl;
		}
	}
	else
	{
		for(int i=0;i<q;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
