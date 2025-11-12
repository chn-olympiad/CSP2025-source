#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[500010],t,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	t=0;
	for(i=1;i<=n;i++)
		if((t^a[i])==m)s++,t=0;
		else t=t^a[i];
	cout<<s;
	return 0;
}
