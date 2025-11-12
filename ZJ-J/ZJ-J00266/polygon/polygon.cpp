#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],num[1<<20],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		int j=i;
		while(j){
			if(j&1) num[i]++;
			j>>=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<n);i++){
		if(num[i]<3) continue;
		int s=0,maxi=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				maxi=max(maxi,a[j]);
				s+=a[j];
			}
		}
		if(s>2*maxi) ans=1+ans%MOD;
	}
	cout<<ans;
	return 0;
}
