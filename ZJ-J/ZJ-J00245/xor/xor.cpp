#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int a[N],v[N];
int n,k;
bool check(int mid){
	int sum=a[1],ans=0;
//	for(int i=2;i<=n;i++){
//		if(sum==k){
//			sum=a[i++];
//			ans++;
//		}
//		else sum^=a[i];
//	}
//	return sum==k&&++ans==mid;
	memset(v,1,sizeof(v));
	int s=n/mid;
	for(int i=1;i<=s;i++){
//		cout<<"changdu:"<<i<<endl;
		for(int j=1;j<=n;j++){
			int sum=a[j];
//			cout<<j<<"^"<<j+i-1<<endl;
			for(int k=j+1;k<j+i;k++){
				if(v[i]){
					sum=-1;
					break;
				}
				sum^=a[k];
			}
//			cout<<sum<<endl;
			if(sum==k){
				for(int k=j;k<j+i;k++) v[i]=1;
				ans++;
				if(ans==mid) return 1;
			}
		}
//		cout<<ans<<endl;
	}
	return ans==mid;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		return cout<<ans,0;
	}
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
//			cout<<endl;
//			cout<<mid<<endl;
		}
		else r=mid-1;
	}
	cout<<++ans;
}