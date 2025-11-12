//王梓乔 SN-S00500 西安高新第一初级中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int mod=998244353;
int n,m;
string s;
int ans;
int c[25];
bool fl[25];
inline void dfs(int now,int l,int cnt){
	if(now>n){
		if(l>=m)	ans+=1;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(fl[i]==0){
			fl[i]=1;
			if(cnt>=c[i]||s[now]=='0')	dfs(now+1,l,cnt+1);
			else	dfs(now+1,l+1,cnt);
			fl[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++)	c[i]=read();
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/

