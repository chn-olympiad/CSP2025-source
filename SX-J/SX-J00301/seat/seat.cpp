#include<bits/stdc++.h>
using namespace std;
int n,m;
struct aaa{
	int fen;
	int id;
	void in(int i){
		scanf("%d",&fen);
		id=i;
		return 0;
	}
}a[105],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		a[i].in(i);
	}
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			bool flag=0;
			if(a[i].fen<a[j].fen&&a[i].id<a[j].id){
				swap(a[i].id,a[j].id);
			}
			if(a[i].fen>a[j].fen&&a[i].id>a[j].id){
				swap(a[i].id,a[j].id);
			}
		}
	}
	R=a[1];
	int k=R.id/n,b=R.id%n;
	while(b==0){
		b=n;
		k-=1;
	}
	int c=0,r=0;
	if((k+1)%2==1){
		c=k+1;
		r=b;
	}else{
		c=k+1;
		r=n-b+1;
	}
	printf("%d %d",c,r);
	return 0;
}