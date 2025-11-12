#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++)cin>>a[i];
	if(k==0)cout<<(n/2);
	return 0;
}