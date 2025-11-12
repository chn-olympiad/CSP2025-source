#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n;
struct p{
	int x,xi;
	int y,yi;
}a[N];
bool cmp(p n1, p n2){return n1.x-n1.y>n2.x-n2.y;}
int vis[140];
int m;
void sol(){
	memset(vis,0,sizeof(vis));
	cin >>n;
	m=n/2;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin >>x>>y>>z;
		if(x>=y&&x>=z)      a[i].x=x,a[i].xi=1;
		else if(x>=z||x>=y) a[i].y=x,a[i].yi=1;
		if(y>=x&&y>=z)      a[i].x=y,a[i].xi=2;
		else if(y>=z||y>=x) a[i].y=y,a[i].yi=2;
		if(z>=y&&z>=x)      a[i].x=z,a[i].xi=3;
		else if(z>=x||z>=y) a[i].y=z,a[i].yi=3;
	}
	long long ans=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(vis[a[i].xi]<m) ans+=a[i].x,vis[a[i].xi]++;
		else  ans+=a[i].y,vis[a[i].yi]++;
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int cff;
	cin >>cff;
	while(cff--)sol();
	return 0;
}

