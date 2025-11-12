#include<bits/stdc++.h>
using namespace std;
int n;
const int MOD=998244353;
int g[29];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n);
	if(n==3){
		if(g[1]+g[2]>g[3])cout<<1;
	}
	return 0;
} 
