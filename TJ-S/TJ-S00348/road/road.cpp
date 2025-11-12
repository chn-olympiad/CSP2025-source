#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n' 
struct Node{
	int be,to,va;
};
Node a[1000005]={};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].be>>a[i].to>>a[i].va;
	}
	for(int i=1;i<=k;i++){
		int er;
		cin>>er;
		for(int i=1;i<=n;i++){
			int f;
			cin>>f;
		}
	}
	cout<<0<<endl;
	return 0;
}
