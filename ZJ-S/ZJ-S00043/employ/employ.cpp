#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+5,mod=998244353;
int a[N],c[N],pl[N],n,m,ans=0,sx[N],t[N],qz[N];
bool vis[N];
void dfs(int x){
	if(x==n+1){
		int sum=0,ff=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ff++;
			}
			else if(ff>=c[pl[i]]){
				ff++;
			}
			else{
				sum++;
			}
		}
	//	cout<<sum<<" "<<ff<<"**\n";
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			pl[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	bool fA=1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[i+1]=1;
		}
		else{
			a[i+1]=0;
			fA=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		t[c[i]]++;
	}
	if(fA){
	//	cout<<"^^\n";
		int k=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				k++;
			}
		}
		if(n-k<m){
			cout<<0;
			return 0;
		}
		else{
			int jc=1;
			for(int i=1;i<=n;i++){
				jc=jc*i;
				jc%=mod;
			}
			cout<<jc;
		}
		return 0;
	}
	else if(m==n){
		sx[0]=1;
		int sum=1;
		bool fl=1;
		for(int i=1;i<=n;i++){
			sx[i]=sx[i-1]*i%mod;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				fl=0;
				break;
			}
			if(c[i]==0){
				fl=0;
				break;
			}
		}
		if(fl){
			cout<<sx[n];
		}
		else{
			cout<<0;
		}
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5
1111111111
6 0 4 2 1 2 5 4 3 3
*/
