#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		ll res=a[i];
		if(a[i]==m){
			ans++;
			last=i;
			continue;
		}
		for(int j=i-1;j>last;j--){
			res^=a[j];
			if(res==m){
				ans++;
				last=i;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}  