#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[5005];
int sum[5005];
int mod=998244353;
int k[5005];
int vis[5005];
int js[5005];
int tot=0;
long long ans=0;
long long solve(int x,int c){
	if(x>tot){
		if(c==0){
			return 1;
		}
		else{
			return 0;
		}	
	}
	return ((js[x]-js[x+1]-c)%mod*solve(x+1,c)%mod+(js[x+c+1]-js[x+1])%mod*solve(x+1,c+1)%mod)%mod;
}
void print(){
	for(int i=1;i<=n-m;i++){
		ans=(ans%mod)*(i%mod)%mod; 
	}
	cout<<ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			sum[i+1]=sum[i]+1;
			vis[i+1]=1;
		}
		else{
			sum[i+1]=sum[i];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[i]=n;
		for(int j=1;j<=n;j++){
			if(a[i]==sum[j]){
				k[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(tot==m){
			break;
		}
		if(vis[i]==1){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(k[j]>=i){
					cnt++;
				}
			}
			js[++tot]=cnt;
		}
	}
	ans=solve(1,0)+solve(1,1);
	print();
	return 0;
}
