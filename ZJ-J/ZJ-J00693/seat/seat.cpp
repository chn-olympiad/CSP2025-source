#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	double ret,a;
	scanf("%d%d%lf",&n,&m,&ret);
	for(int i=1,en=n*m;i<en;i++){
		scanf("%lf",&a);
		if(a>ret)
			cnt++;
	} 
	int r=cnt/n,c=11;
	cnt-=r*n;
	if(!cnt)
		c=((r%2)?(n):(1));
	else{
		r++;
		if(r%2)
			c=cnt;
		else
			c=n-cnt+1;
	}
	printf("%d %d",r,c);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
