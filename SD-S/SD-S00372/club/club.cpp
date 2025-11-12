#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5; 
int T;
int n;
int q[10];
struct Node{
	int x;
	int y;
	int o;
}d[N],d2[N];
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
bool cmp(Node x,Node y){ return x.x>y.x; }
void solve(){
	memset(d,0,sizeof d);
	memset(d2,0,sizeof d2);
	memset(q,0,sizeof q);
	n=read();
	int p=n/2;
	ll ans=0;
	int x,y,z;
	for(int i=1;i<=n;i++){
		x=read(),y=read(),z=read();
		if(max(max(x,y),z)==x) d[i].x=x,d[i].y=max(z,y),d[i].o=1;
		else if(max(max(x,y),z)==y) d[i].x=y,d[i].y=max(x,z),d[i].o=2;
		else if(max(max(x,y),z)==z) d[i].x=z,d[i].y=max(x,y),d[i].o=3;
		d2[i].x=d[i].x-d[i].y,d2[i].y=0,d2[i].o=i;
	}
	stable_sort(d2+1,d2+n+1,cmp);
	for(int i=1;i<=n;i++){
		int l=d2[i].o;
		if(q[d[l].o]<p) ans=(ll)(ans+d[l].x),q[d[l].o]++;
		else ans=(ll)(ans+d[l].y);
	}
	cout<<ans<<"\n"; 
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}

