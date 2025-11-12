#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005],b[500005];
long long dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	int t=1;
	for(int i=1;i<=n;i=t){
		if(a[i]==k){
			ans++;
			t++;
			continue;
		}
		for(int j=i;j<=n;j++){
			int t1=a[i];
			for(int k1=i+1;k1<=j;k1++){
				int t2=a[k1];
				t1=(t1^t2);
			}
				
			if(t1==k){
				t=j+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
