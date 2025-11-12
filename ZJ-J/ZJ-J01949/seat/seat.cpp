#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int a1,k=0;scanf("%d",&a1);
	for(int i=0;i<n*m-1;i++){
		int a;scanf("%d",&a);
		if(a>a1){
			k++;
		}
	}
	int x,y;
	x=k/n+1;
	if(x%2){
		y=k%n+1;
	}
	else{
		y=n-k%n;
	}
	printf("%d %d",x,y);
	return 0;
}
