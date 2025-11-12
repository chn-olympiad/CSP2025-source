#include<bits/stdc++.h>
using namespace std;
int a,x,m,n,cnt=1;
int cell(int y){
	if((y/n)*n==y) return y/n;
	else return (y/n)+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&x);
		if(x>a) cnt++;
	}
	int ce=cell(cnt);
	printf("%d ",ce);
	cnt=cnt%n;
	if(cnt==0){
		cnt=n;
	};
	if(ce&1){ printf("%d",cnt); }
	else{ printf("%d",(n-cnt+1)); }
	return 0;
}
