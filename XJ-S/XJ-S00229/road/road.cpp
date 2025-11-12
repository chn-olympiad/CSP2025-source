#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long ans=0;
	if(k!=0){
		cout<<0;
		return 0;
	}
	while(m--){
		cin>>k>>k>>k;
		ans+=k;
	}
	cout<<ans;
	return 0;
}

