#include <bits/stdc++.h>
using namespace std;
int n,maxn=INT_MIN,sum;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxn)cout<<1;
	else cout<<0;
	return 0;
}
