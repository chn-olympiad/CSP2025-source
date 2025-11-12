#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],x,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;){
		x=a[i];
		if(x==k){
			cnt++;
			i++;
			continue;
		}
		for(ll j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				i=j+1;
				cnt++;
				break;
			}
		}
		i++;
	}
	cout<<cnt;
	return 0;
}
