#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=214514,N=5114514;
const ull base=131;
int n,q;
ull s1[M],s2[M],s3[N];
int len[M];
char s[N],t[N];
ull Pow[N];
struct Hash
{
	ull h[N];
	void init(char s[N],int n) {for(int i=1;i<=n;i++) h[i]=h[i-1]*base+s[i];}
	ull query(int l,int r) {return h[r]-h[l-1]*Pow[r-l+1];}
}hs,ht;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Pow[0]=1;
	for(int i=1;i<=5e6;i++) Pow[i]=Pow[i-1]*base;
	scanf("%d%d",&n,&q);
	for(int i=1,m;i<=n;i++)
	{
		scanf("%s",s+1),m=strlen(s+1);
		for(int j=1;j<=m;j++) s1[i]=s1[i]*base+s[j];
		scanf("%s",s+1),m=strlen(s+1);
		for(int j=1;j<=m;j++) s2[i]=s2[i]*base+s[j];
		len[i]=m;
		s3[i]=s1[i]*Pow[m]+s2[i];
	}
	while(q--)
	{
		scanf("%s%s",s+1,t+1);
		int m=strlen(s+1);
		if(m!=strlen(t+1)) {cout<<"0\n";continue;}
		int L=0,R=m;
		for(int i=1;i<=m;i++) if(s[i]!=t[i]) {L=i;break;}
		for(int i=m;i>=1;i--) if(s[i]!=t[i]) {R=i;break;}
		hs.init(s,m),ht.init(t,m);
		int ans=0;
		for(int i=R;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int l=i-len[j]+1,r=i;
				if(l>L) continue;
//				if(hs.query(l,r)==s1[j]&&ht.query(l,r)==s2[j]) ans++;
				ull v=hs.query(l,r)*Pow[r-l+1]+ht.query(l,r);
				if(v==s3[j]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

