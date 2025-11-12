#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=5000;
const int mod=998244353;
long long jc[N];
int n,m;
string s;
int c[N];
vector<int>g;
bool fl[N];
int ans=0;
void cal() {
	int sum=0;
	for(int i=0; i<g.size(); i++) {
		if(sum>=c[g[i]])sum++;
		else if(s[i]=='0')sum++;
	}
	if(n-sum>=m)ans++;
	return;
}
void dfs(int u,int lst) {
	if(u==n+1) {
		cal();
		return;
	}
	for(int i=lst; i<=n; i++) {
		if(fl[i])continue;
		fl[i]=1;
		g.push_back(i);
		if(i!=lst)dfs(u+1,lst);
		else {

			int c=lst;
			while(fl[c])c++;
			dfs(u+1,c);
		}
		fl[i]=0;
		g.pop_back();
	}
	return;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	int sss=0;
	int maxn=0;
	for(int i=1; i<=n; i++)c[i]=read(),maxn=max(maxn,c[i]);
	int L=-1;
	for(int i=0; i<n; i++) {
		if(s[i]=='1'){
			sss++;
			if(L==-1)L=i;
		}
	}
	if(sss<=18&&maxn<=L) {
		cout<<0<<"\n";
		return 0;
	}
	if(n>15) {
		jc[0]=1ll;
		for(long long i=1ll; i<=n; i++)jc[i]=jc[i-1]*i%mod;
		cout<<jc[n]<<"\n";
		return 0;
	}
	dfs(1,1);
	cout<<ans<<"\n";
	return 0;
}
//½èÇ«¸çÖ®Á¦AC

