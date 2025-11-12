#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,ma,he;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		scanf("%d",&a);
		ma=max(ma,a);
		he+=a;
	}
	if(n==3){
		if(he>ma*2) cout<<1;
		else cout<<0;
	}
	else{
		for(int j=1;j<=n-3;j++){
			for(int i=j+1;i<n;i++){
				ans+=(n-i);
				ans%=998244353;
			}
		}
		cout<<ans+1;
	}
	return 0;
}
