#include<bits/stdc++.h>
using namespace std;
int c[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		scanf("%d",&c[i]);
	}
	int q=c[1],x;
	sort(c+1+n*m,c+1);
	for(int i=1;i<=n*m;i++){
		if(q==c[i]){
			x=i;
			break;
		}
	}
	int z=x/m;
	x%=m;
	if(z%2==1){
		if(x>0){
			printf("%d %d",z+1,n-x);
		}else{
			printf("%d %d",z,n);
		}
	}else{
		if(x>0){
			printf("%d %d",z+1,x);
		}else{
			printf("%d %d",z,1);
		}
	}
	return 0;
}
