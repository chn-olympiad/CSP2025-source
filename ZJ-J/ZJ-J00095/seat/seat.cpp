#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=len;i++){
		if(a[i]>a[1]) ans++;
	}
	int x=(ans-1)/n+1,y,z=(ans-1)%n+1;
	if(x%2==0){
		y=n+1-z;
	}else{
		y=z;
	}
	printf("%d %d",x,y);
	return 0;
}
