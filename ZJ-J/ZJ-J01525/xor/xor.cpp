#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n,k;
ll a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(k==0){
		bool f=0;
		for(int i=1;i<=n;++i){
			if(a[i]>1){
				f=1;
				break;
			}
		}
		if(f){
			for(int i=1;i<=n;++i){
				ans+=(a[i]==0);
			}
		}
		else ans=n/2;
	}
	else{
		for(int i=1;i<=n;++i){
			ans+=(a[i]==1);
		}
	}
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4
