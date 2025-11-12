#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,z,f,ans,mxlen,len[200005],p[200005],s[200005],P,S;
string s1[200005],s2[200005],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		mxlen=max(mxlen,len[i]);
		s1[i]="%"+s1[i];
		s2[i]="%"+s2[i];
	}
	if(mxlen>2000)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			return 0;
		}
		z=t1.size();
		t1="%"+t1;
		t2="%"+t2;
		for(int i=1;i<=z;i++)
		{
			if(t1[i]=='b')P=i;
			if(t2[i]=='b')S=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=len[i];j++)
			{
				if(s1[i][j]=='b')p[i]=j;
				if(s2[i][j]=='b')s[i]=j;
			}
			if(P-S==p[i]-s[i]&&P>=p[i]&&z-S>=len[i]-s[i])ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;ans=0;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		z=t1.size();
		t1="%"+t1;
		t2="%"+t2;
		x=z+1;y=0;
		for(int j=1;j<=z;j++)if(t1[j]!=t2[j])
		{
			x=min(x,j);
			y=max(y,j);
		}
		for(int j=1;j<=x;j++)for(int k=z;k>=y;k--)
		{
			if(k<j)continue;
			for(int l=1;l<=n;l++)if(len[l]==k-j+1)
			{
				f=1;
				for(int m=j;m<=k;m++)if(t1[m]!=s1[l][m-j+1]||t2[m]!=s2[l][m-j+1])f=0;
				if(f)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
/*
Ren5Jie4Di4Ling5%
16:25 wtf so easy?just hash is ok or i am a (b   h)?
16:30 i understand the problem in a wrong way OvO. 
16:40 i can only solve 25pts,D first.
17:00 back to think C
17:20 i think i should start to write codes for C and D,only 249pts,sad
17:35 finisg 25pts,why wrong?
17:40 pass 25pts
18:15 i can solve 30pts now
18:25 finish 30pts
*/
