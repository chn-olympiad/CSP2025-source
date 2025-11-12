#include<bits/stdc++.h>
#define ll long long
const ll N=1e6+10;
const ll MOD=998244353; 
using namespace std;
ll n;
ll a[N];
ll b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[i]+=a[i]+b[i-1];
	}
//	for(int i=3;i<=n;i++){
//		//寻找1~i之间和大于k-a[i]的子集
//		int l=0,r=i;
//		while(l+1!=r){
//			int mid=(l+r)/2;
//			if(b[mid]>k-a[i]){
//				r=mid;
//			}else{
//				l=mid;
//			}
//		}
//		//取r
//		int right=((i-r)*(i-r)+i-r)/2;
//		for(int j=r;j>=1;j--){
//			
//		}
//	}
	if(n==3){
		if(b[n]>2*a[n]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	n-=2;
	int ans=0;
	while(n>=1){
		ans+=n;
		n--;
	}
	cout<<ans;
	return 0;
}
