#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		cin>>a;
		cin>>a;
		ans+=a;
	}
	for(int i=1;i<=(n+1)*k;i++){
		int a;
		cin>>a;
	}
	cout<<ans;
	return 0;
}
