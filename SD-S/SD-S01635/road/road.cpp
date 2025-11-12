#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=2*1e6+5;
long long n,m,k;
long long cn;
long long w,a[10005];
long long ans;
struct node{
	long long u,v;
	long long w;
}c[N];
bool cmp(node a,node b){
	return a.w <= b.w;
}
long long f[10005];
long long z(long long a){
	if(f[a]==a) return a;
	return f[a]=z(f[a]);
}
void change(long long a,long long b){
	long long x=z(a),y=z(b);
	f[y]=x;
	return;
} 
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	cn=m;
	for(int i=1;i<=m;i++)
		cin>>c[i].u>>c[i].v>>c[i].w;
	for(int i=1;i<=k;i++){
		cin>>w;
		long long ff=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]==0) ff=j; 
		} 
		ans+=w;
		for(int j=1;j<=n;j++){
			cn++;
			c[cn].u=ff,c[cn].v=j,c[cn].w=a[j];
		}
	}
	sort(c+1,c+1+cn,cmp);
	for(int i=1;i<=cn;i++){
		long long u=c[i].u,v=c[i].v;
		if(z(u)!=z(v)){
			change(u,v);
			ans+=c[i].w;
			n--;
		}
		if(n==1) break;
	}
	cout<<ans;
	return 0; 
} 
