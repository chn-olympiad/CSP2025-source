#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod998244353=998244353;
inline int fastReadPo(){
	int s=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9'){f=(f||c=='-');c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}
int n,a[10005];
int d[10005];
int ans=0;
void solve(){
	int sum=0,ppp=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]*d[i];
//		cout<<(d[i]?'1':' ');
		if(d[i]) ppp=a[i]*2;
	}
	if(sum<=ppp) {
	
//	cout<<endl;
	return ;}
//	cout<<ppp<<' '<<sum<<' '<<"!!!!!"<<endl;
	ans++;
	ans%=mod998244353;
//	for(int i=1;i<=x;i++){
//		cout<<a[d[i]]<<' ';
//	}
}
void dfs(int x,int t){
	if(x==n+1&&t>=3){
		solve();
	}
	if(x==n+1) return ;
	d[x]=0;
	dfs(x+1,t);
	d[x]=1;
	dfs(x+1,t+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=fastReadPo();
	int sum=0;
	for(int i=1;i<=n;i++){
		a[i]=fastReadPo();
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
