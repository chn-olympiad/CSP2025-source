#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,k,a[N],t[N],ind=1,ans=0;
bool flaga=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flaga=0;
		t[i]=t[i-1]^a[i];
	}
	if(flaga){
		cout<<n/2<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=ind;j<=i;j++){
			if((t[j-1]^t[i])==k){
				//cout<<(t[j-1]^t[i])<<' '<<i<<' '<<j<<'\n';
				ind=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
