#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>
#define rd read()
#define x first
#define y second
#define y1 Y1
#define y0 Y0
char buf[(1<<21)+10],obuf[(1<<21)+10],*p1=buf,*p2=buf,*O=obuf;int ol=(1<<21);
#define getchar() (((p1==p2)&&(p2=((p1=buf)+fread(buf,1,ol,stdin)),p1==p2))?EOF:*p1++)
#define flush() (fwrite(obuf,1,O-obuf,stdout),O=obuf)
#define putchar(x) (((O-obuf==ol)&&(flush(),O-obuf==ol))?:*O++=x)
inline int read(int u=0,char c=getchar(),bool f=false){
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}
inline void read(string &s,char c=getchar()){
	for(;c<'a'||c>'z';c=getchar());s.clear();
	for(;c>='a'&&c<='z';c=getchar()) s+=c;
}
inline void wt(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}
inline void wt(int x,char c){wt(x);putchar(c);}
const int N=2e5+10,M=5e6+10,mod1=998244353,mod2=1e9+7,seed=37;
int n,q,id,sz[N],szl[M],szr[M];string s1[N],s2[N];
P pre[N],suf[N];
map<P,int>mp;vector<int>e[N];
//vector<int>tr[N][26],fail[N],ed[N];
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd,q=rd;
	for(int i=1;i<=n;i++){
		int sum1=0,sum2=0,su1=0,su2=0;
		read(s1[i]);read(s2[i]);
		string t1=s1[i],t2=s2[i];int l1=0,r1=t1.size()-1;
		if(t1==t2) continue;
		while(t1[l1]==t2[l1]) l1++;
		while(t1[r1]==t2[r1]) r1--;
		for(int i=l1;i<=r1;i++) sum1=(sum1*seed+t1[i])%mod1,sum2=(sum2*seed+t2[i])%mod1;su1=sum1*mod1+sum2;sum1=sum2=0;
		for(int i=l1;i<=r1;i++) sum1=(sum1*seed+t1[i])%mod2,sum2=(sum2*seed+t2[i])%mod2;su2=sum1*mod2+sum2;sum1=sum2=0;
		if(!mp[{su1,su2}]) mp[{su1,su2}]=++id;
		e[mp[{su1,su2}]].push_back(i);//sz[mp[{su1,su2}]]+=t1.size();
		for(int i=l1-1;i>=0;i--) sum1=(sum1*seed+t1[i])%mod1,sum2=(sum2*seed+t1[i])%mod2;pre[i]={sum1*mod2+sum2,l1};sum1=sum2=0;
		for(int i=r1+1;i<t1.size();i++) sum1=(sum1*seed+t1[i])%mod2,sum2=(sum2*seed+t1[i])%mod2;suf[i]={sum1*mod2+sum2,t1.size()-r1-1};
	}
//	for(int i=1;i<=id;i++){
//		fail[i].resize(sz[i]+10);ed[i].resize(sz[i]+10);
//		for(int j=0;j<26;j++) tr[i][j].resize(sz[i]+10);int cnt=0;
//		for(int j:e[i]){
//			int now=0;
//			for(char c:s1[j]){
//				if(!tr[i][c-'a'][now]) tr[i][c-'a'][now]=++cnt;
//				now=tr[i][c-'a'][now];
//			}ed[i][now]++;
//		}queue<int>q;
//		for(int j=0;j<26;j++) if(tr[i][j][0]) fail[i][tr[i][j][0]]=0,q.push(tr[i][j][0]);
//		while(!q.empty()){
//			int u=q.front();q.pop();ed[i][u]+=ed[i][fail[i][u]];
//			for(int j=0;j<26;j++)
//				if(tr[i][j][u]) fail[i][tr[i][j][u]]=tr[i][j][fail[i][u]],q.push(tr[i][j][u]);
//				else tr[i][j][u]=tr[i][j][fail[i][u]];
//		}
//	}
	while(q--){
		string t1,t2;int ans=0;
		read(t1);read(t2);
		if(t1.size()!=t2.size()){wt(0,'\n');continue;}
		int l1=0,r1=t1.size()-1;
		while(t1[l1]==t2[l1]) l1++;
		while(t1[r1]==t2[r1]) r1--;
		int sum1=0,sum2=0,su1=0,su2=0;
		for(int i=l1;i<=r1;i++) sum1=(sum1*seed+t1[i])%mod1,sum2=(sum2*seed+t2[i])%mod1;su1=sum1*mod1+sum2;sum1=sum2=0;
		for(int i=l1;i<=r1;i++) sum1=(sum1*seed+t1[i])%mod2,sum2=(sum2*seed+t2[i])%mod2;su2=sum1*mod2+sum2;sum1=sum2=0;
		if(!mp[{su1,su2}]){wt(0,'\n');continue;}
		int idi=mp[{su1,su2}],now=0;
//		for(int i=0;i<r1;i++) now=tr[idi][t1[i]-'a'][now];
//		for(int i=r1;i<t1.size();i++){
//			now=tr[idi][t1[i]-'a'][now];
//			ans+=ed[idi][now];
//		}
		szl[l1]=szr[r1]=0;
		for(int i=l1-1;i>=0;i--) sum1=(sum1*seed+t1[i])%mod1,sum2=(sum2*seed+t1[i])%mod2,szl[i]=sum1*mod2+sum2;sum1=sum2=0;
		for(int i=r1+1;i<t1.size();i++) sum1=(sum1*seed+t1[i])%mod2,sum2=(sum2*seed+t1[i])%mod2,szr[i]=sum1*mod2+sum2;
		for(int i:e[idi]) if(pre[i].y<=l1&&suf[i].y<=t1.size()-1-r1&&szl[l1-pre[i].y]==pre[i].x&&szr[r1+suf[i].y]==suf[i].x) ans++;
		wt(ans,'\n');
	}
	return flush(),0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
