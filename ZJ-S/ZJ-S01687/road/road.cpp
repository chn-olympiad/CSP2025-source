#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int a,b,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a>>b>>c,s+=c;
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++)cin>>a;
	}
	cout<<s<<"\n";
	return 0;
}
//¡ö¡õ
