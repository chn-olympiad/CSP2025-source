#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
int a[1000005];
char c[1000005];
int jc[1000005];

int sum[100005];
inline int ksm(int a,int x){
	int res=1;
	while (x){
		if (x&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		x>>=1;
	}
	return res;
}
int ans;
int p[1000005];
int ct;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	jc[0]=1;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]!='1'){
			flag=0;
		}
		else{
			ct++;
		}
	}
	for (int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
		cin>>a[i];
		sum[a[i]]++;
	}
	
	if (ct<m){
		cout<<0;
		return 0;
	}
	if (m==n){
		if (sum[0]==0){
			cout<<jc[n];
		}
		else{
			cout<<0;
		}
		return 0;
	}
	
	for (int i=1;i<=n;i++){
		p[i]=i;
	}
	if (flag && n>12){
		if (n-sum[0]<m){
			cout<<0;
			return 0;
		}
		int res=1;
		int pre=0;
		for (int i=1;i<=n;i++){
			if (sum[i]==0) continue;
			res=(res*ksm(pre,sum[i]));
			pre=pre+ksm(i,min(sum[i],sum[0]));
			pre%=mod;
		}
		cout<<res;
		return 0;
	}
	do{
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (cnt>=a[p[i]]){
				cnt++;
				continue;
			}
			if (c[i]=='0'){
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m){
			ans++;
		}
		ans%=mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
	
	
	return 0;
}
