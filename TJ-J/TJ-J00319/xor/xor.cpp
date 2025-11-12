#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],maxx=-1,minx=INT_MAX,ans,k;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minx=min(minx,a[i]);
	}
	if(maxx==1&&minx==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(maxx==1&&minx==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
			return 0;
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
