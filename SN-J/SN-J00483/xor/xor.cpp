#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans;
bool f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=true;
	}
	if(k==0){
		if(f){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(a[i+1]==1) i++,ans++;
					else if(a[i+2]==1) i+=2,ans++;
					else i+=2,ans+=2;
				}
				else ans++;
			}
		}
		else ans=n/2;
	}
	else if(k==1){
		if(f){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		else ans=n;
	}
	cout<<ans;
	return 0;
}
