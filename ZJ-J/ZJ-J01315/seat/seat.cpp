#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[(i-1)*m+j]);
		}
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			int c;
			if(i%n==0){
				printf("%d ",i/n);
				c=i/n;
			}else{
				printf("%d ",i/n+1);
				c=i/n+1;
			}
			if(c%2==1){
				if(i%n==0){
					printf("%d",n);
				}else{
					printf("%d",i%n);
				}
				break;
			}else{
				if(i%n==0){
					printf("1");
				}else{
					printf("%d",n-i%n+1);
				}
				break;
			}
		}
	}
	return 0;
}
