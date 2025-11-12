#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int smo=0,ans=0,qwe,nw;
int a[500005];
int f[1005];
int dp[1005][1005];
bool ta=true,tb=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	smo=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)ta=false;
		else smo++;
		
		if(a[i]!=0 and a[i]!=1)tb=false;
	}
	if(ta==true){
		if(k==1){
			cout<<n;
		}
		else if(k==0){
			cout<<n/2;
		}
	}
	else if(tb==true){
		if(k==1){
			cout<<smo;
		}
		else if(k==0){
			ans=0;
			smo=0;
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					smo++;
				}
				else if(a[i]==0){
					ans++;
					if(smo!=0){
						ans+=smo/2;
						smo=0;
					}
				}
			}
			cout<<ans;
		}
	}
	else{
		for(int i=n;i>=1;--i){
			qwe=a[i];
			if(qwe==k)f[i]=i;
			for(int j=n-1;j>=1;--j){
				qwe=qwe^a[j];
				if(qwe==k){
					f[i]=j;
					break;
				}
			}
		}
		nw=0;
		for(int i=1;i<=n;++i){
			if(f[i]==0){
				for(int j=1;j<=i;++j){
					dp[i][j]=dp[i-1][j];
				}
				for(int j=i+1;j<=n;++j){
					dp[i][j]=dp[i][i];
				}
			}
			else{
				for(int j=1;j<=n;++j){
					if(j>=i){
						dp[i][j]=dp[i-1][f[i]-1]+1;
					}
					else{
						dp[i][j]=dp[i-1][j];
					}
				}
			}
		}
		cout<<dp[n][n];
	}
	return 0;
}

