#include<bits/stdc++.h>
using namespace std;
int sum[100000];
int le[100000];
int n;
int Maxzl=0;
int ans;
bool cmp(int a,int b){
	return a<b;
}
int mod=998244353;
int maz;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>le[i];
	sort(le+1,le+n+1,cmp);
	sum[0]=1;
	maz=le[n]*2+1;
	for(int i=1;i<=n;i++){
		if(i<3){
			for(int j=Maxzl;j>=0;j--){
				if(sum[j]){
					sum[int(min(j+le[i],maz))]+=sum[j];
					Maxzl=max(Maxzl,min(j+le[i],maz));
				}
			}
		}else{
			for(int j=Maxzl;j>=0;j--){
				if(sum[j]){
					sum[int(min(j+le[i],maz))]+=sum[j];
					sum[int(min(j+le[i],maz))]%=mod;
					Maxzl=max(Maxzl,min(j+le[i],maz));
				}
			}
			for(int j=le[i]*2+1;j<=Maxzl;j++){
				ans+=sum[j];
				ans%=mod;
			}
			
		}
	}
	cout<<ans%mod;
	return 0;
}
