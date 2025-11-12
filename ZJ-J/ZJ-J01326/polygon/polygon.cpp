#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1100;
int n,a[N],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int s=0;s<(1<<n);s++){
		int sum=0,mx=0;
		for(int i=1;i<=n;i++){
			if(s>>(i-1)&1) {
				sum+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(sum>mx*2) ans++;
	}
	cout<<ans;
}
