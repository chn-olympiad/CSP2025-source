#include<bits/stdc++.h>
using namespace std;
const int inf=2*1e5+1;
int n,q,tp=-1,tl=-1,suc[inf],sov=0,ans=0;
string xie[inf],yuan[inf],yx[inf],gai[inf],dif="",cha="";
string s1,s2;
void pd()
{
	for(int i=1;i<=n;i++)
	{
		if(dif==yx[i]&&cha==gai[i])
		{
			sov++;
			suc[sov]=i;
		}
	}
}
void solve()
{
	int len=s1.size(),x=0,hd=inf,tail=-1,chl;
	bool zj=0;
	for(int i=1;i<=sov;i++)
	{
		chl=yuan[suc[i]].size();
		for(int j=0;j<=len;j++)
		{
			if(s1[j]==yuan[suc[i]][x])
			{
				hd=min(hd,j);
				tail=max(tail,j);
				zj=1;
				x++;
				if(x==chl)
				{
					break;
				}
			}
			else if(s1[j]==yuan[suc[i]][0])
			{
				hd=tail=j;
				x=1;
			}
			else
			{
				x=0;
				tail=-1;
				hd=inf;
				zj=0;
			}
		}
		if(zj==1)
		{
			zj=0,x=0;
			for(int j=hd;j<=tail;j++)
			{
				if(s2[j]!=xie[suc[i]][x])
				{
					zj=1;
					break;
				}
				x++;
			}
			if(zj==0)
			{
				ans++;
			}
		}
		zj=0;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>yuan[i]>>xie[i];
		int len,mx=-1,mn=inf,ln1=yuan[i].size(),ln2=xie[i].size();
			len=yuan[i].size();
			for(int j=0;j<=len;j++)
			{
				if(yuan[i][j]!=xie[i][j])
				{
					if(j<mn)
					{
						mn=j;
						tp=j;
					}
					if(j>mx)
					{
						mx=j;
						tl=j;
					}
				}
			}
			for(int j=tp;j<=tl;j++)
			{
				yx[i]+=yuan[i][j];
				gai[i]+=xie[i][j];
			}
		}
	while(q--)
	{
		memset(suc,0,sizeof(suc));
		sov=ans=0;
		dif="",cha="";
		cin>>s1>>s2;
		int len=s1.size(),mx=-1,mn=inf;
		for(int i=0;i<=len;i++)
		{
			if(s1[i]!=s2[i])
			{
				if(i<mn)
				{
					mn=i;
					tp=i;
				}
				if(i>mx)
				{
					mx=i;
					tl=i;
				}
			}
		}
		for(int i=tp;i<=tl;i++)
		{
			dif+=s1[i];
			cha+=s2[i];
		}
		pd();
		if(suc[1]==0)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			solve();
			cout<<ans<<"\n";
		}
	}
	return 0;
}
