#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t) r=i;
	}
	int j,l;
	if(r%n==0) j=r/n;
	else j=r/n+1;
	if(j&1) l=r-(j-1)*n;
	else l=n-(r-(j-1)*n)+1;
	cout<<j<<" "<<l<<"\n";
	return 0;
}
