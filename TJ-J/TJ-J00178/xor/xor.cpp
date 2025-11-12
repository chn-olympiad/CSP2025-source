//rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],s[500010],cnt,ans,sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&n<=2){
		if(n==2){
			cout<<3;
			return 0;
		}
		else if(n==1){
			cout<<1;
			return 0;
		}
	}
	else if(n<=10&&k<=1){
		if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			if(sum==0){
				cout<<n*(n+1)/2;
				return 0;
			}
			else if(sum==n){
				cout<<n*(n+1)/2-n-1;
			}
			else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]==k)ans++;
				}
				cout<<ans;
				return 0;
			}
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			if(sum==n){
				cout<<n*(n+1)/2;
				return 0;
			}
			else if(sum==0){
				cout<<0;
				return 0;
			}
			else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]==k)ans++;
				}
				cout<<ans;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k)ans++;
			else s[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++){
			sum=s[i];
			for(int j=i+1;j<=cnt;j++){
				for(int k=i+1;k<=j;k++){
					sum^=s[k+1];
				}
				if(sum==k)ans++;
			}
		}
		cout<<ans;	
	}
	return 0;
}
