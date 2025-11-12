#include<bits/stdc++.h>
using namespace std;
bool flag=true;
int n,f[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	if(f[1]+f[2]>f[3] && f[1]+f[3]>f[2] && f[2]+f[3]>f[1]) cout<<1;
	else cout<<0;
	return 0;
}
