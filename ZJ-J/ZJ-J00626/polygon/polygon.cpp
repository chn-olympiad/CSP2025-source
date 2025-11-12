#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5000];
int ans;
int num[101010];
int shu;
int cnt=0;
void www(int x){
	if(cnt>a[x])ans++;
	ans%=mod;
	cnt+=a[x];
	for(int i=x+1;i<=n;i++){
		if(cnt>a[i])ans++;
		ans%=mod;
		www(i);
	}
	cnt-=a[x];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(num[a[i]]==0){
		num[a[i]]=1;
		shu++;
		}
	}
	if(shu==1&&n>30){
		for(int i=n-2;i>=1;i--){
			for(int j=1;j<=i;j++){
				ans+=(1+j)*j/2;
				ans%=mod;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		www(i);
	}
	ans/=2;
	cout<<(ans%mod);
	return 0;
}