#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",a+i);
	}
	int sc=a[1];
	sort(a+1,a+1+n*m,greater<int>() );
	int x=1,y=1,op=1,id=1;
	while(a[id]!=sc){
		if(y%2==1){
			if(x==n){
				y++,op*=-1;
			}else{
				x+=op;
			}
		}else{
			if(x==1){
				y++,op*=-1;
			}else{
				x+=op;
			}
		}
		id++;
	}
	printf("%d %d",y,x);
	return 0;
}
