#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+10;
int n,k;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<a[i]<<" "<<b[i-1]<<"\n";
	}
	int ans=-1,l=1,r=2,sum=0;
	while(r<=n){
		if(ans==-1){
			ans=a[l];
			r=l;
		}
		if(ans==k){
			sum++;
			ans=-1;
			l=r+1;
			r=l;
		}
		else{
			ans^=a[r+1];
			r++;
		}
		if(a[r]==k&&r<=n){
			sum++;
			ans=-1;
			l=r+1;
			r=l;
		}
		else if(a[r]^a[r+1]==k&&r<n){
			sum++;
			ans=-1;
			l=r+2;
			r=l;
		}
//		cout<<l<<" "<<r<<" "<<sum<<" "<<ans<<"\n";
	}
	if(ans==k)sum++;
	cout<<sum;
	return 0;
}
