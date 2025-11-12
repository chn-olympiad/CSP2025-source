#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,pre[5010],a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		if(pre[i-1]>a[i]){
			ans++;
			ans%=mod;
			if(i>3){
				int l=1,r=1;
				while(r<=i-1 && l<=r){
					if(pre[i-1]-pre[r]+pre[l-1]>a[i]){
						ans+=(r-l+1)%mod;
						ans%=mod;
						r++;
					}else{
						l++;
					}
				}
			}
		}
	}
	cout<<ans%mod;
	return 0;
}
