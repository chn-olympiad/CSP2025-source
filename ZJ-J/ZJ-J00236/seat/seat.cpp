#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],sum,x,y,k,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1],b=n*m;
	for(int i=1;i<=b;i++){
		for(int j=1;j<b;j++){
			if(a[j+1]>a[j]){
				int e=a[j];
				a[j]=a[j+1];
				a[j+1]=e;
			}
		}
	}
	for(int i=1;i<=b;i++){
		if(k==a[i]){
			sum=i;
			if(sum%n==0){
				x=sum/n;
				if(x%2==0) y=1;
				else if(x%2!=0) y=n;
			}else if(sum%n!=0){
				x=sum/n+1;
				if(x%2==0) y=n+1-sum%n;
				else if(x%2!=0) y=sum%n;
			}
			
		}
	}
	printf("%d %d",x,y);
	return 0;
}
