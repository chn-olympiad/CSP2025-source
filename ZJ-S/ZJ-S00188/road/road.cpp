#include<bits/stdc++.h>
using namespace std;
int T,a[1000][5],n,m,k,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		s+=z;
	}
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		s+=t;
	}
	cout<<s;
}
