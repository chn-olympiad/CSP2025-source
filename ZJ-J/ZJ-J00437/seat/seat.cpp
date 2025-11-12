#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,pos,x,y;
int num[110];
int r;
bool flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",&num[i]);
	r=num[1];
	sort(num+1,num+1+n*m,cmp);
	flag=true;
	for(int i=1;i<=n*m;++i){
		if(num[i]==r){
			pos=i;
			break;
		}
	}
	y=pos/n;
	x=pos%n;
	if(x!=0) printf("%d %d",y+1,((y+1)%2==1?x:n-x+1));
	else printf("%d %d",y,(y%2==0?1:n));
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/