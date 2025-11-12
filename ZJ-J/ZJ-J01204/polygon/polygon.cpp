#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn=INT_MIN,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2) cout<<1;
		else cout<<0;
	}
	else if(maxn==1){
		for(int i=2;i<n;i++){
			for(int j=n-i;j>=1;j--){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=2;i<n;i++){
			for(int j=n-i;j>=1;j--){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
