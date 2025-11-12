#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e6+10,bas1=13331,mod1=1e9+9;
struct node
{
	int len;
	ull hs1,hs2;
}th[N],xw[N];
int n,q,cnt;
ull hs1[N],hs2[N],pw[N];
char s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>(s1+1)>>(s2+1);
		th[i].len=strlen(s1+1);int vis=1;
		for(int j=1;j<=th[i].len;j++)
		{
			if(s1[j]!=s2[j])vis=0;
			th[i].hs1=(th[i].hs1*bas1%mod1+s1[j]-'a'+1)%mod1;
			th[i].hs2=(th[i].hs2*bas1%mod1+s2[j]-'a'+1)%mod1;
		}
		if(vis)cnt++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>(s1+1)>>(s2+1);
		int len=strlen(s1+1),pre,nxt;
		for(pre=1;pre<=len;pre++)
			if(s1[pre]!=s2[pre])break;
		for(nxt=len;nxt>=1;nxt--)
			if(s1[nxt]!=s2[nxt])break;
		pw[0]=1;
		for(int j=1;j<=len;j++)
		{
			hs1[j]=(hs1[j-1]*bas1%mod1+s1[j]-'a'+1)%mod1;
			hs2[j]=(hs2[j-1]*bas1%mod1+s2[j]-'a'+1)%mod1;
			pw[j]=pw[j-1]*bas1%mod1;
		}
		int ans=0;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=th[j].len;k++)
			{
				int l=pre-k+1,r=l+th[j].len-1;
				if((hs1[r]-hs1[l-1]*pw[r-l+1]%mod1+mod1)%mod1==th[j].hs1&&(hs2[r]-hs2[l-1]*pw[r-l+1]%mod1+mod1)%mod1==th[j].hs2&&r>nxt&&l>=1&&r<=len)ans++;
			}
		if(pre!=len+1)cout<<ans<<'\n';
		else cout<<cnt<<'\n';
	}
	return 0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>s1>>s2;
//		int len=strlen(s1);
//		for(int j=0;j<len;j++)
//		{
//			if(s1[j]=='b')th[i].wz1=j;
//			if(s2[j]=='b')th[i].wz2=j;
//		}
//		th[i].z=th[i].wz1-th[i].wz2;
//	}
//	sort(th+1,th+n+1,cmp);
//	for(int i=1;i<=q;i++)
//	{
//		cin>>s1>>s2;
//		int len=strlen(s1);
//		for(int j=0;j<len;j++)
//		{
//			if(s1[j]=='b')xw[i].wz1=j;
//			if(s2[j]=='b')xw[i].wz2=j;
//		}
//		xw[i].z=xw[i].wz1-xw[i].wz2;
//		xw[i].id=i;
//	}
//	sort(xw+1,xw+q+1,cmp);
//	int las=0,now=1; 
//	for(int i=1;i<=q;i++)
//	{
//		while(now<=n&&th[now].z!=xw[i].z)las=now,now++;
//		while(now<=n&&th[now].wz1<=xw[i].wz1)now++;
//		ans[xw[i].id]=now-las-1;
//	}
//	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
//	cout<<'\n';
	return 0;
}