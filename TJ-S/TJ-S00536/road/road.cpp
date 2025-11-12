#include <bits/stdc++.h>
using namespace std;
int n,m,k,x;
int a,b,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		x+=c;
	}
	cout<<x;
	return 0;
} 
