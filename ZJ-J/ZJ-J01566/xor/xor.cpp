#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,k,a[maxn],ans,sum[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			else if(a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((sum[j]^sum[i-1])==k){
					ans++;
					i=j;
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
