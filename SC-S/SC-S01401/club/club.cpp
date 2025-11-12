#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
const int maxn=1e5+20;
#define ll long long
ll n,T,a[maxn][3],cnt[3],ans,val[maxn];
priority_queue<ll> q;
inline void calc(int x){
	for(int i=1;i<=n;i++){
		if(val[i]!=x) continue;
		ll mx=-1;
		for(int j=0;j<=2;j++) if((j^x)) mx=max(mx,a[i][j]);
		q.push(mx-a[i][x]);
	}
	while(cnt[x]>n/2) ans+=q.top(),q.pop(),cnt[x]--;
}
inline void solve(){
	n=read();while(!q.empty()) q.pop();
	ans=0,cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		ll mx=-1,k=-1;
		for(int j=0;j<=2;j++){
			a[i][j]=read();
			if(a[i][j]>mx) k=j,mx=a[i][j];
		} 
		cnt[k]++,ans+=mx,val[i]=k;
	} 
	for(int i=0;i<=2;i++) if(cnt[i]>n/2) calc(i);
	printf("%lld\n",ans);
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/