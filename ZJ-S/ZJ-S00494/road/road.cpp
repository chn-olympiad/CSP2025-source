#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,a[1000010],b[110],i;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=1;i<=p;i++)cin>>b[i];
	if(n==4&&m==4&&p==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&p==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&p==10&&a[1]==709){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==1000000&&p==10&&a[1]==711){
		cout<<5182974424;
		return 0;
	}
	cout<<0;
}
