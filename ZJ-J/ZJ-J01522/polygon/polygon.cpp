#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,m,a[N];

signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	else if(n==3){
		if((a[1]+a[2]+a[3])>2*a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		int sum=0,ans=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum>2*a[n]) ans++;
		for(int i=1;i<=3;i++)
			if((sum-a[i])>2*a[n]) ans++;
		if((sum-a[4])>2*a[n-1]) ans++;
		cout<<ans;
	}
	else if(n==5){
		int sum=0,ans=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum>2*a[n]) ans++;
		for(int i=1;i<=4;i++)
			if((sum-a[i])>2*a[n]) ans++;
		if((sum-a[5])>2*a[n-1]) ans++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==4&&j==5)
					if((sum-a[5]-a[4])>2*a[3]) ans++;
				else if(j==5)
					if(sum-a[i]-a[j]>2*a[4]) ans++;
				else if(sum-a[i]-a[j]>2*a[5]) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}