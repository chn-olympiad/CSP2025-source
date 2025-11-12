#include<bits/stdc++.h>
using namespace std;
int a[5005],vis[5005],n;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int num=0,maxn=-100;
		for(int i=1;i<=n;i++){
			num+=a[i];
			maxn=max(a[i],maxn);
		}
		if(num>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			int maxn=-1,num=0;
			for(int e=k;e<=i+k-1;e++){
				maxn=max(a[e],maxn);
				num+=a[e];
			}
			if(num>maxn*2) {
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
