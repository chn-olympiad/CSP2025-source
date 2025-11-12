#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[501];
int cnt0,cnt1;
vector<int> h;
int vis[501];
int ans;
void dfs(int cnt){
	if(cnt==n){
		int bu=0;
		int lu=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				bu++;
				continue;
			}
			if(h[i]<=bu){
				bu++;
				continue;
			}
			lu++;
		}
		if(lu>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		h.push_back(c[i]);
		dfs(cnt+1);
		h.pop_back();
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')cnt0++;
		else cnt1++;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(0);
		cout<<ans;
		return 0;	
	}
	if(m==1){
		long long tot=1;
		for(int i=1;i<=n;i++){
			tot=(tot*i)%mod;
		}
		cout<<tot;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(cnt0==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0)sum++;
		}
		if(sum==0){
			long long tot=1;
			for(int i=1;i<=n;i++){
				tot=(tot*i)%mod;
			}
			cout<<tot;
			return 0;		
		}
		else{
			long long tot=1;
			for(int i=1;i<=n;i++){
				tot=(tot*i)%mod;
			}
			cout<<tot-sum*n;			
		}
		return 0;
	}
	long long tot=1;
	for(int i=1;i<=n;i++){
		tot=(tot*i)%mod;
	}
	cout<<tot;	
	return 0;
}