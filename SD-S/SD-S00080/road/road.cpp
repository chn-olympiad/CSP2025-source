#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100001],xg;
long long sum;
struct jj{
	int x,y,w;
}a[1100001];
bool cmp(jj w,jj v){
	return w.w<v.w;}
int fi(int x){
	if(f[f[x]]!=x)
		f[x]=fi(f[x]);
	return f[x];}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int xx=fi(a[i].x),yy=fi(a[i].y);
		if(xx!=yy){
			sum+=a[i].w;
			f[xx]=f[yy];}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
