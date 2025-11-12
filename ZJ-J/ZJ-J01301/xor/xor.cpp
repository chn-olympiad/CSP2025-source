#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k,last,ans;
ll a[N],x[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=(x[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0&&k!=0) continue;
		for(int j=i;j<=n;j++){
			if(i<=last&&j>=last) break;
			if((x[j]^x[i-1])==k){
				if(i<last&&j<last){
					last=j;
				}
				if(i>last){
					last=j;
					ans++;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
