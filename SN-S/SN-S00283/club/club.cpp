#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int a,b,c;
}h[1000005];
int cnt(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>h[i].a>>h[i].b>>h[i].c;
		}
		sort(h+1,h+n+1,cnt);
		for(int i=1;i<=n/2;i++){
			ans+=h[i].a;
		}
		cout<<ans;
	}
	
	
	return 0;
}
