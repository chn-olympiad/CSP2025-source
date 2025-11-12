#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,a1,l=1,h;//co l,h
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	a1=a[1];
	sort(a+1,a+m*n+1);
	for(x=1;x<=m*n;x++) if(a[x]==a1) break;
	x=n*m-x+1;
	while(x-n*2>0){
		x-=n*2;
		l+=2;
	}
	if(x<=n) cout<<l<<" "<<x;
	else cout<<l+1<<" "<<n*2-x+1;
	return 0;
}
/*
2 2
98 99 100 97
*/
