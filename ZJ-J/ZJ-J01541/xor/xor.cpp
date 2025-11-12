#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long unll;
using namespace std;
const int N=5e5+100;
ll n,m;
int a[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=0;
	int pos=0;
	for(int i=1;i<=n;i++){
		for(int j=pos+1;j<=i;j++){
			sum=0;
			for(int k=j;k<=i;k++){
				sum^=a[k];
				if(sum==m){
					++ans;
					pos=k;
					j=k;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
