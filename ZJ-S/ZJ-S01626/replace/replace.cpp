#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int TT1=998244353,TT2=1e9+7;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,q;
string s1[N],s2[N];
int st[N],ed[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++){
		st[i]=0,ed[i]=s1[i].size()-1;
		while(s1[i][st[i]]==s2[i][st[i]])st[i]++;
		while(s1[i][ed[i]]==s2[i][ed[i]])ed[i]--;
	}
	while(q--){
		int now=0;
		string t1,t2;
		cin>>t1>>t2;
		int fst=0,fed=t1.size()-1;
		while(t1[fst]==t2[fst])fst++;
		while(t1[fed]==t2[fed])fed--;
		for(int i=1;i<=n;i++){
			if(fed-fst!=ed[i]-st[i])continue;
			int pt=0;
			while(pt<=fed-fst && s1[i][st[i]+pt]==t1[fst+pt] && s2[i][st[i]+pt]==t2[fst+pt])pt++;
			if(pt<=fed-fst)continue;
			//middle check over
			//s1[0,st[i]-1]  t1[0,fst-1]
			pt=0;
			if(fst<st[i])continue;
			while(pt<=st[i]-1 && s1[i][st[i]-1-pt]==t1[fst-1-pt])pt++;
			if(pt<=st[i]-1)continue;
			//s1[ed[i]+1,s1[i].size()] t1[fed+1,t1.size()]
			if(s1[i].size()-ed[i]>t1.size()-fed)continue;
			pt=ed[i]+1;
			while(pt<s1[i].size() && s1[i][pt]==t1[pt-ed[i]+fed])pt++;
			if(pt<s1[i].size())continue;
			now++;
		}
		write(now);putchar('\n');
	}
	return 0;
}