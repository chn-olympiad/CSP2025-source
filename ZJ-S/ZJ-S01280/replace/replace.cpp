#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,nn,la[200010],l,le[200010],ts,ans,ss[200010];
unsigned long long ha[200010][2],hs[200010][2],tt[5000010],st;
string t1[200010],t2[200010],s1,s2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	tt[0]=1ll;
	for(int i=1;i<=5000000;i++)
	{
		tt[i]=tt[i-1]*27;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t1[i]>>t2[i];
		nn=t1[i].size();
		le[i]=nn;
		la[i]=-1;
		for(int j=0;j<nn;j++)
		{
			ha[i][0]=ha[i][0]*27+t1[i][j]-'a';
			ha[i][1]=ha[i][1]*27+t2[i][j]-'a';
			if(t1[i][j]!=t2[i][j])
			{
				ss[i]++;
			}
			if(t1[i][j]!=t2[i][j]&&la[i]==-1)
			{
				la[i]=j;
			}
		}
	//	cout<<la[i]<<' ';
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		nn=s1.size();
		l=-1;
		st=0;
		for(int j=0;j<nn;j++)
		{
			if(s1[j]!=s2[j])
			{
				st++;
			}
			if(s1[j]!=s2[j]&&l==-1)
			{
				l=j;
			}
			hs[j][0]=s1[j]-'a';
			hs[j][1]=s2[j]-'a';
			if(j!=0)
			{
				hs[j][0]+=hs[j-1][0]*27;
				hs[j][1]+=hs[j-1][1]*27;
			}
	//		cout<<hs[j][0]<<':'<<hs[j][1]<<'\n';
		}
	//	cout<<l<<' ';
		ans=0;
		for(int j=1;j<=n;j++)
		{
			if(l>=la[j]&&st==ss[j])
			{
				if(l>la[j])ts=hs[l-la[j]-1][0];
				else ts=0;
		//		cout<<ha[j][0]<<' '<<hs[l-la[j]+le[j]-1][0]-ts*tt[le[j]]<<' '<<ts<<' '<<ha[j][0]<<'\n';
				if(ha[j][0]==hs[l-la[j]+le[j]-1][0]-ts*tt[le[j]])
				{
		//			cout<<j<<'k'<<'\n';
					if(l>la[j])ts=hs[l-la[j]-1][1];
					else ts=0;
					if(ha[j][1]==hs[l-la[j]+le[j]-1][1]-ts*tt[le[j]])
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}