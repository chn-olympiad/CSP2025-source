//SN-J00692
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans=0;
bool isright(int len,int maxx){
	if(len>(maxx*2)){
		return true;
	}else{
		return false;
	}
}
//void dfs(int num,int l,int maxn,int m){
//	if(isright(l,maxn) and m>=3){
//		ans++;
//	}
//	if(num==n+1){
//		return;
//	}
//	for(int i=0;i<=1;i++){
//		cout<<a[num]<<" ";
//		if(i==0){
//			cout<<0<<" ";
//			num++;
//			dfs(num,l,maxn,m);
//		}else{
//			cout<<1<<endl;
//			m++;
//			l+=a[num];
//			maxn=max(maxn,a[num]);
//			num++;
//			dfs(num,l,maxn,m);
//		}
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int sum=1,k=n;
		for(int j=1;j<=i;j++){
			sum=(sum*k)%mod;
			k--;
		}
		ans+=sum;
		ans%=mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans;
	return 0;
}
