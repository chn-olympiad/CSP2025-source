#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,k;
	scanf("%d%d%d",&n,&m,&k);
	int rank=1;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&t);
		if(t>k) rank++;
	}
	int num=rank/n,rest=rank%n;
	int c;//ÁĞ
	int r;//ĞĞ 
	if(rest==0){
		c=num;
	}else{
		c=num+1;
	}
	if(c%2==1){
		if(rest==0) r=n;
		else{
			r=rest;
		}
	}else{
		if(rest==0) r=1;
		else{
			r=n-rest+1;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
