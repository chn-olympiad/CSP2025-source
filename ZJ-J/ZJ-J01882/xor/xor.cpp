#include<bits/stdc++.h>
using namespace std;
int cnt[3000010],a[500010];
int sum[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	int ans=0,last=0;
	for(int i=1;i<=n;i++){
		int x=sum[i]^last;
		if(x==k){
			ans++;
			last=sum[i];
		}else{
			if(cnt[(x^k)]==ans+1){
				ans++;
				last=sum[i];
			}else{
				cnt[x]=ans+1;
			}
		}		
	}
	cout<<ans;
	return 0;
} 