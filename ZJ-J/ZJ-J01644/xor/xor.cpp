#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+25;
ll n,k,a[N],b[N],ans=0,maxn;
bool f;
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		b[i]=(b[i-1]^a[i]);
	}
	if(maxn<=1){
		if(k>1)cout<<0;
		else{
			if(k==0){
				bool pd=0;
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						ans++;
						pd=0;
					}else{
						if(pd==1){
							ans++;pd=0;
						}else{
							pd=1;
						}
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					if(a[i]==1)ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	ll r=n;
	while(r>=1){
		f=0;
		for(int i=r-1;i>=0;--i){
			if((b[r]^b[i])==k){
				ans++;f=1;r=i;
				break;
			}
		}
		if(f==0)r--;
	}
	cout<<ans;
	return 0;
}
