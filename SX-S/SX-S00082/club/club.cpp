#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			ans+=max(x,max(z,y));
		}
		cout<<ans<<endl;
	}
	return 0;
}
