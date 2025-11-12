#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
inline long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return f*x;
}

int d[N][4];
ll ans[N];
int now[4];
inline void dfs(int i,int op,int n,ll up){
	if(now[op]>=(n>>1)) return;
	if(i>n) return;
//	if(ans[i-1]+d[i][op]<ans[i]) return;
	now[op]++;
	up+=d[i][op];
	ans[i]=max(ans[i],up);
//	cout<<now[0]<<now[1]<<now[2]<<'\n';
	dfs(i+1,0,n,up),dfs(i+1,1,n,up),dfs(i+1,2,n,up);
	now[op]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=read();
	while(t--){
		memset(ans,0,sizeof(ans));
		now[0]=now[1]=now[2]=0;
		int n=read();
		for(int i=1;i<=n;i++){
			d[i][0]=read(),d[i][1]=read(),d[i][2]=read();
			
		}
		dfs(1,0,n,0),dfs(1,1,n,0),dfs(1,2,n,0);
		cout<<ans[n]<<'\n';
	}
	return 0;
} 
//freopen(Æ­ÄãµÄ£¬Ô­µØÍËÒÛ 
