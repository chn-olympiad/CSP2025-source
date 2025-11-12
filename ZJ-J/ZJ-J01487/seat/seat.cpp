#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,it;
int cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)
			it=i;
	}
	for(int i=1;i<=m*n;i+=n){
		if(i>it){
			printf("%d ",(i-n-1)/n+1);
			if(((i-n-1)/n)%2==0)
				printf("%d\n",it-i+n+1);
			else
				printf("%d\n",i-it);
		}
		else if(i+n>m*n){
			printf("%d ",(i-1)/n+1);
			if(((i-1)/n)%2==0)
				printf("%d\n",it-i+1);
			else
				printf("%d\n",i+n-it);
		}
	}
	return 0;
}
