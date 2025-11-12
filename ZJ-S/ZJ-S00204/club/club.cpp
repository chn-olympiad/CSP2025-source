#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	char c=getchar();x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
const int N=1e5+5;
int n,a[N],b[N],c[N],d[N],x,y,z,s;
inline int Q(int i){
	int u,v;u=v=0;
	if(a[i]>b[i])u=a[i],v=b[i];
	else u=b[i],v=a[i];
	if(c[i]>u)v=u,u=c[i];
	else if(c[i]>v)v=c[i];
	return u-v;
}
void deal(int op,int m){
	int t=0;
	for (int i=1;i<=n;i++){
		if(d[i]==op)d[++t]=Q(i);
	}
	sort(d+1,d+m+1);
	for (int i=1;i<=m-n/2;i++)s-=d[i];
}
void work(){
	read(n);x=y=z=s=0;
	for (int i=1,u;i<=n;i++){
		read(a[i]),read(b[i]),read(c[i]);
		u=max(a[i],max(b[i],c[i]));s+=u;
		if(u==a[i])d[i]=1,x++;
		else if(u==b[i])d[i]=2,y++;
		else d[i]=3,z++;
	}
	if(x>n/2)deal(1,x);
	if(y>n/2)deal(2,y);
	if(z>n/2)deal(3,z);
	printf("%d\n",s);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;read(t);
	while(t--)work();
}
