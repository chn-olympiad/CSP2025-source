#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,x,i,h,l,a[200];
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;a[1]=x;
	for(i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++) if(a[i]==x) break;
	if(i%n==0) l=i/n;
	else l=i/n+1;
	cout<<l<<" ";
	if(i%n==0)
		if(l%2==1) cout<<n;
		else cout<<1;
	else
		if(l%2==1) cout<<i%n;
		else cout<<(n+1)-i%n;
}
