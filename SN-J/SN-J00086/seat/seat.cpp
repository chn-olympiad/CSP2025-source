#include <bits/stdc++.h>
using namespace std;
int a[100],n,m,f,c,r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&f);
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
	}
	int an;
	for(int i=0;i<n*m-1;i++){
		for(int j=1;j<n*m-1;j++){
			if(a[j-1]<a[j]){
				an=a[j-1];
				a[j-1]=a[j];
				a[j]=an;
			}
		}
	}
	if(f>a[0]){
		printf("1 1");
		return 0;
	}else if(f<a[m*n-2]){
		printf("%d %d",m,n);
		return 0;		
	}else{
		int an=0;
		while(f>a[an]||f<a[an+1]){
			an++;
		}
		an+=2;
		if((an/n)%2==1){
			if(an%n==0){
				c=an/n;
				r=n;
			}else{
				c=an/n+1;
				r=n-an%n+1;
			}
		}else{
			if(an%n==0){
				c=an/n;
				r=0;
			}else{
				c=an/n+1;
				r=an%n;
			}
		}
	}
	printf("%d %d",c,r);
	return 0;
}
