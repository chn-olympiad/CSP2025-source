#include<bits/stdc++.h>
using namespace std;
int n,k;
long long minn=INT_MAX,maxx=INT_MIN;
long long a[500005];
long long vis[500005];
long long xorr(long long x,long long y){
	long long cntt=1,xumm=0;
	while(x || y){
		if(x%2!=y%2) xumm+=cntt;
		cntt*=2;
		x/=2;
		y/=2;
	}
	return xumm;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	} 
	if(minn==maxx){
		if(minn==k){
			cout<<n;
			return 0;
		}
		if(minn==0){
			cout<<n/2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(minn==0 && maxx==1){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans;
			return 0; 
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					vis[i]=1;
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(a[i]==a[i-1] && a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
		cout<<0;
		return 0;
	}
	int sum=a[1],ans=0;
	for(int i=2;i<=n;i++){
		if(sum==k){
			ans++;
			sum=a[i];
		}
		else sum=xorr(a[i],sum);
	}
	if(sum==k) ans++;
	cout<<ans<<"\n";
	return 0;
}
//#Shang4Shan3Ruo6Shui4
