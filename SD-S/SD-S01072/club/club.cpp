#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N],c[N];
int mx;
void dfs(int st,int sum,int cnt1,int cnt2,int cnt3){
	if(st==n+1){
		mx=max(mx,sum);
		return ;
	}
	if(cnt1<n/2)dfs(st+1,sum+a[st],cnt1+1,cnt2,cnt3);
	if(cnt2<n/2)dfs(st+1,sum+b[st],cnt1,cnt2+1,cnt3);
	if(cnt3<n/2)dfs(st+1,sum+c[st],cnt1,cnt2,cnt3+1);
	return ;
}
void solve(){
	cin>>n;
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		f1=f1&(!b[i]);
		f2=f2&(!c[i]);
	}
	mx=0;
	if(f1&&f2){
		sort(a+1,a+n+1);
		for(int i=n;i>=n/2+1;i--){
			mx+=a[i];
		}
		cout<<mx<<endl;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<mx<<endl;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

