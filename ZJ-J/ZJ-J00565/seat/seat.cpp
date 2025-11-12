#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]),cnt+=(a[i]>a[1]);
	int x=1,y=1;
	bool is=0;
	while(cnt--){
		if(!is&&y==n){
			is=1,x++;
			continue;
		}
		if(is&&y==1){
			is=0,x++;
			continue;
		}
		if(is)y--;
		else y++;
	}
	printf("%d %d\n",x,y);
	return 0;
}
