#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[105],sr,xr,yr,cnt=0;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&s[i]);
	}
	sr=s[1];
	for(int i=1;i<=n*m;i++){
		if(s[i]>sr){
			cnt++;
		}
	}
	cnt+=1;
	if(cnt<=n){
		xr=1;
		yr=cnt;
	}else{
		if(cnt%n==0)
			xr=cnt/n;
		else
			xr=cnt/n+1;
		if(xr%2==1){
			
			yr=(cnt-1)%n+1;
		}else{
			yr=xr*n-cnt+1;
		}
		
	}
	printf("%lld %lld",xr,yr);
	return 0;
}