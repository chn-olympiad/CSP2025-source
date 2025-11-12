#include <bits/stdc++.h>
#define int long long
using namespace std;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=3e5+5;
int T;
int n;
bool Y[N];
int f[2][105][105];
struct node{
	int a,b,c;
}l[N],c[N];
bool cmp(node a,node b){
	if(a.a!=b.a) 
		return a.a>b.a;
	int mx1=0,mx2=0;
	if(l[a.b].a!=a.a) mx1=l[a.b].a;
	if(l[a.b].b!=a.a) mx1=l[a.b].b;
	if(l[a.b].c!=a.a) mx1=l[a.b].c;
	if(l[b.b].a!=b.a) mx2=l[b.b].a;
	if(l[b.b].b!=b.a) mx2=l[b.b].b;
	if(l[b.b].c!=b.a) mx2=l[b.b].c;
	return mx1>mx2;
}
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].b>>l[i].c;
	}
	if(n<=200){
		memset(f,-0x3f,sizeof f);
		f[0][0][0]=0;
		for(int i=1;i<=n;i++){//200
			memset(f[i&1],-0x3f,sizeof f[i&1]);
			for(int a=0;a<=min(i,n/2);a++){//100
				for(int b=0;b<=min(i-a,n/2);b++){//100
					if(i-a-b > n/2) continue;
					if(a) f[i&1][a][b]=max(f[i&1][a][b],f[(i+1)&1][a-1][b]+l[i].a);
					if(b) f[i&1][a][b]=max(f[i&1][a][b],f[(i+1)&1][a][b-1]+l[i].b);
					if(n-a-b) f[i&1][a][b]=max(f[i&1][a][b],f[(i+1)&1][a][b]+l[i].c);
				}
			}
		}
		int ans=0;
		for(int a=1;a<=n/2;a++)
			for(int b=1;b<=min(n-a,n/2);b++)
				if(n-a-b <= n/2)
					ans=max(ans,f[n&1][a][b]);
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		c[i*3-2]={l[i].a,i};
		c[i*3-1]={l[i].b,i};
		c[i*3]={l[i].c,i};
	}
	int ans=0;
	memset(Y,0,sizeof Y);
	sort(c+1,c+3*n+1,cmp);
	for(int i=1;i<=3*n;i++){
		node x=c[i];
		if(Y[x.b]) continue;
		Y[x.b]=1;
		ans+=x.a;
	}
	cout<<ans<<'\n';
}
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T --> 0) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/