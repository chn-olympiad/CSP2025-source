#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
bool cmp(const int &p,const int &k){
	return p>k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int v=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1,k=1;
	for(int i=1;i<=n*m;i++){
		x+=k;
		if(x==n+1)
			x--,k=-1,y++;
		if(x==0)
			x++,k=1,y++;
		if(a[i]==v)
			break;
	}printf("%d %d",y,x);
	return 0;
}
