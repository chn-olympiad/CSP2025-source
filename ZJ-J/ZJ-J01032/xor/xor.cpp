#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[510000],k,ans,t,x[510000],y[510000],u[510000],ma,mi=10;
void dfs(ll p,ll c) {
	if(p==t+1) {
		ans=max(ans,c);
		return ;
	}
	dfs(p+1,c);
	for(int i=x[p]; i<=y[p]; i++) {
		if(u[i]==1) {
			dfs(p+1,c);
			return ;
		}
	}
	for(int i=x[p]; i<=y[p]; i++) {
		u[i]=1;
	}
	dfs(p+1,c+1);
	for(int i=x[p]; i<=y[p]; i++) {
		u[i]=0;
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(ma==1&&mi==1){
		cout<<n/2;
		return 0;
	}
	else if(ma==1&&mi==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
				else if(a[i]==0){
					ans++;
				}
			}
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==0&&a[i+1]==0){
					ans++;
					i++;
				}
				else if(a[i]==1){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=15) {
		for(int i=1; i<=n; i++) {
			int p=a[i];
			if(p!=k) {
				for(int j=i+1; j<=n; j++) {
					p=p^a[j];
					if(p==k) {
						t++;
						x[t]=i;
						y[t]=j;
					}
				}
			} else {
				t++;
				x[t]=i;
				y[t]=i;
			}
		}
		dfs(1,0);
	} 
	else {
	for(int i=1; i<=n; i++) {
			int p=a[i];
			int j;
			if(a[i]!=k) {
				for(j=i+1; j<=n; j++) {
					p=p^a[j];
					if(p==k) {
						ans++;
						break;
					}
				}
				i=j;
			} 
			else {
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
