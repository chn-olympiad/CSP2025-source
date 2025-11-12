#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			y=i;
			break;
		}
	}
	int u=y/(2*n),v=y%(2*n);
	if(v<=n) cout<<2*u+1<<' '<<v<<'\n';
	else cout<<2*u+2<<' '<<n-(v-n)+1<<'\n';
	return 0;
}

