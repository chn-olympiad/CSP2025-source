#include<bits/stdc++.h>
using namespace std;
int n,m,r,x,p,q,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			x=n*m+1-i;
			break;
		}
	}
	if(x%n==0){
		x=(x/n);
		if(x%2==0){
			printf("%d 1",x);
			return 0;
		}else{
			printf("%d %d",x,n);
			return 0;
		}
	}else{
		p=x%n;
		q=(x/n)+1;
		if(q%2!=0){
			printf("%d %d",q,p);
			return 0;
		}else{
			p=n+1-p;
			printf("%d %d",q,p);
			return 0;
		}
	}
	return 0;
}