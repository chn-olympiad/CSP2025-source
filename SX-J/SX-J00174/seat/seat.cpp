#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int q=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]){
				int w=a[i];
				a[i]=a[j];
				a[j]=w;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==q) q=i;
	}
	int c=q/n+(q%n!=0),r;
	if(c%2==0){
		r=n-(q%n)+1;
	}
	else{
		if(q%n==0){
			r=n;
		}
		else{
			r=q%n;
		}
	}
	printf("%d %d",c,r);
	return 0;
}