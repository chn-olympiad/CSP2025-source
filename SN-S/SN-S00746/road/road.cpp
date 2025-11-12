#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10001],siz[10001],c[11][10001],s;
struct node{
	long long x,y,z;
}a[1000001];
bool cmp(node x,node y){
	return x.z<y.z;
}
long long find(long long x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void unite(long long x,long long y){
	if(siz[x]<siz[y]) swap(x,y);
	f[y]=x;
	siz[x]+=siz[y];
}
int main(){
//	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>c[i][j];
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
		siz[i]=1;
	}
	sort(a+1,a+m+1,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			a[i].x=find(a[i].x);
			a[i].y=find(a[i].y);
			if(a[i].x==a[i].y) continue;
			unite(a[i].x,a[i].y);
			s+=a[i].z;
		}
		cout<<s;
		return 0;
	}
	cout<<0;
	return 0;
}

