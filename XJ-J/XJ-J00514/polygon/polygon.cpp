#include <bits/stdc++.h>
using namespace std;
int n,ans,sum;
int a[5050],pre[5050];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	if(n==3){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		if(sum>maxx*2)cout<<1;
		else cout<<0;
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int sm=pre[j]-pre[i-1];
			if(sm>a[j]*2)ans++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			for(int l=i+1;l<=j-1;l++){
				for(int r=l;r<=j-1;r++){
					if(j-i-r+l<3)continue;
					int sm=pre[l-1]-pre[i-1]+pre[j]-pre[r];
					if(sm>a[j]*2)ans++;
				}
			}
		}
	}
	cout<<ans%998244353;
	
	return 0;
}
