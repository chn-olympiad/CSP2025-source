#include<bits/stdc++.h>
using namespace std;
int n,m,t,g,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n*m;i++)scanf("%d",&g),s+=(g>t);
	if(((s+m-1)/m)%2==1)printf("%d %d",(s+m-1)/m,(s-1)%m+1);
	else printf("%d %d",(s+m-1)/m,m-(s-1)%m);
	return 0;
}
