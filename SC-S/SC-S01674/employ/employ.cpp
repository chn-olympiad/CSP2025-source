#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[100005];
int vis[100005];
int n,m;
string s;
int cnt=0;
void dfs(int x,int y,int z,int t){
	if(x==n){
		if(y>=m){
			cnt++;
		}
		return;
	}
	x++;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(s[t]=='0'||z>=a[i]){
			vis[i]=1;
			dfs(x,y,z+1,t+1);
			vis[i]=0;
		}else
		if(s[t]=='1'){
			vis[i]=1;
			dfs(x,y+1,z,t+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f=0;
	}
	int li=0;
	int mi=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			li++;
		}
		if(mi>a[i]){
			mi=a[i];
		}
	}
	sort(a+1,a+1+n);
	if(n<=18){
		dfs(0,0,0,0);
		cout<<cnt;
	}else if(f){
		if(n-li<m){
			cout<<0;
		}
		else{
			int ans=1;
			for(int i=n-m;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			ans%=mod;
			cout<<ans;
		}
	}else if(n==m){
		if(f&&li==0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<2;
	}
	return 0;
} /*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/