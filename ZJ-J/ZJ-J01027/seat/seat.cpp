#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a1);
	for(int i=2;i<=n*m;i++){
		int ai;scanf("%d",&ai);
		if(ai>a1)cnt++;
	}
	int x=ceil(1.0*cnt/n),y=(cnt%n)?cnt%n:n;
	if(x%2==0)y=n-y+1;
	printf("%d %d",x,y);
	return 0;
}
