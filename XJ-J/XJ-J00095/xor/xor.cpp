#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+100;
ll n,k,a[N];
bool vis[N];
bool aaa(ll x){
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ll cnt=k&a[i];
		if(aaa(cnt) && vis[cnt]==false){
			ans++;
			vis[cnt]=true;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
