#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt,ans;
int main(){
	freopen("polygon,in","r",stdin);
	freopen("polygon,out","w",stdout);
	cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];
		int sum=0; 
for(int i=1;i<=n-2;i++){
	for(int j=i+1;j<=n-1;j++){
		for(int k=i+2;k<=n;k++){
			sum=0;
			sum+=a[i]+a[j]+a[k];
			if(sum>2*a[k])  cnt++;
		}
	}
}
	ans=(ans+cnt)%998244353;
	cout<<ans;
	return 0;
}
