#include<cstdio>
#include<algorithm>
const int maxnm=105;
int a[maxnm];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
	}
	int t1=a[1];
	int s=1;
	std::sort(&a[1],&a[t+1]);
	for(int i=t,j=1;i>=1;i--,j++){
		if(t1==a[i]){
			s=j;
			break;
		}
	}
	int c=(s+m-1)/m;
	int r;
	if(c%2){
		r=s%m;
		if(r==0) r=m;
	}else{
		int t=s%m;
		if(t==0) t=m; 
		r=m-t+1;
	}
	printf("%d %d\n",c,r);
	return 0;
}
