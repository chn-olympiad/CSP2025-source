#include<bits/stdc++.h>
using namespace std;
long long n,a[11111];
long long ans,mx,sum,dp=1;
void d(long long x){
	if(x>n)return;
	mx=max(mx,a[x]);
	for(int i=x+1;i<=n;i++){
		ans+=a[i];dp++;
		mx=max(mx,a[i]);
		int z=mx;
		int t=mx*2;
		if(ans>t&&dp>=3){
			sum++;
			sum%=998244353;
		}
		d(i);
		dp--;
		ans-=a[i];
		mx=z; 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		mx=0;
		ans=0;
		dp=1;
		ans+=a[i];
		mx=max(mx,a[i]);
		d(i);
	}
	cout<<sum;
} 
