#include<bits/stdc++.h>
using namespace std;
long long int n,a[5100],tot=1,maxn; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(a[i],maxn);
	if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
	else cout<<0;
	return 0;
}
