#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],maxx,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) maxx++;
	} 
	cout<<maxx<<endl;
	while(maxx+1>2*n){
		x+=2;
		maxx-=2*n;
	}
	if(maxx+1>n) cout<<x+2<<' '<<2*n-maxx;
	else cout<<x+1<<' '<<maxx+1;
}