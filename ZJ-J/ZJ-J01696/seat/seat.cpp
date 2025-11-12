#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(x>=a)++cnt;
	}
	int i=cnt/(2*n)*2;
	cnt=cnt%(2*n);
	if(cnt<n)printf("%d %d",i+1,cnt+1);
	else printf("%d %d",i+2,n*2-cnt);
}
