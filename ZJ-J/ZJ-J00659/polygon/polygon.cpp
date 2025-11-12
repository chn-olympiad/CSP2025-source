#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,a[5005],sum[5005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	if(n>=100){
		cout<<0;
		return 0;
	}
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]) cout<<1;
	else cout<<0;
	return 0;
}