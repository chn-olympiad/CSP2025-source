#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,a[N],k,ans,dp[N],xo[N],p;
bool tp1=true,tp2=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) tp1=false;
		if(a[i]>1) tp2=false;
	}
	if(tp1){
		if(k==1){
			cout<<n;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else if(k==0){
			cout<<n/2;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	if(tp2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]+a[i+1]==2){
					ans++;
					i++;
				}
			}
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=i;j>0;j--){
			p=p^a[j];
			if(p==k){
				dp[i]=max(dp[i-1],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
