#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e5+5;
int a[maxn][4];
int cnt[4];
bool vis[maxn];
int T,n,ans;
void dfs(int x,int y,int sum){
	if(cnt[y]>n/2) return;
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		cnt[i]++;
		dfs(x+1,i,sum+a[x][i]);
		cnt[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		int nn=n*2;
		for(int i=1;i<=n;++i){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		}
		dfs(0,0,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}