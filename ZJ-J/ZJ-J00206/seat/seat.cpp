#include<bits/stdc++.h>
using namespace std;

inline int fastReadSeat(){
	int s=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9'){f=(f||c=='-');c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int xm,s[1005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=fastReadSeat();m=fastReadSeat();
	for(int i=1;i<=n*m;i++){
		s[i]=fastReadSeat();
	}
	xm=s[1];
	sort(s+1,s+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(s[i]==xm){
			printf("%d %d",y,x);
			return 0;
		}
		if(x==n&&y%2==1) x=n,y++;
		else if(x==1&&y%2==0) y++;
		else if(y%2==1)x++;
		else x--;
	}
	
	return 0;
}
