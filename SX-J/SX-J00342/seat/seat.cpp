#include<bits/stdc++.h>;
using namespace std;

int n,m,x,y;
int a[101];
int h,l;

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	x=n*m;
	for(int i=1;i<=x;i++)
		scanf("%d",&a[i]);
	y=a[1];
	for(int i=1;i<x;i++){
		for(int j=i;j<=x;j++){
			if(a[j]>a[i]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=1;i<=x;i++){
		if(a[i]==y){
			if(i%n==0){
				l=i/n,h=n;
				break;
			}else{
				l=i/n+1;
				if(l%2==0)
					h=n-i%n+1;
				else
					h=i%n;
				break;
			}
		}
	}
	printf("%d %d\n",l,h);

	return 0;
}