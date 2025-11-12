#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int vis[1000];
long long mod=998244353;
long long anss=0;
void dfs(int x,int z,int l){
	if(x==n && l>=m){
		//cout<<l<<"\n";
		anss++;
		anss%=mod;
		return ;
	}
	//cout<<a[x];
	for(int i=z+1;i<=n;i++){
		if(vis[i]>0 && a[x]=='1'){
			for(int j=1;j<=vis[i];j++){
				vis[i]--;
				//cout<<i<<" "<<x<<" "<<z<<" "<<l<<" 1\n";
				dfs(x+1,z,l+1);
				vis[i]++;
			}
		}
		else if(vis[i]>0 && a[x]=='0'){
			for(int j=1;j<=vis[i];j++){
				vis[i]--;
				//cout<<i<<" "<<x<<" "<<z<<" "<<l<<" 0\n";
				dfs(x+1,z+1,l);
				vis[i]++;
			}
		} 
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vis[x]++;
	}
	int zero=0;
	if(vis[0]==n){
		cout<<0;
		return 0;
	}
	for(int i=0;i<a.size();i++) if(a[i]=='0') zero++;
	if(n==m){
		if(zero==0)cout<<1;
		else cout<<0;
		return 0;
	}
	if(zero==0){
		long long sum=0;
		for(int i=1;i<=n;i++) if(vis[i]>0) sum+=vis[i];
		long long ans=1;
		for(int i=n;i>=1;i++){
			ans*=sum;
			sum--;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1){
		int maxx=0,sum=0;
		for(int i=1;i<=n;i++)
			if(vis[i]>0){
				sum+=vis[i];
				maxx=max(maxx,i);
			} 
		if(maxx>zero){
			long long ans=1;
			for(int i=n;i>=1;i++){
				ans*=sum;
				sum--;
				ans%=mod;
			}
		}
		else{
			int ans=1;
			sum-=1;
			int cntt=0;
			for(int i=0;i<a.size();i++){
				ans*=sum;
				if(a[i]=='0') cntt++;
				if(cntt==maxx){
					cout<<ans;
					return 0;
				}
			}
		}
	}
	dfs(0,0,0);
	cout<<anss;
	return 0;
}
//Ren5Jie4Di4Ling5%
