#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
#define N 1000010
typedef long long ll;
ll n,m,k,f[10005],c[11],a[11][10005],ans=0;
struct node{
	ll x,u,v;
}w[N];
bool cmp(node l,node r){
	return l.x<r.x;
}
int find(int l){
	if(l!=f[l])f[l]=find(f[l]);
	return f[l];
}
void unionn(int l,int r){
	l=find(l);
	r=find(r);
	if(l==r)return;
	f[l]=r;
}
bool judge(int l,int r){
	l=find(l);
	r=find(r);
	if(l==r)return true;
	else return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[i].u>>w[i].v>>w[i].x;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(w+1,w+m+1,cmp);
	int cnt=1;
	for(int i=1;i<=n-1;i++){
		while(judge(w[cnt].u,w[cnt].v))cnt++;
		unionn(w[cnt].u,w[cnt].v);
		ans+=w[cnt].x;
	}
	cout<<ans<<endl;
	return 0;
}