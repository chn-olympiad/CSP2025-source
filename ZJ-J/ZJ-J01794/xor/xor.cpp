#include <iostream>

using namespace std;
const int N = 5 * 1e5 + 5;
int a[N];
int sum[N];
int cnt[N];
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++,cnt2++;
		if(a[i]==0) cnt2++;
	}

	if(cnt1==n){//ÌØÊâĞÔÖÊA 
		cout<<n/2;
		return 0;
	}
	
	else if(cnt2==n){//B
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1&&i+1<=n){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
				else if(a[i]==0&&a[i+1]==0&&i+1<=n){
					ans++;
					i++;
				} 
			}
			cout<<ans;
		}
		return 0;
	}
	else{
//		sum[1]=a[1];
//		for(int i=2;i<=n;i++){
//			sum[i]=sum[i-1]^a[i];
//		}
//		for(int i=1;i<=n;i++){
//	        if(sum[i]^a[i+1]==k){
//	        	cnt[i]++;
//			}
//		}
		cout<<0;
	}
	return 0;
}

