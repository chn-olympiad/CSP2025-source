#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=55;
struct node{
	int x,y,z;
}a[N],b[N];
bool cp(node q,node w){
	return q.z>w.z;
}
bool cmp(node q,node w){
	return q.x-q.y>w.x-w.y;
}
int n,m,T,ans,f[M][M][M];
int mymax(int i,int j,int k,int l){
	int as=f[i][j][k];
	if(i>0) as=max(as,f[i-1][j][k]+a[l].x);
	if(j>0) as=max(as,f[i][j-1][k]+a[l].y);
	if(k>0) as=max(as,f[i][j][k-1]+a[l].z);
	return as;
}
void solve1(){
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	m=n/2;
	for(int i=m;i>=0;i--)
	for(int j=m;j>=0;j--)
	for(int k=m;k>=0;k--)
	f[i][j][k]=0;
	for(int l=1;l<=n;l++)
	for(int i=m;i>=0;i--)
	for(int j=m;j>=0;j--)
	for(int k=m;k>=0;k--){
	f[i][j][k]=mymax(i,j,k,l);
	}		
	cout<<f[m][m][m]<<"\n";
}
void solve2(){
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+n+1,cmp);
	ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=a[i].x,b[i].z=a[i].z-a[i].x,b[i].x=a[i].x,b[i].y=a[i].y;
	for(int i=n/2+1;i<=n;i++)
		ans+=a[i].y,b[i].z=a[i].z-a[i].y,b[i].x=a[i].x,b[i].y=a[i].y;
	sort(b+1,b+n+1,cp);
	for(int i=n/2+1;i<=n;i++){
		if(b[i].z>0) ans+=b[i].z;
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n;
	if(n<=100) solve1();
	else solve2();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
1
4
4 3 2
2 3 4
3 2 1
1 2 3
*/
