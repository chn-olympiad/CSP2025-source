#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10;
const int mod=998244353;
int n,maxn,sum,ans;
int a[N];
int f[N][N];
void solve1(){
	if(n<=2){
		cout<<0<<'\n';
		return;
	}
	cout<<1<<'\n';
	return;
}
void dfs(int x,int len,int maxlen,int cnt){
	if(x==n+1){
		if(cnt>=3&&len>2*maxlen){
			ans++;
	//		cout<<len<<' '<<maxlen<<'\n';
		}
		return;
	}
	dfs(x+1,len+a[x],max(maxlen,a[x]),cnt+1);
	dfs(x+1,len,maxlen,cnt);
}
void solve2(){
//	dfs(1,a[1],a[1],1);
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return;
}
bool cmp(int x,int y){
	return x>y;
}
void solve3(){
	int cnt;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==0)break;
		cnt=i;
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			ans+=(cnt-j);
		}
	}
	cout<<ans<<'\n';
	return;
}
void solve4(){
	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn+=a[i];
		sum=max(sum,a[i]);
	}
	swap(sum,maxn);
	sort(a+1,a+n+1);
	if(n<=3){
		solve1();
		return 0;
	}else if(n<=20){
		solve2();
		return 0;
	}else if(n<=500&&maxn<=1){
		solve3();
		return 0;
	}
	swap(sum,maxn);
//	f[1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[j][a[i]+a[j]]=1;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=maxn;j++){
			f[i][j]+=f[i-1][j];
			if(j>a[i]&&j-a[i]>a[i]){
				f[i][j]+=f[i-1][j-a[i]];
			}
			f[i][j]%=mod;
//			cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+a[j]>=a[1]+a[2]+a[3]){
				f[n][a[i]+a[j]]--;
			}
		}
	}
	for(int j=a[1]+a[2]+a[3];j<=maxn;j++){
		ans+=f[n][j];
//		cout<<n<<' '<<j<<' '<<f[n][j]<<'\n';
		ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}
