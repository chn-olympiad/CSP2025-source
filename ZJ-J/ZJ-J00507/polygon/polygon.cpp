#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,k;
ll a[5001];
ll cnt;
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]<=a[3]){
		cout<<0<<endl;
	}
	else{
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}