#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[10010],b[10010],cnt=0;
bool vis[10010];
int n,m=3;
void stick(int t){
	if(t>m){
		long long int sum=0;
		int ma=INT_MIN;
		for(int i=1;i<=m;i++){
			sum+=b[i];
			ma=max(ma,b[i]);
		}
		if(sum>ma*2){
			cnt++;
		}
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!vis[i]&&b[t-1]<=a[i]){
			b[t]=a[i];
			vis[i]=1;
			stick(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
		}
	}
	while(m<=n){
		if(m==n+1) break;
		stick(1);
		m++;
	}
	cout<<cnt%mod;
	return 0;
}