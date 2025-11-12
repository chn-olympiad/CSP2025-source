#include<bits/stdc++.h>
using namespace std;
long long a[1100],f[20][20];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long x=1,y=1,j=0;
	bool b=false;
	while(j<=n*m){
		j++;
		f[x][y]=a[j];
		if((x==n or x==1) and b){
			y++;
			b=false;
		}
		else if(y%2){
			x++;b=true;
		}
		else {
			x--;
			b=true;
		}
	}
	for(long long i=1;i<=n;i++){
		bool b=false;
		for(long long l=1;l<=m;l++){
			if(k==f[i][l]){
				printf("%lld %lld",l,i);
				b=true;break;
			}
		}
		if(b)
		  break;
	}
	return 0;
}
