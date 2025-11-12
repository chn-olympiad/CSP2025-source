#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,s_0,s_1,a[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			s_0++;
		}else if(a[i]==1){
			s_1++;
		}
	}
	if(s_1==n&&k==0){
		cout<<n/2<<"\n";
	}else if(s_1+s_0==n){
		if(k==1){
			cout<<s_1<<"\n";
		}else if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					s_0++;
					i++;
				}
			}
			cout<<s_0<<"\n";
		}
	}else{
		int s=a[1];
		for(int i=2;i<=n;i++){
			if(s==k){
				ans++;
				s=a[i];
				continue;
			}
			s=s^a[i];
		}
		if(s==k){
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
