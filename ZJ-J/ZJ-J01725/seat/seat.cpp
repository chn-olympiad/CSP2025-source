#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n,m,R,pos,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1],sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) pos=i;
	}
	c=ceil(pos*1.0/n);
	if(c%2) r=(pos%n==0?n:pos%n);
	else r=n-(pos%n==0?n:pos%n)+1;
	cout<<c<<' '<<r;
	return 0;
}
/*
By ZJ-J01725.
Luogu UID:1086453.
*/
