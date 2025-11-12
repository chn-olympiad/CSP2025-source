#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int s=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') s=-1;c=getchar();}
	while('0'<=c&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	return k*s;
}
void out(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) out(x/10);
	putchar(x%10^48);
}
const int MAXN=505;
const int mod=998244353;
int n,m;
char s[MAXN];
int pat[MAXN];
bool vis[MAXN];
int ans=0;
void dfs(int day,int tot){
	if(day==n+1){
		if(tot>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
//		if(pat[i]>day-tot) dfs(day+1,tot+1);
//		else dfs(day+1,tot);
		if(s[day]=='0') dfs(day+1,tot);
		else dfs(day+1,tot+(pat[i]>day-tot-1));
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(); m=in();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) pat[i]=in();
	dfs(1,0);
	out(ans);
	return 0;
}
/*
3 2
101
1 1 2
*/