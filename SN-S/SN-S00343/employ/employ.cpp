//李承恩 SN-S00343 西安湖滨中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,sum[N],h[N],ans,c[N],f[N][N];
char a[N];
void dfs(int x){
	if(x>n){
		int k=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'||k>=c[h[i]])k++;
		}
		if(n-k>=m)ans++;
		return;
	}
	h[x]=x;
	for(int j=1;j<=x;j++){
		swap(h[j],h[x]);
		dfs(x+1);
		swap(h[j],h[x]);
	}
}
void solve1(){
	dfs(1);
	cout<<ans;
}
//void solve2(){
//	num=0;
//	for(int i=1;i<=n;i++)if(a[i]=='1')h[++num]=i;
//	for(int i=1;i<(1<<num);i++){
//		int k=0;
//		for(int j=1;j<=num;j++){
//			if(i&(1<<j-1))k++;
//		}
//		
//	}
//}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+(a[i]-'0');
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(n<=10)solve1();
//	else solve2();
	return 0;
}
