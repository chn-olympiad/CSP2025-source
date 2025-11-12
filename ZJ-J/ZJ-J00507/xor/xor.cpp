#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,k;
ll a[500001];
ll cnt;
ll ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==1){
			if(a[i]==1){
				cnt++;
			}
		}
		if(k==0){
			ans++;
			if(ans%2==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}