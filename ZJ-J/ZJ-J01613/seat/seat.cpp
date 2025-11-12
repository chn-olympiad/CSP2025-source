#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,cnt=0;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n*m;++i){
		int a;scanf("%d",&a);
		if(a>s)++cnt;
	}
	int x=cnt/n+1,y;
	if(x&1)y=cnt%n+1;
	else y=(n-cnt%n);
	printf("%d %d",x,y);
	return 0;
}
