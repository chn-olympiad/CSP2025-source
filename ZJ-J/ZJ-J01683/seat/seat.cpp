#include<bits/stdc++.h>
using namespace std;
long long n,m,zzz,l;
struct node{
	int c,k;
}a[1100];
int cmp(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int zzz=n*m;
	for(int i=1;i<=zzz;i++) cin>>a[i].c,a[i].k=i;
	sort(a+1,a+zzz+1,cmp);
	for(int i=1;i<=zzz;i++) if(a[i].k==1) l=i;
	long long s=1;
	while(l>n){
		l-=n;
		s++;
	}
	if(s%2==1) cout<<s<<' '<<l;
	else cout<<s<<' '<<n-l+1;
	return 0;
}
